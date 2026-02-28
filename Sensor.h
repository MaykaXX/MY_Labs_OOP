#ifndef UNTITLED_EXAMPLE_H
#define UNTITLED_EXAMPLE_H
#include <string>

class Sensor {
private:
    int id;
    std::string type;
    double lastvalue;

public:
    Sensor();

    Sensor(int id);

    Sensor(int id, std::string type, double lastvalue);

    double read_value() const;

    int get_id() const;

    std::string get_type() const;

    double get_lastvalue() const;
};


#endif //UNTITLED_EXAMPLE_H
