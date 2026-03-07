#include "WeatherStation.h"
#include "Sensor.h"
#include <iostream>
#include <string>

#include "../termcolor/termcolor.hpp"

WeatherStation::WeatherStation() : WeatherStation("Default station") {
};

WeatherStation::WeatherStation(std::string name) : name(name) {
};

WeatherStation::~WeatherStation() {
    // std::cout << "WeatherStation destructor" << std::endl;
};


void WeatherStation::add_Sensor(int id, std::string type) {
    sensors.push_back(Sensor(id, type, 0.0));
};

void WeatherStation::collect_data() {
    for (auto &sensor: sensors) {
        double value = sensor.read_value();

        measurements.push_back(Measurement("01.05.2015", value, sensor.get_id(), sensor.get_type()));
    }
};

void WeatherStation::show_Sensors() const {
    for (auto &sensor: sensors) {
        std::cout << sensor.get_id() << ". " << sensor.get_type() << std::endl;
    }
};

void WeatherStation::show_history() const {
    for (auto &measurement: measurements) {
       std::cout << measurement; // here is operator <<
    }
};

double WeatherStation::calculate_average(const std::string type) const {
    double sum = 0;
    int count = 0;

    for (auto &measurement: measurements) {
        int id = measurement.getSensorId();

        for (auto &sensor: sensors) {
            if (sensor.get_id() == id && sensor.get_type() == type) {
                sum += measurement.getValue();
                count++;
                break;
            }
        }
    }
    if (count == 0) {
        return 0;
    }

    return sum / count;

};

void WeatherStation::show_sensor_count() const {
    std::cout << termcolor::bright_green << "Sensor Count:" << Sensor::get_sensor_count() << termcolor::reset << std::endl;
}

void WeatherStation::operator--() {
    if (!sensors.empty()) {
        sensors.pop_back();
        Sensor::decrement_count_sensors();

    }
}
