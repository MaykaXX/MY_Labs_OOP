
#include "TemperatureWorker.h"

#include <iostream>

void TemperatureWorker::describe() const {
    std::cout << "Role: Temperature worker" << std::endl;
}

std::string TemperatureWorker::get_sensorType() const {
    return "Temperature";
}

TemperatureWorker::~TemperatureWorker() {
    std::cout << "TemperatureWorker destructor" << std::endl;
}
