#include "FileOps.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

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

std::string readFile(const std::string &filePath) {
  std::ifstream file(filePath);
  std::stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}

std::vector<char> FileOps::readFileBytes(const std::string &filePath) {
  std::ifstream file(filePath, std::ios::binary);
  std::vector<char> buffer((std::istreambuf_iterator<char>(file)),
                           std::istreambuf_iterator<char>());
  return buffer;
}

void FileOps::writeFileBytes(const std::string &filePath,
                             const std::vector<char> &data) {
  std::ofstream file(filePath, std::ios::binary);
  file.write(data.data(), data.size());
}

void FileOps::printFileInfo(const std::string &filePath) {
  std::filesystem::path path(filePath);
  if (std::filesystem::exists(path)) {
    std::cout << "Size: " << std::filesystem::file_size(path) << " bytes"
              << std::endl;
  }
}

void FileOps::listFiles(const std::string &directoryPath) {
  for (const auto &entry : std::filesystem::directory_iterator(directoryPath)) {
    std::cout << entry.path() << std::endl;
  }
}
