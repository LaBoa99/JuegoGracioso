#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include "IObject.hpp"

class Entity : public IObject
{
    public:
        Entity(float speed = 200, float hp = 100, std::string = "Entity") : IObject(), mTexture(), mSprite() {};
        virtual ~Entity() {};

        //Functions
        virtual void update(sf::Time& deltaTime) = 0;

        float addVelocity(bool isMoving){
            if(this->velocity < this->MAX_VEL){
                this->velocity += this->acceleration;
            }
        }

        float reduceVelocity(bool isMoving){
            if(this->velocity < -this->MAX_VEL){
                this->velocity -= this->acceleration;
            }
        }

        float updateVelocity(bool isMoving){
            if(isMoving == false){
                this->acceleration -= 1;
            }
        }

        virtual void draw() = 0;
        virtual void move() = 0;
        //Getters
        inline sf::Sprite getSprite() { return this->mSprite; }

    public:
        float speed, velocity = 0, acceleration = 5;
        float MAX_VEL = 500, MAX_ACCELERATION = 10;
        int hp;

        std::string name;

        sf::Texture mTexture;
        sf::Sprite mSprite;


    private:
};


#endif // ENTITY_HPP
