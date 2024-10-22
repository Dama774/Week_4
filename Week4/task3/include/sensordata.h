#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include <string>
#include <stdexcept>

const int MAX_SENSORS = 100;
const int MAX_INPUT_LENGTH = 512;

struct SensorData {
    int id;    
    double sum;
    int count;

    double average() const {
        if (count == 0) {
            throw std::runtime_error("Деление на ноль: отсутствуют данные для расчета среднего.");
        }
        return sum / count;
    }
};

class SensorManager {
public:
    SensorManager() : sensorCount(0) {}

    void calculateAverageTemperatures(const std::string& input);
    void sortSensors(int choice);
    void printSensors() const;

private:
    SensorData sensors[MAX_SENSORS];
    int sensorCount;

    void updateSensorData(int id, double temperature);
};

#endif // SENSOR_DATA_H

