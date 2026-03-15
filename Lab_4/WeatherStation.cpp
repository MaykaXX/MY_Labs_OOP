#include "WeatherStation.h"
#include "TemperatureSens.h"
#include "HumiditySens.h"
#include "PressureSens.h"
#include "Sensor.h"
#include <iostream>
#include <string>

#include "../termcolor/termcolor.hpp"

WeatherStation::WeatherStation() : WeatherStation("Default station") {
    std::cout << "Default WeatherStation" << std::endl;
};

WeatherStation::WeatherStation(std::string name) : name(name) {
    std::cout << "WeatherStation (std::string name)" << name << std::endl;
};

WeatherStation::~WeatherStation() {
    for (auto s: sensors) {
        delete s;
    }
    sensors.clear();
    std::cout << "WeatherStation destructor" << std::endl;
};


void WeatherStation::add_temperature_sensor(int id) {
    sensors.push_back(new TemperatureSens(id));
}

void WeatherStation::add_humidity_sensor(int id) {
    sensors.push_back(new HumiditySens(id));
}

void WeatherStation::add_pressure_sensor(int id) {
    sensors.push_back(new PressureSens(id));
}

void WeatherStation::collect_data(std::string &date) {
    for (auto sensor: sensors) {
        sensor->read_value(date);
    }
};

void WeatherStation::show_Sensors() const {
    for (auto sensor: sensors) {
        std::cout << sensor->get_id() << ". " << sensor->get_type() << std::endl;
    }
};

void WeatherStation::show_history() const {
    for (auto sensor: sensors) {
        for (auto measurement: sensor->get_history()) {
            std::cout << measurement << std::endl;
        }
    }
};

double WeatherStation::calculate_average(const std::string type) const {
    double sum = 0;
    int count = 0;

    for (auto sensor: sensors) {
        if (sensor->get_type() == type) {
            for (auto measurement: sensor->get_history()) {
                sum += measurement.getValue();
                count++;
            }
        }
    }

    if (count == 0) {
        return 0;
    }

    return sum / count;
};

void WeatherStation::show_sensor_count() const {
    std::cout << termcolor::bright_green << "Sensor Count:" << Sensor::get_sensor_count() << termcolor::reset <<
            std::endl;
}

void WeatherStation::operator--() {
    if (!sensors.empty()) {
        delete sensors.back();
        sensors.pop_back();
        Sensor::decrement_count_sensors();

    }
}

void WeatherStation::operator-(int temp_id) {
    bool found = false;
    for (size_t i = 0; i < sensors.size(); i++) {
        if (sensors[i]->get_id() == temp_id) {
            std::cout << termcolor::bright_green << "Sensor " << sensors[i]->get_type() << " was removed." <<
                    termcolor::reset << std::endl;
            delete sensors[i];
            sensors.erase(sensors.begin() + i);
            Sensor::decrement_count_sensors();
            found = true;
            break;
        }
        if (!found) {
            std::cout << termcolor::bright_red << "Error! You dont have this sensor." << termcolor::reset << std::endl;
        }
    }
}
