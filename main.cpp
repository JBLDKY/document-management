#include "FileOps.h"
#include <iostream>

int main() {
  std::string fileContent = FileOps::readFile("example.txt");

  const std::string filePath = "./example_dump.txt";

  FileOps::listFiles("./");

  FileOps::printFileInfo(filePath);

  return 0;
}
