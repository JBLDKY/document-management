#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
#include <QSplitter>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QMimeData>
#include <QDebug>
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DatabaseManager.h"
#include <QSqlTableModel>
#include <QTableView>


const QString MainWindow::DEFAULT_PATH_LOCAL = "/home/jord/";
const QString MainWindow::DEFAULT_PATH_VAULT = "/home/jord/projects/dms/pdms/vault";
const QString MainWindow::DEFAULT_TABLE = "files";

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), dbManager() {
        ui->setupUi(this);
        setAcceptDrops(true);

        // FS
        QString target_dir = "/home/jord/projects/dms/pdms/vault";
        this->model = new QFileSystemModel(this);
        this->model->setRootPath(target_dir);

        // TreeView
        ui->treeView->setModel(this->model);
        ui->treeView->setRootIndex(this->model->index(QDir::currentPath()));
        selectCallback();

        // DB IMPL
        this->dbModel = new QSqlTableModel(this);
        dbModel->setTable("files");
        dbModel->select();
        ui->databaseTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->databaseTableView->setModel(dbModel);


        // dbManager.dropTable("files");
        // dbManager.dropTable("file_metadata");
        // dbManager.dropTable("file_access");
        // dbManager.dropTable("file_tags");
        // dbManager.dropTable("file_tag_mapping");
    };

void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasUrls()) {
        e->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *e)
{
    foreach (const QUrl &url, e->mimeData()->urls()) {
        QString fileName = url.toLocalFile();
        qDebug() << "Dropped file:" << fileName;

        MainWindow::handleDroppedFile(fileName);
    }
}

void MainWindow::handleDroppedFile(QString filePath)
{
        this->activeFile = filePath;

        QFileInfo file(filePath);
        ui->fileNameLineEdit->setText(file.fileName());
        ui->fileLastModifiedTimeEdit->setDateTime(file.lastModified());
        ui->fileCreatedTimeEdit->setDateTime(file.birthTime());
        ui->fileOwnerLineEdit->setText(file.owner());
        ui->fileSizeLineEdit->setText(QString::number(file.size()));
        ui->fileVersionLineEdit->setText("0");
}

void MainWindow::selectCallback()
{
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, [this](const QItemSelection &selected, const QItemSelection &_deselected){
        QModelIndexList indexes = selected.indexes();
        if (!indexes.isEmpty()) {
            QModelIndex index = indexes.first();
            if (index.isValid()) {
                qDebug() << "Selected item:" << this->model->filePath(index);
                MainWindow::handleDroppedFile(this->model->filePath(index));
                qDebug() << "Name:" << this->model->fileName(index);
            }
        }
    });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionLocal_triggered() {
    const QString target_dir = "/home/jord/";
    qDebug() << "Setting treeview path to " << target_dir;
    MainWindow::setTreeViewPath(target_dir);
}

void MainWindow::on_actionVault_triggered() {
    const QString target_dir = "/home/jord/projects/dms/pdms/vault";
    qDebug() << "Setting treeview path to " << target_dir;
    MainWindow::setTreeViewPath(target_dir);
}

void MainWindow::setTreeViewPath(QString path){
    if (this->ui->treeView == nullptr) {
        qDebug() << "TreeView is a  nullptr.";
        return;
    }

    const QDir qdir(path);
    if (!this->model || !QDir(path).exists()) {
         qDebug() << "Directory does not exist:" << path;
         return;
    }

    qDebug() << "Setting root path to:" << path;
    this->model->setRootPath(qdir.absolutePath());
    this->ui->treeView->setRootIndex(model->index(path));
}

void MainWindow::on_savePushButton_clicked()
{
    if (activeFile.isEmpty()){
       qDebug() << "Tried to save a filepath that is empty: " << this->activeFile;
       return;
    }

    QFileInfo fileInfo(this->activeFile);
    if (!fileInfo.exists()){
       qDebug() << "No file exists at: " << this->activeFile;
       return;
    }

    if (!fileInfo.permission(QFile::WriteUser | QFile::ReadGroup)){
        qWarning() << "No permissions for file:" << fileInfo.fileName();
    }

    QString destination("/home/jord/projects/dms/pdms/vault/%1");
    destination = destination.arg(fileInfo.fileName());

   qDebug() << "Saving active file to destination: " << destination;
   bool successfullyCopied = QFile::copy(this->activeFile, destination);
   if (!successfullyCopied){
       qDebug() << "File was not copied succesfully";
       return;
   }

    // Create new database entry
    dbManager.addFileEntry(fileInfo.fileName(), fileInfo.absoluteFilePath(), fileInfo.size(),
                           fileInfo.suffix(), fileInfo.birthTime(), fileInfo.lastModified(),
                           fileInfo.owner(), "active", 0, "standard", "veryCleverCustomTag");
}

void MainWindow::on_addDummyFileButton_clicked()
{
   dbManager.addDummyFile();
}

void MainWindow::on_actionDms_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_actionDatabase_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_tableComboBox_activated(const QString &table)
{
    dbModel->setTable(table);
    dbModel->select();
    ui->databaseTableView->setModel(dbModel);
}

