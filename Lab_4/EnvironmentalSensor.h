
#ifndef UNTITLED_ENVIRONMENTALSENSOR_H
#define UNTITLED_ENVIRONMENTALSENSOR_H
#include "Sensor.h"


class EnvironmentalSensor : public Sensor {
protected:
    std::string unit;

public:
    EnvironmentalSensor() = default;

    EnvironmentalSensor(int id, std::string type, std::string unit);

    std::string get_unit();
};


#endif //UNTITLED_ENVIRONMENTALSENSOR_H
