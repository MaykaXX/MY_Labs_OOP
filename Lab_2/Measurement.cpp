#include "Measurement.h"
#include <iostream>
#include <ostream>
#include <string>

Measurement::Measurement() : Measurement("00.00.0000", 0.0, 0) {
};

Measurement::Measurement(double value) : Measurement("00.00.0000", value, 0) {
};

Measurement::Measurement(std::string data, double value, int sensor_id) : data(data), value(value),
                                                                          sensor_id(sensor_id) {
};


Measurement::Measurement(const Measurement &other) {
    data = other.data;
    value = other.value;
    sensor_id = other.sensor_id;
}

Measurement::Measurement(Measurement &&other) {
    data = std::move(other.data);
    value = other.value;
    sensor_id = other.sensor_id;
}

Measurement::~Measurement() {
    //std::cout << "Measurement destructor called." << std::endl;
}

void Measurement::print() const {
    std::cout << "Info: " << this->data << ", " << this->value << ", " << this->sensor_id << std::endl;
};

double Measurement::getValue() const {
    return value;
}

int Measurement::getSensorId() const {
    return sensor_id;
}
