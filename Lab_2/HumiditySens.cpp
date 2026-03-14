//
// Created by hwang on 14.03.2026.
//

#include "HumiditySens.h"

HumiditySens::HumiditySens(int id) {
    this->id = id;
    type = "Humidity";
    lastvalue = 0;
}

double HumiditySens::read_value() {
    lastvalue = rand() % 101;
    history.emplace_back(lastvalue, id , type);
    return lastvalue;
}
