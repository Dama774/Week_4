#include <iostream>
#include <iomanip>
#include "sensordata.h"
#include "invalidinputexception.h"

int main() {
    std::string input;
    std::cout << "Введите показания датчиков: ";
    std::getline(std::cin, input);

    // Проверка длины входной строки
    if (input.length() > MAX_INPUT_LENGTH) {
        std::cerr << "Ошибка: Длина строки превышает максимальное значение в " 
                  << MAX_INPUT_LENGTH << " символов." << std::endl;
        return 1; // Завершение программы с ошибкой
    }

    // Проверка на пустую строку
    if (input.empty()) {
        throw std::runtime_error("Ошибка: Должны быть введены показания датчиков."); // Выбрасываем исключение
    }

    SensorManager manager;

    try {
        manager.calculateAverageTemperatures(input);
    } catch (const InvalidInputException& e) {
        std::cerr << "Ошибка ввода: " << e.what() << std::endl;
        return 1; // Завершение программы с ошибкой
    } catch (const std::runtime_error& e) {
        std::cerr << "Ошибка вычисления: " << e.what() << std::endl;
        return 1; // Завершение программы с ошибкой
    }

    // Если данные введены корректно, продолжаем дальше
    std::cout << "По какому полю сортировать? (1 - по ID, 2 - по средней температуре): ";
    int choice;
    std::cin >> choice;

    manager.sortSensors(choice);
    manager.printSensors();

    return 0; // Успешное завершение программы
}

