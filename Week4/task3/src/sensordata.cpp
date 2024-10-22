#include "sensordata.h"
#include "invalidinputexception.h"
#include <sstream>
#include <iostream>
#include <iomanip>

void SensorManager::updateSensorData(int id, double temperature) {
    for (int i = 0; i < sensorCount; ++i) {
        if (sensors[i].id == id) {
            sensors[i].sum += temperature;
            sensors[i].count++;
            return;
        }
    }

    // Если не найден, добавляем новый датчик
    if (sensorCount < MAX_SENSORS) {
        sensors[sensorCount++] = {id, temperature, 1};
    }
}

void SensorManager::calculateAverageTemperatures(const std::string& input) {
    if (input.empty()) {
        // Если входная строка пустая, бросаем исключение
        throw std::runtime_error("Деление на ноль: отсутствуют данные для расчета среднего.");
    }
    
    std::istringstream stream(input);
    std::string token;

    while (std::getline(stream, token, '@')) {
        if (token.length() < 3) {
            throw InvalidInputException("Некорректные данные: " + token);
        }

        int id = std::stoi(token.substr(0, 2)); // Извлекаем двузначный ID
        double temperature;

        try {
            temperature = std::stod(token.substr(2)); // Получаем температуру
        } catch (const std::invalid_argument&) {
            throw InvalidInputException("Некорректное значение температуры: " + token.substr(2));
        } catch (const std::out_of_range&) {
            throw InvalidInputException("Температура выходит за допустимые пределы: " + token.substr(2));
        }

        // Проверка на допустимые пределы температуры
        if (temperature < -50.0 || temperature > 50.0) {
            throw InvalidInputException("Температура должна быть в диапазоне от -50 до +50: " + std::to_string(temperature));
        }

        updateSensorData(id, temperature);
    }

    // Проверяем, были ли добавлены данные
    if (sensorCount == 0) {
        throw std::runtime_error("Деление на ноль: отсутствуют данные для расчета среднего.");
    }
}

void SensorManager::sortSensors(int choice) {
    for (int i = 0; i < sensorCount - 1; ++i) {
        for (int j = i + 1; j < sensorCount; ++j) {
            bool condition = (choice == 1) ? (sensors[i].id > sensors[j].id)
                                            : (sensors[i].average() > sensors[j].average());
            if (condition) {
                std::swap(sensors[i], sensors[j]);
            }
        }
    }
}

void SensorManager::printSensors() const {
    for (int i = 0; i < sensorCount; ++i) {
        std::cout << sensors[i].id << " " << std::fixed << std::setprecision(1) << sensors[i].average() 
                  << std::endl;
    }
}

