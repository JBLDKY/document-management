#ifndef FILEOPS_H
#define FILEOPS_H

#include <string>
#include <vector>

#include <chrono>

struct FileInfo {
  std::string filePath;
  std::uintmax_t fileSize;
  std::chrono::system_clock::time_point creationTime;
  std::chrono::system_clock::time_point lastModifiedTime;
};

class FileOps {
public:
  // string
  static std::string readFile(const std::string &filePath);
  static void writeFile(const std::string &filePath,
                        const std::string &content);
  static void copyFile(const std::string &source,
                       const std::string &destination);

  // bytes
  static std::vector<char> readFileBytes(const std::string &filePath);
  static void writeFileBytes(const std::string &filePath,
                             const std::vector<char> &data);

  // fs / info
  static void listFiles(const std::string &directoryPath);
  static void printFileInfo(const std::string &filePath);
  FileInfo getFileInfo(const std::string &filePath);
};

#endif
