//
// Created by hwang on 14.03.2026.
//

#include "PressureSens.h"

PressureSens::PressureSens(int id) {
    this->id = id;
    type = "Pressure";
    lastvalue = 0;
}

double PressureSens::read_value() {
    lastvalue = 950 + rand() % 101;
    history.emplace_back(lastvalue, id , type);
    return lastvalue;
}
