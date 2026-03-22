#ifndef UNTITLED_HUMIDITYWORKER_H
#define UNTITLED_HUMIDITYWORKER_H
#include "Roles.h"


class HumidityWorker final : public Roles {
public:
    void describe() const override;

    std::string get_sensorType() const override;

    ~HumidityWorker();
};


#endif //UNTITLED_HUMIDITYWORKER_H
