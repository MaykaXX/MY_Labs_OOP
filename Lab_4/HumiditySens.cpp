//
// Created by hwang on 14.03.2026.
//

#include "HumiditySens.h"

#include <iostream>
#include <ostream>

HumiditySens::HumiditySens(int id) {
    this->id = id;
    type = "Humidity";
    unit = "%";
    std::cout << "HumiditySens was called" << std::endl;
}

double HumiditySens::read_value(std::string &date) {
    lastvalue = rand() % 101;
    addMeasurement(lastvalue, date);
    return lastvalue;
}
