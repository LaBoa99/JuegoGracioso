#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Entity.hpp"
#include "ResourceHolder.hpp"
#include "Textures.hpp"


Player::Player() : Entity(200, 100, "Player")
{
    std::cout<< "Creando usuario " << std::endl;
    ResourceHolder<sf::Texture, Textures::ID> resourceHolder;
    try{
        resourceHolder.load(Textures::John, "./resources/sprites/John.png");

    } catch(std::runtime_error& e){
        std::cout <<"Exception: " << e.what() << std::endl;
    }

    Entity::mSprite.setTexture(resourceHolder.get(Textures::John));
    Entity::mSprite.setPosition(100.f, 100.f);
}
Player* Player::instance = nullptr;
Player* Player::getInstance(){
    if(instance == nullptr){
        instance = new Player();
    }
    return instance;
}

void Player::update(sf::Time &deltaTime) {
    sf::Vector2f movement(0.f, 0.f);
    // W A S D
    this->
    std::cout << Entity::speed << std::endl;
    if(this->edges[0])
        movement.y -= Entity::speed ;
    if(this->edges[1])
        movement.y  += this->speed;
    if(this->edges[2])
        movement.x -= this->speed;
    if(this->edges[3])
        movement.x -= this->speed;

    Entity::mSprite.move(movement * deltaTime.asSeconds());
}

void Player::draw() {

}

void Player::handlePlayerInputPress(sf::Keyboard::Key key){
    // Se mantiene la aceleracion, la acelearcion puede cambiar de direccion
    if (key == sf::Keyboard::W) this->edges[0] = true;
    if (key == sf::Keyboard::A) this->edges[1] = true;
    if (key == sf::Keyboard::S) this->edges[2] = true;
    if (key == sf::Keyboard::D) this->edges[3] = true;
}

void Player::handlePlayerInputRelease(sf::Keyboard::Key key){
    // Se disminuye la aceleracion
    if (key == sf::Keyboard::W) this->edges[0] = false;
    if (key == sf::Keyboard::A) this->edges[1] = false;
    if (key == sf::Keyboard::S) this->edges[2] = false;
    if (key == sf::Keyboard::D) this->edges[3] = false;
}

void Player::move(){

}

Player::~Player()
{
    //dtor
}
