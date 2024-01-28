#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDateTime>
#include <QFileSystemModel>
#include <UserData.h>

class DatabaseManager {
public:
    DatabaseManager();
    void setupDatabase();
    int addTagAndGetId(const QString &tag);
    ~DatabaseManager();
    void addDummyFile();
    void dropTable(const QString &table);
    // FileName is provided separately
    void addFileEntry(const QFileInfo fileinfo, const UserData userData);
};

#endif // DATABASEMANAGER_H
