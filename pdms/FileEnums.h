#ifndef FILEENUMS_H
#define FILEENUMS_H

#include <QFileSystemModel>

enum class FileStatus {
    Active,
    Paused,
    AwaitingAppoval,
    Reviewed,
    Archived,
    Deleted,
    Unknown,
};


QString fileStatusToString(FileStatus status);
FileStatus stringToFileStatus(const QString& statusStr);


enum class RetentionPolicy {
    ShortTerm,
    MidTerm,
    LongTerm,
    Standard,
    Temporary,
    Permanent,
    Unknown,
};

QString retentionPolicyToString(RetentionPolicy retentionPolicy);
RetentionPolicy stringToRetentionPolicy(const QString& retentionPolicyStr);

enum class Permissions {
    Read,
    Write,
    Execute,
    FullControl,
    NoAccess,
    Restricted
};

QString permissionsToString(Permissions permission);
Permissions stringToPermissions(const QString& permissionStr);

#endif // FILEENUMS_H
