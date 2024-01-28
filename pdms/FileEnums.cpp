#include<FileEnums.h>

QString fileStatusToString(FileStatus status) {
    switch (status) {
    case FileStatus::Active: return "Active";
    case FileStatus::Paused: return "Paused";
    case FileStatus::AwaitingAppoval: return "AwaitingAppoval";
    case FileStatus::Reviewed: return "Reviewed";
    case FileStatus::Archived: return "Archived";
    case FileStatus::Deleted: return "Deleted";
    case FileStatus::Unknown: return "Unknown";
    }
}

FileStatus stringToFileStatus(const QString& statusStr) {
    if (statusStr == "Active") return FileStatus::Active;
    if (statusStr == "Paused") return FileStatus::Paused;
    if (statusStr == "AwaitingAppoval") return FileStatus::AwaitingAppoval;
    if (statusStr == "Reviewed") return FileStatus::Reviewed;
    if (statusStr == "Archived") return FileStatus::Archived;
    if (statusStr == "Deleted") return FileStatus::Deleted;
    return FileStatus::Deleted;
}

QString retentionPolicyToString(RetentionPolicy retentionPolicy) {
    switch (retentionPolicy){
    case RetentionPolicy::ShortTerm: return "ShortTerm";
    case RetentionPolicy::MidTerm: return "MidTerm";
    case RetentionPolicy::LongTerm: return "LongTerm";
    case RetentionPolicy::Standard: return "Standard";
    case RetentionPolicy::Temporary: return "Temporary";
    case RetentionPolicy::Permanent: return "Permanent";
    case RetentionPolicy::Unknown: return "Unknown";
    }
    return "Unknown";
}

RetentionPolicy stringToRetentionPolicy(const QString& retentionPolicyStr) {
    if (retentionPolicyStr == "ShortTerm") return RetentionPolicy::ShortTerm;
    if (retentionPolicyStr == "MidTerm") return RetentionPolicy::MidTerm;
    if (retentionPolicyStr == "LongTerm") return RetentionPolicy::LongTerm;
    if (retentionPolicyStr == "Standard") return RetentionPolicy::Standard;
    if (retentionPolicyStr == "Temporary") return RetentionPolicy::Temporary;
    if (retentionPolicyStr == "Permanent") return RetentionPolicy::Permanent;
    return RetentionPolicy::Unknown;
}

QString permissionsToString(Permissions permission) {
    switch (permission) {
    case Permissions::Read: return "Read";
    case Permissions::Write: return "Write";
    case Permissions::Execute: return "Execute";
    case Permissions::FullControl: return "FullControl";
    case Permissions::NoAccess: return "NoAccess";
    case Permissions::Restricted: return "Restricted";
    }
    return "Unknown";
}

Permissions stringToPermissions(const QString& permissionStr) {
    if (permissionStr == "Read") return Permissions::Read;
    if (permissionStr == "Write") return Permissions::Write;
    if (permissionStr == "Execute") return Permissions::Execute;
    if (permissionStr == "FullControl") return Permissions::FullControl;
    if (permissionStr == "NoAccess") return Permissions::NoAccess;
    if (permissionStr == "Restricted") return Permissions::Restricted;
    return Permissions::Read;
}

