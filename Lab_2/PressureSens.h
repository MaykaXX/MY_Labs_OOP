//
// Created by hwang on 14.03.2026.
//

#ifndef UNTITLED_PRESSURESENS_H
#define UNTITLED_PRESSURESENS_H
#include "EnvironmentalSensor.h"
#include "Sensor.h"

class PressureSens : public EnvironmentalSensor {
public:
    PressureSens(int id);

    double read_value(std::string &date) override;
};


#endif //UNTITLED_PRESSURESENS_H
