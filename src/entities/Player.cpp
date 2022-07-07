#include "Player.hpp"
#include "Entity.hpp"
#include <SFML/Graphics.hpp>

Player::Player() : Entity(100, 100, "Player")
{
    if (!Entity::mTexture.loadFromFile("./resources/sprites/John.png")) {
        std::cout << "No se pudo cargar la textura" << std::flush;
    }
    Entity::mSprite.setTexture(this->mTexture);
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
    // son pulsaciones del teclado (cuando se indica el movimiento) osea que esto aplica una aceleracion
    // W arriba
    if (this->edges[0]) {
        movement.y -= Entity::addVelocity(true);
    }
    // D derecha
    if (this->edges[1]) movement.x += 10;
    // S abajo
    if (this->edges[2]) {
       movement.y += Entity::reduceVelocity(true);
    }
    // A izquierda
    if (this->edges[3]) movement.x -= 10;

    Entity::mSprite.move(movement * deltaTime.asSeconds());
}

void Player::draw() {

}

void Player::handlePlayerInputPress(sf::Keyboard::Key key){
    // Se mantiene la aceleracion, la acelearcion puede cambiar de direccion
    if (key == sf::Keyboard::W) this->edges[0] = true;
    if (key == sf::Keyboard::D) this->edges[1] = true;
    if (key == sf::Keyboard::S) this->edges[2] = true;
    if (key == sf::Keyboard::A) this->edges[3] = true;
}

void Player::handlePlayerInputRelease(sf::Keyboard::Key key){
    // Se disminuye la aceleracion
    if (key == sf::Keyboard::W) this->edges[0] = false;
    if (key == sf::Keyboard::D) this->edges[1] = false;
    if (key == sf::Keyboard::S) this->edges[2] = false;
    if (key == sf::Keyboard::A) this->edges[3] = false;
}

void Player::move(){

}

Player::~Player()
{
    //dtor
}
