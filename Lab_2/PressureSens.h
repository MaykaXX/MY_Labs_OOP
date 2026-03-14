//
// Created by hwang on 14.03.2026.
//

#ifndef UNTITLED_PRESSURESENS_H
#define UNTITLED_PRESSURESENS_H
#include "Sensor.h"

class PressureSens:public Sensor {
    public:
    PressureSens(int id);
    double read_value() override;
};


#endif //UNTITLED_PRESSURESENS_H