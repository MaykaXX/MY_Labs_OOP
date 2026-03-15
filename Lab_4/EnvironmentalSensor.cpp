#include "EnvironmentalSensor.h"
#include <iostream>

EnvironmentalSensor::EnvironmentalSensor(int id, std::string type, std::string unit) : Sensor(id, type), unit(unit) {
    std::cout << "EnvironmentalSensor was called" << std::endl;
}

std::string EnvironmentalSensor::get_unit() {
    return unit;
}
