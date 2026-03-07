#include "Sensor.h"
#include <iostream>
#include <ostream>
#include <string>

int Sensor::sensor_count = 0;


Sensor::Sensor() : Sensor(0, "None", 0.0) {
    sensor_count++;
};

Sensor::Sensor(int id) : Sensor(id, "Temperature", 0.0) {
    sensor_count++;
};

Sensor::Sensor(int id, std::string type, double lastvalue) : id(id), type(type), lastvalue(lastvalue) {
    sensor_count++;
};


Sensor::~Sensor() {
    // std::cout << "Sensor destroyed\n";
}

double Sensor::read_value() {
    lastvalue = (rand() % 400) / 10;
    //std::cout << lastvalue << std::endl;
    return lastvalue;
};

void Sensor::decrement_count_sensors() {
    if(sensor_count>0)
        sensor_count--;
}

int Sensor::get_id() const {
    return id;
};

std::string Sensor::get_type() const {
    return type;
};

double Sensor::get_lastvalue() const {
    return lastvalue;
};

int Sensor::get_sensor_count() {
    return sensor_count;
}


