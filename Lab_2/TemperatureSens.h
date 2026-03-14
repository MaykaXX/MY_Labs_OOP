//
// Created by hwang on 14.03.2026.
//

#ifndef UNTITLED_TEMPERATURESENS_H
#define UNTITLED_TEMPERATURESENS_H
#include "Sensor.h"


class TemperatureSens: public Sensor {
    public:
    TemperatureSens(int id);
    double read_value() override;
    double convertCtoF() const;
};


#endif //UNTITLED_TEMPERATURESENS_H