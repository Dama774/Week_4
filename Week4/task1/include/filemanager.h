#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>

bool openFile(std::ifstream &file, const std::string &filename);
void readFile(std::ifstream &file);
void closeFile(std::ifstream &file);

#endif // FILEMANAGER_H

