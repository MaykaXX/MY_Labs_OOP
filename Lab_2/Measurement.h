#ifndef UNTITLED_MEASUREMENT_H
#define UNTITLED_MEASUREMENT_H
#include <string>

#include "Sensor.h"

class Measurement {
private:
    std::string data;
    double value;
    int sensor_id;

public:
    Measurement();

    Measurement(double value);

    Measurement(std::string data, double value, int sensor_id);

    ~Measurement();

    void print() const;

    double getValue() const;

    int getSensorId() const;
};


#endif //UNTITLED_MEASUREMENT_H
