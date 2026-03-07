#ifndef UNTITLED_MEASUREMENT_H
#define UNTITLED_MEASUREMENT_H
#include <string>


class Measurement {
private:
    std::string data;
    double value;
    int sensor_id;
    std::string type_sensor;

public:
    Measurement();

    Measurement(double value, std::string type_sensor);

    Measurement(std::string data, double value, int sensor_id, std::string type_sensor);

    Measurement(const Measurement &other);

    Measurement(Measurement &&other) noexcept;

    friend std::ostream &operator<<(std::ostream &cout, const Measurement &measurement);

    ~Measurement();


    // void print() const;

    double getValue() const;

    int getSensorId() const;
};


#endif //UNTITLED_MEASUREMENT_H
