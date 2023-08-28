#ifndef GameStateCustomization_H
#define GameStateCustomization_H

#include "GameState.h"
#include "Gui.h"
#include "Game.h"
#include "Card.h"
#include "GameStateBattle.h"

#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <map>

#include <cstdlib>
#include <ctime>
//#include <random>

///
///Deck Builder and difficulty
///

class GameStateCustomization : public GameState
{
    enum SceneNum
    {
        Main,
        FirstGeneralDeck,
        SecondGeneralDeck,
        FirstPlayerDeck, /// they are not realized
        SecondPlayerDeck, /// they are not realized
    };

    SceneNum currentScene;

    sf::View view;

    std::vector<std::vector<Card*>> generalcards; //vector of vectors of Cards for different pages 1 player
    std::vector<std::vector<Card*>> generalcards2; //vector of vectors of Cards for different pages 2 player
    std::vector<std::vector<Label*>> labels; //vector of vectors of Labels for different scenes in the same Game State
    std::vector<std::vector<Button*>> buttons; //vector of vectors of Buttons for different scenes in the same Game State

    void changeScene(GameStateCustomization::SceneNum newcurrentscene);

    int currentPage = 1;
    int maxPage = 1;
    int currentPage2 = 1;

    bool typeMode = false;
    bool scaleMode = false;
    bool AIchooseDeck = false;

    //bool scaleMode2 = false;

    void sortDeckByID(std::vector<Card*>& deck, int generaldecknum);

    void handleDeckSizeInput(sf::Event& event);

    void handleMouseBtnReleaseFirstGeneralDeck(sf::Event& event);
    void handleMouseBtnReleaseSecondGeneralDeck(sf::Event& event);

    void CreateGeneralCards(std::vector<std::vector<Card*>>& generalcards);

    bool CanStartBattle();

    void buildBotsDeck();

    int botdifficulty = 1;

    std::vector<Card*> deck1;
    std::vector<Card*> deck2;

    int maxDeckSize = 12;
    int maxPHealth = 30;

    bool playerIsBot = true;

public:

    virtual void draw (const float dt) override;

    virtual void update (const float dt) override;

    virtual void handleInput (const float dt) override;

    GameStateCustomization (Game* game);

    ~GameStateCustomization ();

};

#endif // GameStateCustomization_H
