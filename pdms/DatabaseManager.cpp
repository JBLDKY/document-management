#include "DatabaseManager.h"
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QDateTime>
#include <QFileSystemModel>

DatabaseManager::DatabaseManager() {
    setupDatabase();
}

DatabaseManager::~DatabaseManager() {
    QSqlDatabase db = QSqlDatabase::database();
    if (db.isOpen()) {
        db.close();
    }
}

 UserData DatabaseManager::findSelectedFile(const QString &filePath){
    QSqlQuery query;
    UserData userData;
    int fileId = -1;

    query.prepare("SELECT fm.key, fm.value FROM file_metadata fm INNER JOIN files f ON fm.file_id = f.file_id WHERE f.path = :filePath");
    query.bindValue(":filePath", filePath);

    query.prepare("SELECT file_id, status, retention_policy, version FROM files WHERE path = :filePath");
    query.bindValue(":filePath", filePath);

    if (query.exec() && query.next()) {
        fileId = query.value(0).toInt();
        userData.fileStatus = stringToFileStatus(query.value(1).toString());
        userData.retentionPolicy = stringToRetentionPolicy(query.value(2).toString());
        userData.version = query.value(3).toInt();
    } else {
        qDebug() << "Selected file could not be found" << query.lastError().text();
    }

    if (fileId != -1) {
          // Retrieve and set metadata
          QSqlQuery metadataQuery;
          metadataQuery.prepare("SELECT key, value FROM file_metadata WHERE file_id = :fileId");
          metadataQuery.bindValue(":fileId", fileId);

          if (metadataQuery.exec()) {
              while (metadataQuery.next()) {
                  QString key = metadataQuery.value(0).toString();
                  QString value = metadataQuery.value(1).toString();
                  userData.metadata.insert(key, value);
              }
          }

          // Retrieve and set tags
          QSqlQuery tagsQuery;
          tagsQuery.prepare("SELECT t.tag FROM file_tags t INNER JOIN file_tag_mapping m ON t.tag_id = m.tag_id WHERE m.file_id = :fileId");
          tagsQuery.bindValue(":fileId", fileId);

          if (tagsQuery.exec()) {
              while (tagsQuery.next()) {
                  userData.tags.append(tagsQuery.value(0).toString());
              }
          }
      }
    return userData;
}

void DatabaseManager::setupDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("pdms.db");

    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
        return;
    }

    QSqlQuery query;

    // files
    if (!query.exec("CREATE TABLE IF NOT EXISTS files ("
                    "file_id INTEGER PRIMARY KEY, "
                    "name TEXT, "
                    "path TEXT, "
                    "size INTEGER, "
                    "type TEXT, "
                    "creation_date DATETIME, "
                    "modification_date DATETIME, "
                    "owner_id INTEGER, "
                    "status TEXT, "
                    "version INTEGER, "
                    "retention_policy TEXT)")) {
        qDebug() << "Error creating files table:" << query.lastError().text();
    }

    // file_metadata
    if (!query.exec("CREATE TABLE IF NOT EXISTS file_metadata ("
                    "metadata_id INTEGER PRIMARY KEY, "
                    "file_id INTEGER, "
                    "key TEXT, "
                    "value TEXT, "
                    "FOREIGN KEY(file_id) REFERENCES files(file_id))")) {
        qDebug() << "Error creating file_metadata table:" << query.lastError().text();
    }

    // file_access
    if (!query.exec("CREATE TABLE IF NOT EXISTS file_access ("
                    "access_id INTEGER PRIMARY KEY, "
                    "file_id INTEGER, "
                    "user_id INTEGER, "
                    "permission_type TEXT, "
                    "FOREIGN KEY(file_id) REFERENCES files(file_id))")) {
        qDebug() << "Error creating file_access table:" << query.lastError().text();
    }

    // file_tags
    if (!query.exec("CREATE TABLE IF NOT EXISTS file_tags ("
                    "tag_id INTEGER PRIMARY KEY, "
                    "tag TEXT)")) {
        qDebug() << "Error creating file_tags table:" << query.lastError().text();
    }

    // file_tag_mapping
    if (!query.exec("CREATE TABLE IF NOT EXISTS file_tag_mapping ("
                    "file_id INTEGER, "
                    "tag_id INTEGER, "
                    "FOREIGN KEY(file_id) REFERENCES files(file_id), "
                    "FOREIGN KEY(tag_id) REFERENCES file_tags(tag_id))")) {
        qDebug() << "Error creating file_tag_mapping table:" << query.lastError().text();
    }
}

void DatabaseManager::addDummyFile() {
    QSqlQuery query;

    // Insert into 'files' table first
    query.prepare("INSERT INTO files (name, path, size, type, creation_date, modification_date, owner_id, status, version, retention_policy) "
                  "VALUES (:name, :path, :size, :type, :creation_date, :modification_date, :owner_id, :status, :version, :retention_policy)");
    query.bindValue(":name", "dummy.txt");
    query.bindValue(":path", "/dummy/path/dummy.txt");
    query.bindValue(":size", 1024);
    query.bindValue(":type", "txt");
    query.bindValue(":creation_date", QDateTime::currentDateTime());
    query.bindValue(":modification_date", QDateTime::currentDateTime());
    query.bindValue(":owner_id", 1);
    query.bindValue(":status", "active");
    query.bindValue(":version", 1);
    query.bindValue(":retention_policy", "standard");
    if (!query.exec()) {
        qDebug() << "Error adding dummy file:" << query.lastError().text();
        return;
    }

    int fileId = query.lastInsertId().toInt();

    // Insert into 'file_metadata' table
    query.prepare("INSERT INTO file_metadata (file_id, key, value) VALUES (:file_id, :key, :value)");
    query.bindValue(":file_id", fileId);
    query.bindValue(":key", "dummyKey");
    query.bindValue(":value", "dummyValue");
    if (!query.exec()) {
        qDebug() << "Error adding file metadata:" << query.lastError().text();
    }

    // Insert into 'file_access' table
    query.prepare("INSERT INTO file_access (file_id, user_id, permission_type) VALUES (:file_id, :user_id, :permission_type)");
    query.bindValue(":file_id", fileId);
    query.bindValue(":user_id", 1);
    query.bindValue(":permission_type", "read");
    if (!query.exec()) {
        qDebug() << "Error adding file_access:" << query.lastError().text();
    }

    // tagId required from here onwards
    QString tag = "VeryWittyTag";
    int tagId = addTagAndGetId(tag);

    if (tagId != -1) {
        // Insert into 'file_tag_mapping' table
        query.prepare("INSERT INTO file_tag_mapping (file_id, tag_id) VALUES (:file_id, :tag_id)");
        query.bindValue(":file_id", fileId);
        query.bindValue(":tag_id", tagId);
        if (!query.exec()) {
            qDebug() << "Error mapping tag to file:" << query.lastError().text();
        }
    }

    qDebug() << "Dummy file added successfully";
}

void DatabaseManager::dropTable(const QString& table){
    QSqlQuery query;
    QString queryString = "DROP TABLE IF EXISTS " + table;

    if (!query.exec(queryString)) {
        qDebug() << "Error dropping table " << table << query.lastError().text();
    } else {
        qDebug() << "Table " << table << " dropped successfully";
    }
 }

int DatabaseManager::addTagAndGetId(const QString& tag) {
    QSqlQuery query;
    query.prepare("SELECT tag_id FROM file_tags WHERE tag = :tag");
    query.bindValue(":tag", tag);
    if (!query.exec()) {
        qDebug() << "Error checking for existing tag:" << query.lastError().text();
        return -1;
    }

    if (query.next()) {
        // Tag exists
        return query.value(0).toInt();
    } else {
        // Tag doesn't exist
        query.prepare("INSERT INTO file_tags (tag) VALUES (:tag)");
        query.bindValue(":tag", tag);
        if (!query.exec()) {
            qDebug() << "Error inserting new tag:" << query.lastError().text();
            return -1;
        }
        return query.lastInsertId().toInt();
    }
}

void DatabaseManager::addFileEntry(const QFileInfo fileInfo, const UserData userData) {
    QSqlQuery query;

    // files
    query.prepare("INSERT INTO files (name, path, size, type, creation_date, modification_date, owner_id, status, version, retention_policy) "
                  "VALUES (:name, :path, :size, :type, :creation_date, :modification_date, :owner_id, :status, :version, :retention_policy)");
    query.bindValue(":name", fileInfo.fileName());
    query.bindValue(":path", fileInfo.absoluteFilePath());
    query.bindValue(":size", fileInfo.size());
    query.bindValue(":type", fileInfo.suffix());
    query.bindValue(":creation_date", fileInfo.birthTime());
    query.bindValue(":modification_date", fileInfo.lastModified());
    query.bindValue(":owner_id", fileInfo.owner());  // Adjust according to your owner_id handling
    query.bindValue(":status", fileStatusToString(userData.fileStatus));
    query.bindValue(":version", userData.version);
    query.bindValue(":retention_policy", retentionPolicyToString(userData.retentionPolicy));
    if (!query.exec()) {
        qDebug() << "Error adding file to database:" << query.lastError().text();
    }

    // Now create the fileId for use in the other tables
    int fileId = query.lastInsertId().toInt();

    //Unpack metadata
    QMapIterator<QString, QString> i(userData.metadata);
    while (i.hasNext()) {
        i.next();

        // Insert entry per metadata key, value pair into 'file_metadata' table
        query.prepare("INSERT INTO file_metadata (file_id, key, value) VALUES (:file_id, :key, :value)");
        query.bindValue(":file_id", fileId);
        query.bindValue(":key", i.key());
        query.bindValue(":value", i.value());
        if (!query.exec()) {
            qDebug() << "Error adding file metadata:" << query.lastError().text();
        }
    }

    // Insert into 'file_access' table
    query.prepare("INSERT INTO file_access (file_id, user_id, permission_type) VALUES (:file_id, :user_id, :permission_type)");
    query.bindValue(":file_id", fileId);
    query.bindValue(":user_id", 1);
    query.bindValue(":permission_type", permissionsToString(userData.permissions));
    if (!query.exec()) {
        qDebug() << "Error adding file_access:" << query.lastError().text();
    }

    QStringList tags = userData.tags;
    foreach (const QString &tag, tags) {
        int tagId = addTagAndGetId(tag);
        if (tagId != -1) {
            // Insert into 'file_tag_mapping' table for each tag
            QSqlQuery query;
            query.prepare("INSERT INTO file_tag_mapping (file_id, tag_id) VALUES (:file_id, :tag_id)");
            query.bindValue(":file_id", fileId); // fileId is the ID of the file you inserted earlier
            query.bindValue(":tag_id", tagId);
            if (!query.exec()) {
                qDebug() << "Error mapping tag to file:" << query.lastError().text();
            }
        } else {
            qDebug() << "Error getting/adding tag ID for tag:" << tag;
        }
    }
}
