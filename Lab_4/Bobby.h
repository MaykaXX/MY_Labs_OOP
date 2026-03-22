#ifndef UNTITLED_BOBBY_H
#define UNTITLED_BOBBY_H
#include "Human.h"
#include "Roles.h"


class Bobby : public Human {
private:
    std::string name;
    Roles * role;
public:
    Bobby(std::string name, Roles & role);

    std::string get_name() const override;

    void introduce() const override;

    void change_role(Roles & newrole);


    ~Bobby();
};


#endif //UNTITLED_BOBBY_H