
#include "Bobby.h"

#include <iostream>
#include <ostream>

#include "../termcolor/termcolor.hpp"

Bobby::Bobby(std::string name, Roles &role) : name(name), role(&role) {
    std::cout << "Bobby() created" << std::endl;
}

std::string Bobby::get_name() const {
    return name;
}

void Bobby::introduce() const {
    std::cout << termcolor::bright_yellow << "Hey, I'm " << name << ", I work with " << role->get_sensorType() <<
            " sensors" << termcolor::reset << std::endl;
}

void Bobby::change_role(Roles &newrole) {
    role = &newrole;
    std::cout << name << " change role to: " << role->get_sensorType() << std::endl;
}

Bobby::~Bobby() {
    std::cout << "Bobby() destroyed" << std::endl;
}
