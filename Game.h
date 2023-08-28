#ifndef Game_H
#define Game_H

class GameState;

#include "TextureManager.h"

#include <vector>
#include <SFML/Graphics.hpp>
#include <windows.h>

class Game
{
    void loadalltextures();
public:
    TextureManager texturemanager;

    unsigned int standartWsizeX = 950; //950
    unsigned int standartWsizeY = 750; //750

    unsigned int scrXmetric;
    unsigned int scrYmetric;

    sf::Font font;
    sf::Font fontforCards;

    bool fullscreen = false;

    sf::String language = "Russian";

    std::vector<GameState*> states;

    sf::RenderWindow window;

    void pushState (GameState* state);

    void popState ();

    void changeState (GameState* state);

    GameState* peekState ();

    void gameLoop();

    Game();

    ~Game();
};

#endif // Game_H
