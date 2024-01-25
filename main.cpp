#include "FileOps.h"
#include <iostream>

int main() {
  std::string fileContent = FileOps::readFile("example.txt");
  std::cout << fileContent;

  const std::string filePath = "./example_dump.txt";

  FileOps::writeFile(filePath, fileContent);

  return 0;
}
