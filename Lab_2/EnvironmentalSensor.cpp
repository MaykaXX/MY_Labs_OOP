#include "EnvironmentalSensor.h"

EnvironmentalSensor::EnvironmentalSensor(int id, std::string type, std::string unit) : Sensor(id, type), unit(unit) {
}

std::string EnvironmentalSensor::get_unit() {
    return unit;
}
