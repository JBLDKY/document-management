#include "FileOps.h"
#include <fstream>
#include <iostream>

std::string FileOps::readFile(const std::string &filePath) {
  std::ifstream file(filePath);
  std::string content, line;
  while (std::getline(file, line)) {
    content += line + "\n";
  }
  return content;
}

void FileOps::writeFile(const std::string &filePath,
                        const std::string &content) {
  std::ofstream file(filePath);
  file << content;
}
