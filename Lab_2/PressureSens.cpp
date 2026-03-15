//
// Created by hwang on 14.03.2026.
//

#include "PressureSens.h"

PressureSens::PressureSens(int id) {
    this->id = id;
    type = "Pressure";
    unit = "hPa";
}

double PressureSens::read_value(std::string &date) {
    lastvalue = 950 + rand() % 101;
    addMeasurement(lastvalue, date);
    return lastvalue;
}
