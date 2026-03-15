#include "TemperatureSens.h"
#include <iostream>

TemperatureSens::TemperatureSens(int id) {
    this->id = id;
    type = "Temperature";
    unit = "C";
    std::cout << "TemperatureSens was called" << std::endl;
}

double TemperatureSens::read_value(std::string &date) {
    lastvalue = rand() % 50;
    addMeasurement(lastvalue, date);
    return lastvalue;
}

double TemperatureSens::convertCtoF() const {
    return lastvalue * 9.0 / 5.0 + 32;
}
