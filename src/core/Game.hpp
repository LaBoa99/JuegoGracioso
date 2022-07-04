#include <SFML/Graphics.hpp>

#ifndef GAME_HPP
#define GAME_HPP

/*
    TODA ESTA CLASE SE REFACTORIZARA PARA SEPARAR LAS FUNCIONALIDADES DE UN PLAYER A SU
    RESPECTIVA CLASE
*/
class Game {
   private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;
    sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

    // Inicializa un arrego  [0, 0, 0, 0] siendo W, D, S, A
    bool edges[4];

   public:
    Game() : mWindow(sf::VideoMode(640, 480), "SFML Game"), mPlayer() {
        this->mPlayer.setRadius(40.f);
        this->mPlayer.setPosition(100.f, 100.f);
        this->mPlayer.setFillColor(sf::Color::Red);
    }

    void run(){
        sf::Clock clock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        while (this->mWindow.isOpen()){
            this->processEvents();
            timeSinceLastUpdate += clock.restart();
            while(timeSinceLastUpdate > this->TIME_PER_FRAME){
                timeSinceLastUpdate -= this->TIME_PER_FRAME;
                processEvents();
                update(this->TIME_PER_FRAME);
            }
            this->render();
        }
    }

   private:
    void processEvents(){
        sf::Event event;
        while(this->mWindow.pollEvent(event)){
            switch(event.type){
                case sf::Event::KeyPressed:
                    this->handlePlayerInput(event.key.code, true);
                    break;
                case sf::Event::KeyReleased:
                    this->handlePlayerInput(event.key.code, false);
                    break;
                case sf::Event::Closed:
                    this->mWindow.close();
                    break;
            }
        }
    }

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
        if (key == sf::Keyboard::W) this->edges[0] = isPressed;
        if (key == sf::Keyboard::D) this->edges[1] = isPressed;
        if (key == sf::Keyboard::S) this->edges[2] = isPressed;
        if (key == sf::Keyboard::A) this->edges[3] = isPressed;
    }

    void update(sf::Time deltaTime){
        sf::Vector2f movement(0.f, 0.f);
        if(this->edges[0]) movement.y -= 10.f;
        if(this->edges[1]) movement.x += 10.f;
        if(this->edges[2]) movement.y += 10.f;
        if(this->edges[3]) movement.x -= 10.f;

        this->mPlayer.move(movement * deltaTime.asSeconds());
    }

    void render(){
        this->mWindow.clear();
        this->mWindow.draw(mPlayer);
        this->mWindow.display();
    }

};

#endif