#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <DatabaseManager.h>
#include <QSqlTableModel>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);
    void handleDroppedFile(QString filePath);
    void selectCallback();
    void switchToLocalFileSystemView();
    void switchToVaultView();
    void setupViews();

    QFileSystemModel *model; // filepath for TreeView
    QSqlTableModel *dbModel; // database for TableView
    void setTreeViewPath(QString);
    QString activeFile;

    ~MainWindow();


private slots:
    void on_actionLocal_triggered();

    void on_actionVault_triggered();

    void on_savePushButton_clicked();

    void on_addDummyFileButton_clicked();

    void on_actionDms_triggered();

    void on_actionDatabase_triggered();

    void on_tableComboBox_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    DatabaseManager dbManager;
    static const QString DEFAULT_PATH_LOCAL;
    static const QString DEFAULT_PATH_VAULT;
    static const QString DEFAULT_TABLE;
};


#endif // MAINWINDOW_H
