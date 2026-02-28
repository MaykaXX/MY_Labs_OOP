#ifndef UNTITLED_MEASUREMENT_H
#define UNTITLED_MEASUREMENT_H
#include <string>

class Measurement {
private:
    std::string data;
    double value;
    int sensor_id;

public:
    Measurement();

    Measurement(double value);

    Measurement(std::string data, double value, int sensor_id);

    void print() const;

    std::string get_data() const;

    int get_sensor_id() const;
};


#endif //UNTITLED_MEASUREMENT_H
