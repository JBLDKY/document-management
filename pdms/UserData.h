#ifndef USERDATA_H
#define USERDATA_H

#include <QString>
#include <QStringList>
#include <QMap>
#include <FileEnums.h>

struct UserData {
    QString category;
    QStringList tags;
    RetentionPolicy retentionPolicy;
    FileStatus fileStatus;
    QMap<QString, QString> metadata;
    Permissions  permissions;
    int version;
};

#endif // USERDATA_H
