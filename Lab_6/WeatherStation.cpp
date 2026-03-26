#include "WeatherStation.h"

#include <fstream>

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
    load_sensor_from_file();
};

void WeatherStation::add_temperature_sensor(int id) {
    sensors.push_back(std::make_unique<TemperatureSens>(id));
    save_sensor_to_file();
}

void WeatherStation::add_humidity_sensor(int id) {
    sensors.push_back(std::make_unique<HumiditySens>(id));
    save_sensor_to_file();
}

void WeatherStation::add_pressure_sensor(int id) {
    sensors.push_back(std::make_unique<PressureSens>(id));
    save_sensor_to_file();
}

void WeatherStation::collect_data(std::string &date) {
    for (auto& sensor: sensors) {
        sensor->read_value(date);
    }
};

void WeatherStation::save_sensor_to_file() const {
    std::ofstream file("sensors_data.txt");

    if (!file) {
        throw "Error opening file for save sensors!";
    }

    for (const auto& sensor:sensors) {
        file << sensor->get_id() << " " << sensor->get_type() << std::endl;
    }
}

void WeatherStation::load_sensor_from_file() {
    std::ifstream file("sensors_data.txt");
    if (!file)
    {
        return;
    }

    int id;
    std::string type;
    while (file >> id>>type) {
        if (type=="Temperature")
            sensors.push_back(std::make_unique<TemperatureSens>(id));
        else if (type=="Humidity")
            sensors.push_back(std::make_unique<HumiditySens>(id));
        else if (type=="Pressure")
            sensors.push_back(std::make_unique<PressureSens>(id));
    }
}

void WeatherStation::log_action(const std::string & action) const {
    std::ofstream file("user_history.txt", std::ios::app);
    if (!file) {
        throw "Cannot open history file!";
    }

    file <<action <<std::endl;
}

void WeatherStation::show_Sensors() const {
    for (auto& sensor: sensors) {
        std::cout << sensor->get_id() << ". " << sensor->get_type() << std::endl;
    }
};

void WeatherStation::show_history() const {
    for (auto& sensor: sensors) {
        for (auto measurement: sensor->get_history()) {
            std::cout << measurement << std::endl;
        }
    }
};

double WeatherStation::calculate_average(const std::string type) const {
    double sum = 0;
    int count = 0;

    for (auto& sensor: sensors) {
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
    if (!sensors.empty())
    {
        sensors.pop_back();
        Sensor::decrement_count_sensors();
    }
    else
    {
       throw "Error: NO sensors left to delete!!";
    }
}

void WeatherStation::operator-(int temp_id) {
    bool found = false;
    for (auto it = sensors.begin(); it != sensors.end(); ++it) {
        if ((*it)->get_id() == temp_id) {
            std::cout << termcolor::bright_green << "Sensor " << (*it)->get_type() << " was removed." <<
                    termcolor::reset << std::endl;

            sensors.erase(it);
            Sensor::decrement_count_sensors();
            save_sensor_to_file();
            found = true;
            break;
        }
        if (!found) {
           throw "Error! You dont have this sensor.";
        }
    }
}
