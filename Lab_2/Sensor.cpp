#include "Sensor.h"
#include <iostream>
#include <ostream>
#include <string>

int Sensor::sensor_count = 0;


Sensor::Sensor() : Sensor(0, "None", 0.0) {
    sensor_count++;
};

// Sensor::Sensor(int id) : Sensor(id, "Temperature", 0.0) {
//     sensor_count++;
// };


Sensor::Sensor(int id, std::string type, double lastvalue) : id(id), type(type), lastvalue(lastvalue) {
    sensor_count++;
};

Sensor::Sensor(const Sensor& other):
id(other.id),
type(other.type),
lastvalue(other.lastvalue),
history(other.history) {sensor_count++;}


Sensor::Sensor(Sensor &&other) noexcept :
id(other.id),
type(other.type),
lastvalue(other.lastvalue),
history(std::move(other.history)) {
    other.id = 0;
    other.lastvalue = 0;
}

Sensor& Sensor::operator=(const Sensor& other) {
    if (this != &other) {
        id = other.id;
        type = other.type;
        lastvalue = other.lastvalue;
        history = other.history;
    }
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


