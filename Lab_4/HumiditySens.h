//
// Created by hwang on 14.03.2026.
//

#ifndef UNTITLED_HUMIDITYSENS_H
#define UNTITLED_HUMIDITYSENS_H
#include "EnvironmentalSensor.h"
#include "Sensor.h"

class HumiditySens : public EnvironmentalSensor {
public:
    HumiditySens(int id);

    double read_value(std::string &date) override;
};


#endif //UNTITLED_HUMIDITYSENS_H
