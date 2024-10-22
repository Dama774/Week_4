#include "converter.h"
#include <sstream>
#include <stdexcept>

void convertToDouble(const std::string &input, double &output) {
    std::istringstream iss(input);
    if (!(iss >> output)) {
        throw std::invalid_argument("невозможно преобразовать '" + input + "' в тип double.");
    }
}

void convertToInt(const std::string &input, int &output) {
    double temp;
    convertToDouble(input, temp);
    output = static_cast<int>(temp);
}

void convertToString(const double &input, std::string &output) {
    output = std::to_string(input);
}

