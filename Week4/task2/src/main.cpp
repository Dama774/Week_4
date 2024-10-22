#include <iostream>
#include "converter.h"

int main() {
    std::string input;

    std::cout << "Введите сообщение для преобразования: ";
    std::getline(std::cin, input);
    
    int choice;
    std::cout << "Выберите тип преобразования:\n";
    std::cout << "1. В double\n";
    std::cout << "2. В int\n";
    std::cout << "3. В string (из double)\n";
    std::cin >> choice;

    try {
        switch (choice) {
            case 1: {
                double output;
                convertToDouble(input, output); // Если преобразование не удастся, будет выброшено исключение
                std::cout << "Преобразовано в double: " << output << std::endl;
                break;
            }
            case 2: {
                int output;
                convertToInt(input, output); // Если преобразование не удастся, будет выброшено исключение
                std::cout << "Преобразовано в int: " << output << std::endl;
                break;
            }
            case 3: {
                double temp;
                convertToDouble(input, temp); // Если преобразование не удастся, будет выброшено исключение
                std::string output;
                convertToString(temp, output);
                std::cout << "Преобразовано в string: " << output << std::endl;
                break;
            }
            default:
                std::cerr << "Ошибка: неверный выбор." << std::endl;
        }
    } catch (const std::invalid_argument &e) {
        // Обработка исключения: выводим сообщение об ошибке
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1; // Возвращаем ненулевой код для указания на ошибку
    }

    return 0; // Успешное завершение программы
}

