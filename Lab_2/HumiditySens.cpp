//
// Created by hwang on 14.03.2026.
//

#include "HumiditySens.h"

HumiditySens::HumiditySens(int id) {
    this->id = id;
    type = "Humidity";
    unit = "%";
}

double HumiditySens::read_value(std::string &date) {
    lastvalue = rand() % 101;
    addMeasurement(lastvalue, date);
    return lastvalue;
}
