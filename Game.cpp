#include "Game.h"
#include "GameState.h"
#include <iostream>
void Game::pushState(GameState* state)
{
    this->states.push_back(state);
    std::cout << "stack: " << states.size() << std::endl;
}

void Game::popState()
{
    this->states.pop_back();
}

void Game::changeState(GameState* state)
{
    if (!this->states.empty())
        popState();
    pushState(state);
}

GameState* Game::peekState()
{
    if (this->states.empty())
        return nullptr;
    return this->states[states.size()-1];
}

void Game::gameLoop()
{
    sf::Clock clock;
    while (this->window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if (this->peekState() == nullptr)
            continue;

        peekState()->handleInput(dt);
        peekState()->update(dt);


        this->window.clear(peekState()->backgrdColor);

        peekState()->draw(dt);

        this->window.display();
    }
}

void Game::loadalltextures()
{
    texturemanager.LoadTexture("src/textures/checkMark.png", "checkMark");
    texturemanager.LoadTexture("src/textures/crossMark.png", "crossMark");
    texturemanager.LoadTexture("src/textures/cards/T-34-76.png", "T-34-76");
    texturemanager.LoadTexture("src/textures/cards/T-34-85.png", "T-34-85");
    texturemanager.LoadTexture("src/textures/cards/SU-100.png", "SU-100");
    texturemanager.LoadTexture("src/textures/cards/IS-2.png", "IS-2");
    texturemanager.LoadTexture("src/textures/cards/MS-1.png", "MS-1");
    texturemanager.LoadTexture("src/textures/cards/LTvz38.png", "LT vz.38");
    texturemanager.LoadTexture("src/textures/cards/Tiger I.png", "TigerI");
    texturemanager.LoadTexture("src/textures/cards/Hetzer.png", "Hetzer");
    texturemanager.LoadTexture("src/textures/cards/TigerII.png", "TigerII");
    texturemanager.LoadTexture("src/textures/cards/PzIII.png", "Pz.III");
}

Game::Game()
{
    this->window.create(sf::VideoMode(standartWsizeX, standartWsizeY), "Tank Card Game", sf::Style::Default);

    this->window.setFramerateLimit(60);

    this->scrXmetric = GetSystemMetrics(SM_CXSCREEN);
    this->scrYmetric = GetSystemMetrics(SM_CYSCREEN);

    font.loadFromFile("src/fonts/sfns-display-bold.ttf");
    fontforCards.loadFromFile("src/fonts/arnamu.ttf");

    loadalltextures();
}

Game::~Game()
{
    std::cout << "pop of all states" << std::endl;
    while (!this->states.empty())
        popState();
    this->states.shrink_to_fit();
}

