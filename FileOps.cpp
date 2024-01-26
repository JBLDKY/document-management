#include "FileOps.h"
#include <chrono>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <system_error>
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

void FileOps::printFileInfo(const FileInfo &fileInfo) {
  std::time_t lastModified =
      std::chrono::system_clock::to_time_t(fileInfo.lastModifiedTime);

  std::cout << "File Path: " << fileInfo.filePath << std::endl;
  std::cout << "File size: " << fileInfo.fileSize << " bytes" << std::endl;
  std::cout << "Last modified: " << lastModified << std::endl;
}

void FileOps::listFiles(const std::string &directoryPath) {
  for (const auto &entry : std::filesystem::directory_iterator(directoryPath)) {
    std::cout << entry.path() << std::endl;
  }
}

FileInfo FileOps::getFileInfo(const std::string &filePath) {
  FileInfo info;
  std::filesystem::path path(filePath);

  try {
    if (std::filesystem::exists(path)) {
      info.filePath = filePath;
      info.fileSize = std::filesystem::file_size(path);

      auto ftime = std::filesystem::last_write_time(path);
      // info.lastModifiedTime = decltype(ftime)::clock::to_sys(ftime);
      // info.lastModifiedTime = std::chrono::sys_time(ftime);
    }
  } catch (const std::filesystem::filesystem_error &e) {

    std::cout << "Invalid / bad file at: " << path << std::endl;
  }

  return info;
}
