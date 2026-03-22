#ifndef UNTITLED_HUMAN_H
#define UNTITLED_HUMAN_H
#include <string>
#include <vector>

#include "Roles.h"


class Human {
public:
    virtual std::string get_name() const = 0;

    virtual void introduce() const =0;

    virtual ~Human();
};


#endif //UNTITLED_HUMAN_H
