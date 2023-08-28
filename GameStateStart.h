#ifndef GameStateStart_H
#define GameStateStart_H

#include "GameState.h"
#include "GameStateCustomization.h"
#include "GameStateSettings.h"
#include "GameStateTutorial.h"
#include "Gui.h"
#include "Game.h"

#include "SFML/Graphics.hpp"

///
///Main menu
///

class GameStateStart : public GameState
{
    sf::View view;

    std::vector<Label*> labels;
    std::vector<Button*> buttons;
public:

    virtual void draw (const float dt) override;

    virtual void update (const float dt) override;

    virtual void handleInput (const float dt) override;

    GameStateStart (Game* game);

    ~GameStateStart ();

};

#endif // GameStateStart_H
