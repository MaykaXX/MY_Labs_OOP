#include "Measurement.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <string>

Measurement::Measurement() : Measurement("00.00.0000", 0.0, 0) {
};

Measurement::Measurement(double value) : data("00.00.0000"), value(value), sensor_id(0) {
};

Measurement::Measurement(std::string data, double value, int sensor_id) : data(data), value(value),
                                                                          sensor_id(sensor_id) {
};

Measurement::~Measurement() {
    //std::cout << "Measurement destructor called." << std::endl;
}

void Measurement::print() const {
    std::cout << "Info: " << data << ", " << value << ", " << sensor_id << std::endl;
};

double Measurement::getValue() const {
    return value;
}

int Measurement::getSensorId() const {
    return sensor_id;
}
