//
// Created by hwang on 14.03.2026.
//

#include "TemperatureSens.h"


TemperatureSens::TemperatureSens(int id){
    this->id = id;
    type = "Temperature";
    lastvalue = 0;
}

double TemperatureSens::read_value() {
    lastvalue = rand() % 50;
    history.emplace_back(lastvalue, id, type);
    return lastvalue;
}

double TemperatureSens::convertCtoF() const {
    return lastvalue * 9.0/5.0+32;
}
