#include "filemanager.h"
#include <iostream>

bool openFile(std::ifstream &file, const std::string &filename) {
    file.open(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл '" << filename << "'." << std::endl;
        return false;
    }
    return true;
}

void readFile(std::ifstream &file) {
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl; // Выводим строку на экран
    }

    if (file.bad()) {
        std::cerr << "Ошибка: произошла ошибка при чтении файла." << std::endl;
    }
}

void closeFile(std::ifstream &file) {
    file.close();

    if (file.is_open()) {
        std::cerr << "Ошибка: не удалось закрыть файл." << std::endl;
    }
}

