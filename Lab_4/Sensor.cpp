#include "Sensor.h"
#include <iostream>
#include <ostream>
#include <string>

int Sensor::sensor_count = 0;


Sensor::Sensor() : Sensor(0, "None", 0.0) {
    std::cout << "default Sensor created" << std::endl;
};

// Sensor::Sensor(int id) : Sensor(id, "Temperature", 0.0) {
//     sensor_count++;
// };


Sensor::Sensor(int id, std::string type) : Sensor(id, type, 0.0) {
    std::cout << "Sensor created (int id, std::string type)" << std::endl;
}

Sensor::Sensor(int id, std::string type, double lastvalue) : id(id), type(type), lastvalue(lastvalue) {
    sensor_count++;
    std::cout << "Sensor created (int id, std::string type, double lastvalue) " << std::endl;
};

Sensor::Sensor(const Sensor &other) : id(other.id),
                                      type(other.type),
                                      lastvalue(other.lastvalue),
                                      history(other.history) {
    sensor_count++;
    std::cout << "Copy constructor of sensor" << std::endl;
}


Sensor::Sensor(Sensor &&other) noexcept : id(other.id),
                                          type(other.type),
                                          lastvalue(other.lastvalue),
                                          history(std::move(other.history)) {
    other.id = 0;
    other.lastvalue = 0;
    std::cout << "Move constructor of sensor" << std::endl;
}

Sensor &Sensor::operator=(const Sensor &other) {
    if (this != &other) {
        id = other.id;
        type = other.type;
        lastvalue = other.lastvalue;
        history = other.history;
    }
    std::cout << "Copy assignment of sensor" << std::endl;
    return *this;
}


Sensor::~Sensor() {
    std::cout << "Base Sensor destroyed\n";
    sensor_count--;
}

void Sensor::decrement_count_sensors() {
    if (sensor_count > 0)
        sensor_count--;
}

const std::vector<Measurement> &Sensor::get_history() const{
    return history;
}

void Sensor::addMeasurement(double value, std::string &date) {
    Measurement m(value, id, type);
    m.setData(date);
    history.push_back(m);
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


