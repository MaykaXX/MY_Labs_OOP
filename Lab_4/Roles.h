#ifndef UNTITLED_ROLES_H
#define UNTITLED_ROLES_H
#include <string>


class Roles {
public:
   void describe_static() const; //статична прив'язка
   virtual void describe() const;

   virtual std::string get_sensorType() const;

   virtual ~Roles();
};


#endif //UNTITLED_ROLES_H
