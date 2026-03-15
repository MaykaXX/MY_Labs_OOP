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

    Measurement(double value, int sensor_id, std::string type_sensor);

    Measurement(std::string data, double value, int sensor_id, std::string);

    //Measurement(const Measurement &other);

    //Measurement(Measurement &&other) noexcept;

    //Measurement &operator=(const Measurement &other);

    ~Measurement();


    // void print() const;

    friend std::ostream &operator<<(std::ostream &cout, const Measurement &measurement);

    double getValue() const;

    int getSensorId() const;

    std::string getTypeSensor() const;

    void setData(std::string data);
};


#endif //UNTITLED_MEASUREMENT_H
