#include "FileOps.h"
#include <iostream>

int main() {
  std::string fileContent = FileOps::readFile("example.txt");

  const std::string filePath = "./example_dump.txt";

  // FileOps::listFiles("./");
  //
  const FileInfo fileInfo = FileOps::getFileInfo(filePath);

  FileOps::printFileInfo(fileInfo);

  return 0;
}
