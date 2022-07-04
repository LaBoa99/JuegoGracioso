#include <string>
#include "../utils/IObject.hpp"


#ifndef ENTITY_HPP
#define ENTITY_HPP
/*
    Una entidad puede:
    Moverse, verse e interactuar con ella 
*/
class Entity : public IObject {

    float speed;
    float hp;
    std::string name;
    

};

#endif