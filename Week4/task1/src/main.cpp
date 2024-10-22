#include "filemanager.h"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Ошибка: не указано имя файла для открытия." << std::endl;
        return 1;
    }

    std::string filename = argv[1]; // Указываем имя файла из командной строки
    std::ifstream file;

    if (!openFile(file, filename)) {
        return 1; // Возвращаем ненулевой код, чтобы указать на ошибку
    }

    readFile(file); // Читаем файл

    closeFile(file); // Закрываем файл

    return 0; // Успешное завершение программы
}

