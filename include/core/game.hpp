#ifndef GAME_HPP
#define GAME_HPP


#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Subject.hpp"

/*
    TODA ESTA CLASE SE REFACTORIZARA PARA SEPARAR LAS FUNCIONALIDADES DE UN
   PLAYER A SU RESPECTIVA CLASE
*/
class Game {
   private:
    sf::RenderWindow mWindow;
    sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

   public:
    Player* mPlayer;

   private:
    static Game* instance;
    Game();

   public:
    static Game* getInstance();
    void run();

   private:
    void processEvents();

    void update(sf::Time deltaTim);
    void render();
};

#endif // GAME_HPP
