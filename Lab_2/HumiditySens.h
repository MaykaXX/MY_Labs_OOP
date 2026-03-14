//
// Created by hwang on 14.03.2026.
//

#ifndef UNTITLED_HUMIDITYSENS_H
#define UNTITLED_HUMIDITYSENS_H
#include "Sensor.h"

class HumiditySens : public Sensor {
    public:
    HumiditySens(int id);
    double read_value() override;
};


#endif //UNTITLED_HUMIDITYSENS_H