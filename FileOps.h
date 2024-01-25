#ifndef FILEOPS_H
#define FILEOPS_H

#include <string>
#include <vector>

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
};

#endif
