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

    void show_Sensors() const;

    void show_history() const;

    double calculate_average(const std::string type) const;

    void show_sensor_count() const;
};


#endif //UNTITLED_WEATHERSTATION_H
