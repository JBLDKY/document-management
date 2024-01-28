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
#include <QMap>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DatabaseManager.h"
#include "UserData.h"
#include "FileEnums.h"
#include <QSqlTableModel>
#include <QTableView>


const QString MainWindow::DEFAULT_PATH_LOCAL = "/home/jord/";
const QString MainWindow::DEFAULT_PATH_VAULT = "/home/jord/projects/dms/pdms/vault";
const QString MainWindow::DEFAULT_TABLE = "files";

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), dbManager() {
        ui->setupUi(this);
        setAcceptDrops(true);

        MainWindow::setupViews();
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


void MainWindow::setupViews() {
    this->model = new QFileSystemModel(this);
    this->model->setRootPath(QDir::homePath());

    ui->treeView->setModel(this->model);
    switchToVaultView();
}

void MainWindow::switchToVaultView() {
    this->model->setRootPath(DEFAULT_PATH_VAULT);
    ui->treeView->setRootIndex(this->model->index(DEFAULT_PATH_VAULT));

}

void MainWindow::switchToLocalFileSystemView() {
    QString localPath = QDir::homePath();
    this->model->setRootPath(localPath);
    ui->treeView->setRootIndex(this->model->index(localPath));
}

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
        ui->nameLineEdit->setText(file.fileName());
        ui->lastModifiedTimeEdit->setDateTime(file.lastModified());
        ui->createdTimeEdit->setDateTime(file.birthTime());
        ui->ownerLineEdit->setText(file.owner());
        ui->sizeLineEdit->setText(QString::number(file.size()));
        ui->versionLineEdit->setText("0");
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
    switchToLocalFileSystemView();
}


void MainWindow::on_actionVault_triggered() {
    switchToVaultView();
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

    /*
     * Create new database entry from the destination file.
     * The copied file might have a new name/path/extension according to the user input.
     */

   QMap<QString, QString> metadata;

   for(int i = 0; i < this->ui->metadataTableWidget->rowCount(); i++){
       if (this->ui->metadataTableWidget->item(i,0) == nullptr ||
            this->ui->metadataTableWidget->item(i,1) == nullptr){
           continue;
       }
       qDebug() <<  this->ui->metadataTableWidget->item(i, 0);
       QString key(this->ui->metadataTableWidget->item(i, 0)->text());
       QString value(this->ui->metadataTableWidget->item(i, 1)->text());

       qDebug() << "key :" << key;
       qDebug() << "value :" << value;

       metadata[key] = value;
   }

   const QFileInfo fi((QFile(destination)));
   UserData userData;
    userData.category = this->ui->categoryComboBox->currentText();
    userData.fileStatus = stringToFileStatus(this->ui->statusComboBox->currentText());
    userData.metadata = metadata;
    userData.permissions = stringToPermissions(this->ui->permissionsComboBox->currentText());
    userData.retentionPolicy = stringToRetentionPolicy(this->ui->retentionPolicyComboBox->currentText());
    userData.tags = QStringList(this->ui->tagsLineEdit->text().toLower().trimmed().split(","));

    // Handle error, preferably in frontend
    // Actually, this just returns 0
    userData.version = ui->versionLineEdit->text().toInt();

   dbManager.addFileEntry(fi, userData);
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

