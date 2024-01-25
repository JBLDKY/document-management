#ifndef FILEOPS_H
#define FILEOPS_H

#include <string>

class FileOps {
public:
  static std::string readFile(const std::string &filePath);
  static void writeFile(const std::string &filePath,
                        const std::string &content);
};

#endif
