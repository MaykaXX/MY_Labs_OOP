#include "PressureWorker.h"

#include <iostream>

#include "../termcolor/termcolor.hpp"

void PressureWorker::describe() const {
    std::cout << "Role: Pressure worker" << std::endl;
}

std::string PressureWorker::get_sensorType() const {
    return "Pressure worker";
}

PressureWorker::~PressureWorker() {
    std::cout << "PressureWorker destructor" << std::endl;
}
