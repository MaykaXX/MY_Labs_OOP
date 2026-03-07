#ifndef UNTITLED_EXAMPLE_H
#define UNTITLED_EXAMPLE_H
#include <string>

class Sensor {
private:
    int id;
    std::string type;
    double lastvalue;
    static int sensor_count;

public:
    Sensor();

    Sensor(int id);

    Sensor(int id, std::string type, double lastvalue);

    ~Sensor();

    double read_value();

    static void decrement_count_sensors();

    int get_id() const;

    std::string get_type() const;

    double get_lastvalue() const;

    static int get_sensor_count();
};


#endif //UNTITLED_EXAMPLE_H
