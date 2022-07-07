#include "game.hpp"
#include "Player.hpp"
#include <iostream>
Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Game"), mPlayer() {
    this->mPlayer = Player::getInstance();
}

Game* Game::instance = NULL;
Game* Game::getInstance() {
    if (instance == NULL) {
        instance = new Game();
        std::cout << "Creando game..." << std::endl;
    }
    return instance;
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TIME_PER_FRAME) {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            processEvents();
            update(TIME_PER_FRAME);
        }
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                this->mPlayer->handlePlayerInputPress(event.key.code);
                break;
            case sf::Event::KeyReleased:
                this->mPlayer->handlePlayerInputRelease(event.key.code);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Game::update(sf::Time deltaTime) { mPlayer->update(TIME_PER_FRAME); }

void Game::render() {
    mWindow.clear();
    mWindow.draw(mPlayer->getSprite());
    mWindow.display();
}
