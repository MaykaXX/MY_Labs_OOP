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

public:
    static int sensor_count;

    Sensor();
    Sensor(int id, std::string type);

    Sensor(int id, std::string type, double lastvalue);

    Sensor(const Sensor &other);

    Sensor(Sensor &&other) noexcept;

    Sensor &operator=(const Sensor &other);

    virtual ~Sensor();

    virtual double read_value(std::string & date) =0;

    static void decrement_count_sensors();

    void addMeasurement(double value, std::string &date);

    int get_id() const;

    std::string get_type() const;

    double get_lastvalue() const;

    const std::vector<Measurement> &get_history() const;

    static int get_sensor_count();

    void operator--(int id);
};


#endif //UNTITLED_EXAMPLE_H
