#include "Roles.h"

#include <iostream>

void Roles::describe_static() const {
    std::cout << "[Static] Role: base worker\n";
}

void Roles::describe() const {
    std::cout << "Role: generic worker\n";
}

std::string Roles::get_sensorType() const {
    return "none";
}

Roles::~Roles() {
    std::cout << "Role destructor\n";
}
