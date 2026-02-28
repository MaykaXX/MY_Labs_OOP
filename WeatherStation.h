#ifndef UNTITLED_WEATHERSTATION_H
#define UNTITLED_WEATHERSTATION_H
#include <string>
#include <vector>

#include "Measurement.h"
#include "Sensor.h"

class WeatherStation {
private:
    std::string name;
    std::vector<Sensor>;
    std::vector<Measurement>;

public:
    void add_Sensor();

    Measurement collest_data();

    void show_Sensors();

    void show_history();

    double calculate_average();
};


#endif //UNTITLED_WEATHERSTATION_H
