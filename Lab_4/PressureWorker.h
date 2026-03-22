#ifndef UNTITLED_PRESSUREWORKER_H
#define UNTITLED_PRESSUREWORKER_H
#include <string>

#include "Roles.h"


class PressureWorker final: public Roles{
    public:
    void describe() const override;
    std::string get_sensorType() const override;
    ~PressureWorker();
};


#endif //UNTITLED_PRESSUREWORKER_H