//
// Created by hwang on 14.03.2026.
//

#ifndef UNTITLED_TEMPERATURESENS_H
#define UNTITLED_TEMPERATURESENS_H
#include "EnvironmentalSensor.h"
#include "Sensor.h"


class TemperatureSens : public EnvironmentalSensor {
public:
    TemperatureSens(int id);

    double read_value(std::string &date) override;

    double convertCtoF() const;
};


#endif //UNTITLED_TEMPERATURESENS_H
