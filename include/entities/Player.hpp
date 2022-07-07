#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Player : public Entity
{
    public:
        virtual ~Player() override;
        static Player* getInstance();

        void handlePlayerInputPress(sf::Keyboard::Key key);
        void handlePlayerInputRelease(sf::Keyboard::Key key);

        void update(sf::Time &deltaTime) override;
        void draw() override;
        void move() override;

    protected:
        static Player* instance;

    private:
        Player();

        bool edges[4];

};

#endif // PLAYER_HPP
