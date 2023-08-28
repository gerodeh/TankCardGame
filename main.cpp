#include "Gui.h"
#include "GameStateStart.h"
#include "Game.h"

#include <SFML/Graphics.hpp>

int main()
{

    //sf::Font font;
    //font.loadFromFile("src/fonts/sfns-display-bold.ttf");
    //Label label(&app, sf::Text(L"РРіСЂР°С‚СЊ", font), Label::componentAlignment::Center, Label::componentAlignment::Center, sf::Color::White);
    Game game;

    game.pushState(new GameStateStart(&game));

    game.gameLoop();

    return EXIT_SUCCESS;
}
