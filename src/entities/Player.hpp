#include "Entity.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player : protected Entity {

    static Player *instance;

    public:
    static Player *getInstance(){
        if(!instance)
            instance = new Player();
        return instance;
    }
        
};

#endif