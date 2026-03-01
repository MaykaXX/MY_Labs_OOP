#ifndef UNTITLED_WEATHERSTATION_H
#define UNTITLED_WEATHERSTATION_H
#include <string>
#include <vector>

#include "Measurement.h"
#include "Sensor.h"

class WeatherStation {
private:
    std::string name;
    std::vector<Sensor> sensors;
    std::vector<Measurement> measurements;

public:
    WeatherStation();

    WeatherStation(std::string name);

    ~WeatherStation();

    void add_Sensor(int id, std::string type);

    void collest_data();

    void show_Sensors();

    void show_history();

    double calculate_average(const std::string type);
};


#endif //UNTITLED_WEATHERSTATION_H
