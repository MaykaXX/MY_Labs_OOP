#ifndef UNTITLED_EXAMPLE_H
#define UNTITLED_EXAMPLE_H
#include <string>
#include <vector>
#include "Measurement.h"

class Sensor {
protected:
    int id;
    std::string type;
    double lastvalue;
    std::vector<Measurement> history;
    static int sensor_count;

public:
    Sensor();

    //Sensor(int id);

    Sensor(int id, std::string type, double lastvalue);

    Sensor(const Sensor& other);
    Sensor(Sensor&& other) noexcept;
    Sensor& operator=(const Sensor& other);

    virtual ~Sensor();

    virtual double read_value()=0;

    static void decrement_count_sensors();

    int get_id() const;

    std::string get_type() const;

    double get_lastvalue() const;

    const std::vector<Measurement>& get_history() const;

    static int get_sensor_count();

    void operator--(int id);
};


#endif //UNTITLED_EXAMPLE_H
