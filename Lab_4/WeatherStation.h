#ifndef UNTITLED_WEATHERSTATION_H
#define UNTITLED_WEATHERSTATION_H
#include <string>
#include <vector>
#include "Sensor.h"

class WeatherStation {
private:
    std::string name;
    std::vector<Sensor *> sensors;

public:
    WeatherStation();

    WeatherStation(std::string name);

    ~WeatherStation();

    void add_temperature_sensor(int id);

    void add_humidity_sensor(int id);

    void add_pressure_sensor(int id);

    void collect_data(std::string &date);

    void show_Sensors() const;
    void show_history() const;
    double calculate_average(const std::string type) const;
    void show_sensor_count() const;

    void operator--();

    void operator-(int id);
};


#endif //UNTITLED_WEATHERSTATION_H
