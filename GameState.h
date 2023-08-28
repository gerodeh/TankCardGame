#ifndef GameStates_H
#define GameStates_H

#include "Gui.h"
#include "Game.h"

#include "SFML/Graphics.hpp"

class GameState
{
public:
    Game* game;
    sf::Color backgrdColor = sf::Color::Black;

    virtual void draw (const float dt) = 0;
    virtual void update (const float dt) = 0;
    virtual void handleInput (const float dt) = 0;

    virtual ~GameState();
};

#endif
