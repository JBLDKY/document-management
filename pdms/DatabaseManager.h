#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDateTime>

class DatabaseManager {
public:
    DatabaseManager();
    void setupDatabase();
    int addTagAndGetId(const QString &tag);
    ~DatabaseManager();
    void addDummyFile();
    void dropTable(const QString &table);
    void addFileEntry(const QString& name, const QString& path, qint64 size,
                      const QString& type, const QDateTime& creationDate,
                      const QDateTime& modificationDate, const QString& owner,
                      const QString& status, int version, const QString& retentionPolicy,
                      const QString& tag);
};

#endif // DATABASEMANAGER_H
