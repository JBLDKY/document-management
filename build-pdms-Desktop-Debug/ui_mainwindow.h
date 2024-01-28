/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLocal;
    QAction *actionOther;
    QAction *actionVault;
    QAction *actionDms;
    QAction *actionDatabase;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *dms;
    QLineEdit *nameLineEdit;
    QLabel *nameLabel;
    QLabel *categoryLabel;
    QComboBox *categoryComboBox;
    QLabel *tagsLabel;
    QLineEdit *tagsLineEdit;
    QLineEdit *ownerLineEdit;
    QLabel *ownerLabel;
    QLabel *versionLabel;
    QLineEdit *versionLineEdit;
    QLineEdit *sizeLineEdit;
    QLabel *sizeLabel;
    QDateTimeEdit *createdTimeEdit;
    QLabel *createdLabel;
    QDateTimeEdit *lastModifiedTimeEdit;
    QLabel *lastModifiedLabel;
    QPushButton *addDummyFileButton;
    QPushButton *savePushButton;
    QTreeView *treeView;
    QLabel *permissionsLabel;
    QComboBox *retentionPolicyComboBox;
    QComboBox *statusComboBox;
    QLabel *statusLabel;
    QLabel *retentionPolicyLabel;
    QComboBox *permissionsComboBox;
    QTableWidget *metadataTableWidget;
    QLabel *metadataLabel;
    QWidget *db;
    QTableView *databaseTableView;
    QComboBox *tableComboBox;
    QLabel *tableLabel;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuButtonSystem;
    QMenu *menuViw;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1255, 973);
        MainWindow->setAcceptDrops(true);
        actionLocal = new QAction(MainWindow);
        actionLocal->setObjectName(QString::fromUtf8("actionLocal"));
        actionOther = new QAction(MainWindow);
        actionOther->setObjectName(QString::fromUtf8("actionOther"));
        actionVault = new QAction(MainWindow);
        actionVault->setObjectName(QString::fromUtf8("actionVault"));
        actionDms = new QAction(MainWindow);
        actionDms->setObjectName(QString::fromUtf8("actionDms"));
        actionDatabase = new QAction(MainWindow);
        actionDatabase->setObjectName(QString::fromUtf8("actionDatabase"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(-90, -40, 1341, 961));
        dms = new QWidget();
        dms->setObjectName(QString::fromUtf8("dms"));
        nameLineEdit = new QLineEdit(dms);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setEnabled(true);
        nameLineEdit->setGeometry(QRect(550, 90, 281, 25));
        nameLabel = new QLabel(dms);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setEnabled(true);
        nameLabel->setGeometry(QRect(550, 70, 62, 17));
        categoryLabel = new QLabel(dms);
        categoryLabel->setObjectName(QString::fromUtf8("categoryLabel"));
        categoryLabel->setEnabled(true);
        categoryLabel->setGeometry(QRect(550, 120, 62, 17));
        categoryComboBox = new QComboBox(dms);
        categoryComboBox->addItem(QString());
        categoryComboBox->addItem(QString());
        categoryComboBox->addItem(QString());
        categoryComboBox->addItem(QString());
        categoryComboBox->addItem(QString());
        categoryComboBox->addItem(QString());
        categoryComboBox->setObjectName(QString::fromUtf8("categoryComboBox"));
        categoryComboBox->setGeometry(QRect(550, 140, 281, 25));
        tagsLabel = new QLabel(dms);
        tagsLabel->setObjectName(QString::fromUtf8("tagsLabel"));
        tagsLabel->setEnabled(true);
        tagsLabel->setGeometry(QRect(550, 170, 62, 17));
        tagsLineEdit = new QLineEdit(dms);
        tagsLineEdit->setObjectName(QString::fromUtf8("tagsLineEdit"));
        tagsLineEdit->setEnabled(true);
        tagsLineEdit->setGeometry(QRect(550, 190, 281, 25));
        ownerLineEdit = new QLineEdit(dms);
        ownerLineEdit->setObjectName(QString::fromUtf8("ownerLineEdit"));
        ownerLineEdit->setEnabled(false);
        ownerLineEdit->setGeometry(QRect(860, 290, 191, 25));
        ownerLabel = new QLabel(dms);
        ownerLabel->setObjectName(QString::fromUtf8("ownerLabel"));
        ownerLabel->setEnabled(true);
        ownerLabel->setGeometry(QRect(860, 270, 62, 17));
        versionLabel = new QLabel(dms);
        versionLabel->setObjectName(QString::fromUtf8("versionLabel"));
        versionLabel->setGeometry(QRect(860, 220, 62, 17));
        versionLineEdit = new QLineEdit(dms);
        versionLineEdit->setObjectName(QString::fromUtf8("versionLineEdit"));
        versionLineEdit->setEnabled(false);
        versionLineEdit->setGeometry(QRect(860, 240, 191, 25));
        sizeLineEdit = new QLineEdit(dms);
        sizeLineEdit->setObjectName(QString::fromUtf8("sizeLineEdit"));
        sizeLineEdit->setEnabled(false);
        sizeLineEdit->setGeometry(QRect(860, 190, 191, 25));
        sizeLabel = new QLabel(dms);
        sizeLabel->setObjectName(QString::fromUtf8("sizeLabel"));
        sizeLabel->setGeometry(QRect(860, 170, 62, 17));
        createdTimeEdit = new QDateTimeEdit(dms);
        createdTimeEdit->setObjectName(QString::fromUtf8("createdTimeEdit"));
        createdTimeEdit->setEnabled(false);
        createdTimeEdit->setGeometry(QRect(860, 140, 191, 26));
        createdLabel = new QLabel(dms);
        createdLabel->setObjectName(QString::fromUtf8("createdLabel"));
        createdLabel->setEnabled(true);
        createdLabel->setGeometry(QRect(860, 120, 101, 17));
        lastModifiedTimeEdit = new QDateTimeEdit(dms);
        lastModifiedTimeEdit->setObjectName(QString::fromUtf8("lastModifiedTimeEdit"));
        lastModifiedTimeEdit->setEnabled(false);
        lastModifiedTimeEdit->setGeometry(QRect(860, 90, 191, 26));
        lastModifiedLabel = new QLabel(dms);
        lastModifiedLabel->setObjectName(QString::fromUtf8("lastModifiedLabel"));
        lastModifiedLabel->setEnabled(true);
        lastModifiedLabel->setGeometry(QRect(860, 70, 101, 17));
        addDummyFileButton = new QPushButton(dms);
        addDummyFileButton->setObjectName(QString::fromUtf8("addDummyFileButton"));
        addDummyFileButton->setGeometry(QRect(860, 390, 131, 31));
        savePushButton = new QPushButton(dms);
        savePushButton->setObjectName(QString::fromUtf8("savePushButton"));
        savePushButton->setGeometry(QRect(860, 340, 131, 31));
        treeView = new QTreeView(dms);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(90, 40, 441, 921));
        permissionsLabel = new QLabel(dms);
        permissionsLabel->setObjectName(QString::fromUtf8("permissionsLabel"));
        permissionsLabel->setEnabled(true);
        permissionsLabel->setGeometry(QRect(550, 270, 91, 17));
        retentionPolicyComboBox = new QComboBox(dms);
        retentionPolicyComboBox->addItem(QString());
        retentionPolicyComboBox->addItem(QString());
        retentionPolicyComboBox->addItem(QString());
        retentionPolicyComboBox->addItem(QString());
        retentionPolicyComboBox->addItem(QString());
        retentionPolicyComboBox->addItem(QString());
        retentionPolicyComboBox->setObjectName(QString::fromUtf8("retentionPolicyComboBox"));
        retentionPolicyComboBox->setGeometry(QRect(550, 240, 281, 25));
        statusComboBox = new QComboBox(dms);
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->setObjectName(QString::fromUtf8("statusComboBox"));
        statusComboBox->setGeometry(QRect(550, 340, 281, 25));
        statusLabel = new QLabel(dms);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setEnabled(true);
        statusLabel->setGeometry(QRect(550, 320, 91, 17));
        retentionPolicyLabel = new QLabel(dms);
        retentionPolicyLabel->setObjectName(QString::fromUtf8("retentionPolicyLabel"));
        retentionPolicyLabel->setEnabled(true);
        retentionPolicyLabel->setGeometry(QRect(550, 220, 121, 17));
        permissionsComboBox = new QComboBox(dms);
        permissionsComboBox->addItem(QString());
        permissionsComboBox->addItem(QString());
        permissionsComboBox->addItem(QString());
        permissionsComboBox->addItem(QString());
        permissionsComboBox->addItem(QString());
        permissionsComboBox->addItem(QString());
        permissionsComboBox->addItem(QString());
        permissionsComboBox->setObjectName(QString::fromUtf8("permissionsComboBox"));
        permissionsComboBox->setGeometry(QRect(550, 290, 281, 25));
        metadataTableWidget = new QTableWidget(dms);
        if (metadataTableWidget->columnCount() < 2)
            metadataTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        metadataTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        metadataTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (metadataTableWidget->rowCount() < 1)
            metadataTableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        metadataTableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        metadataTableWidget->setObjectName(QString::fromUtf8("metadataTableWidget"));
        metadataTableWidget->setGeometry(QRect(550, 390, 281, 51));
        metadataTableWidget->setMinimumSize(QSize(281, 0));
        metadataTableWidget->horizontalHeader()->setMinimumSectionSize(32);
        metadataTableWidget->verticalHeader()->setMinimumSectionSize(21);
        metadataLabel = new QLabel(dms);
        metadataLabel->setObjectName(QString::fromUtf8("metadataLabel"));
        metadataLabel->setEnabled(true);
        metadataLabel->setGeometry(QRect(550, 370, 91, 17));
        stackedWidget->addWidget(dms);
        db = new QWidget();
        db->setObjectName(QString::fromUtf8("db"));
        databaseTableView = new QTableView(db);
        databaseTableView->setObjectName(QString::fromUtf8("databaseTableView"));
        databaseTableView->setGeometry(QRect(90, 40, 911, 921));
        databaseTableView->setAlternatingRowColors(true);
        databaseTableView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        databaseTableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        databaseTableView->setSortingEnabled(true);
        databaseTableView->horizontalHeader()->setCascadingSectionResizes(false);
        tableComboBox = new QComboBox(db);
        tableComboBox->addItem(QString());
        tableComboBox->addItem(QString());
        tableComboBox->addItem(QString());
        tableComboBox->addItem(QString());
        tableComboBox->addItem(QString());
        tableComboBox->setObjectName(QString::fromUtf8("tableComboBox"));
        tableComboBox->setGeometry(QRect(1020, 80, 171, 25));
        tableLabel = new QLabel(db);
        tableLabel->setObjectName(QString::fromUtf8("tableLabel"));
        tableLabel->setGeometry(QRect(1020, 60, 71, 17));
        stackedWidget->addWidget(db);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1255, 22));
        menuButtonSystem = new QMenu(menubar);
        menuButtonSystem->setObjectName(QString::fromUtf8("menuButtonSystem"));
        menuViw = new QMenu(menubar);
        menuViw->setObjectName(QString::fromUtf8("menuViw"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuButtonSystem->menuAction());
        menubar->addAction(menuViw->menuAction());
        menuButtonSystem->addAction(actionLocal);
        menuButtonSystem->addAction(actionVault);
        menuButtonSystem->addAction(actionOther);
        menuViw->addAction(actionDms);
        menuViw->addAction(actionDatabase);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLocal->setText(QCoreApplication::translate("MainWindow", "Local", nullptr));
        actionOther->setText(QCoreApplication::translate("MainWindow", "Other", nullptr));
        actionVault->setText(QCoreApplication::translate("MainWindow", "Vault", nullptr));
        actionDms->setText(QCoreApplication::translate("MainWindow", "Documents", nullptr));
        actionDatabase->setText(QCoreApplication::translate("MainWindow", "Database", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "File name", nullptr));
        categoryLabel->setText(QCoreApplication::translate("MainWindow", "Category", nullptr));
        categoryComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Other", nullptr));
        categoryComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Taxes", nullptr));
        categoryComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Programming", nullptr));
        categoryComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Sales", nullptr));
        categoryComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Car", nullptr));
        categoryComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Work", nullptr));

        tagsLabel->setText(QCoreApplication::translate("MainWindow", "Tags", nullptr));
        tagsLineEdit->setText(QString());
        ownerLineEdit->setText(QString());
        ownerLabel->setText(QCoreApplication::translate("MainWindow", "Owner", nullptr));
        versionLabel->setText(QCoreApplication::translate("MainWindow", "Version", nullptr));
        versionLineEdit->setText(QString());
        sizeLineEdit->setText(QString());
        sizeLabel->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        createdLabel->setText(QCoreApplication::translate("MainWindow", "Created", nullptr));
        lastModifiedLabel->setText(QCoreApplication::translate("MainWindow", "Last modified", nullptr));
        addDummyFileButton->setText(QCoreApplication::translate("MainWindow", "addDummyFile", nullptr));
        savePushButton->setText(QCoreApplication::translate("MainWindow", "Save to vault", nullptr));
        permissionsLabel->setText(QCoreApplication::translate("MainWindow", "Permissions", nullptr));
        retentionPolicyComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Unknown", nullptr));
        retentionPolicyComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Short term", nullptr));
        retentionPolicyComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Mid term", nullptr));
        retentionPolicyComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Long term", nullptr));
        retentionPolicyComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Permanent", nullptr));
        retentionPolicyComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Temporary", nullptr));

        statusComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Unknown", nullptr));
        statusComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Active", nullptr));
        statusComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Paused", nullptr));
        statusComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Awaiting approval", nullptr));
        statusComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Reviewed", nullptr));
        statusComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Archived", nullptr));
        statusComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Deleted", nullptr));

        statusLabel->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        retentionPolicyLabel->setText(QCoreApplication::translate("MainWindow", "Retention policy", nullptr));
        permissionsComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Unknown", nullptr));
        permissionsComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Read", nullptr));
        permissionsComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Write", nullptr));
        permissionsComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Execute", nullptr));
        permissionsComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Full control", nullptr));
        permissionsComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "No access", nullptr));
        permissionsComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Restricted", nullptr));

        QTableWidgetItem *___qtablewidgetitem = metadataTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = metadataTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = metadataTableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        metadataLabel->setText(QCoreApplication::translate("MainWindow", "Metadata", nullptr));
        tableComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "files", nullptr));
        tableComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "file_metadata", nullptr));
        tableComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "file_access", nullptr));
        tableComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "file_tags", nullptr));
        tableComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "file_tag_mapping", nullptr));

        tableLabel->setText(QCoreApplication::translate("MainWindow", "Table", nullptr));
        menuButtonSystem->setTitle(QCoreApplication::translate("MainWindow", "Source", nullptr));
        menuViw->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
