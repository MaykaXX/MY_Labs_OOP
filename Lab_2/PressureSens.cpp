//
// Created by hwang on 14.03.2026.
//

#include "PressureSens.h"

#include <iostream>
#include <ostream>

PressureSens::PressureSens(int id) {
    this->id = id;
    type = "Pressure";
    unit = "hPa";
    std::cout << "PressureSens was called" << std::endl;
}

double PressureSens::read_value(std::string &date) {
    lastvalue = 950 + rand() % 101;
    addMeasurement(lastvalue, date);
    return lastvalue;
}
