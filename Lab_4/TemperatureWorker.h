#ifndef UNTITLED_TEMPERATUREWORKER_H
#define UNTITLED_TEMPERATUREWORKER_H
#include <string>
#include "Roles.h"


class TemperatureWorker final: public Roles {
public:
    void describe() const override;

    std::string get_sensorType() const override;

    ~TemperatureWorker();
};


#endif //UNTITLED_TEMPERATUREWORKER_H
