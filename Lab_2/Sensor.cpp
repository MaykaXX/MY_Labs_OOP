#include "Sensor.h"
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <ctime>

Sensor::Sensor() : Sensor(0, "None", 0.0) {
};

Sensor::Sensor(int id, std::string type, double lastvalue) : id(id), type(type), lastvalue(lastvalue) {
};

Sensor::Sensor(int id) : id(id), type("Temperature"), lastvalue(0.0) {
};

Sensor::~Sensor() {
    // std::cout << "Sensor destroyed\n";
}

double Sensor::read_value() {
    lastvalue = (rand() % 400) / 10;
    //std::cout << lastvalue << std::endl;
    return lastvalue;
};

int Sensor::get_id() const {
    return id;
};

std::string Sensor::get_type() const {
    return type;
};

double Sensor::get_lastvalue() const {
    return lastvalue;
};


