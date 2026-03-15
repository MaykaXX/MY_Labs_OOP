#include "Measurement.h"
#include <ostream>
#include <iostream>
#include <string>

#include "../termcolor/termcolor.hpp"

Measurement::Measurement() : Measurement("00.00.0000", 0.0, 0, "none") {
};

Measurement::Measurement(double value, int sensor_id, std::string type_sensor) : Measurement(
    "00.00.0000", value, sensor_id, type_sensor) {
};

Measurement::Measurement(std::string data, double value, int sensor_id, std::string type_sensor) : data(data),
    value(value),
    sensor_id(sensor_id), type_sensor(type_sensor) {
};


// Measurement::Measurement(const Measurement &other) {
//     data = other.data;
//     value = other.value;
//     sensor_id = other.sensor_id;
//     type_sensor = other.type_sensor;
// }
//
// Measurement::Measurement(Measurement &&other) noexcept {
//     data = std::move(other.data);
//     value = other.value;
//     sensor_id = other.sensor_id;
//     type_sensor = std::move(other.type_sensor);
// }
//
// Measurement &Measurement::operator=(const Measurement &other) {
//     if (this != &other) {
//         data = other.data;
//         value = other.value;
//         sensor_id = other.sensor_id;
//         type_sensor = other.type_sensor;
//     }
// }

Measurement::~Measurement() {
    std::cout << "Measurement destructor called." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Measurement &measurement) {
    out << "Info: " << termcolor::bright_yellow <<measurement.sensor_id <<termcolor::reset << ", " << measurement.value << ", " << measurement.type_sensor << ", " <<
            measurement.data << std::endl;
    return out;
}


// void Measurement::print() const {
//     std::cout << "Info: " << this->data << ", " << this->value << ", " << this->sensor_id << std::endl;
// };

double Measurement::getValue() const {
    return value;
}

int Measurement::getSensorId() const {
    return sensor_id;
}

void Measurement::setData(std::string data) {
    this->data = data;
}
