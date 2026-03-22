//
// Created by hwang on 22.03.2026.
//

#include "HumidityWorker.h"

#include <iostream>

void HumidityWorker::describe() const {
    std::cout << "Role: Humidity worker" << std::endl;
}

std::string HumidityWorker::get_sensorType() const {
    return "Humidity";
}

HumidityWorker::~HumidityWorker() {
    std::cout << "HumidityWorker destructor" << std::endl;
}
