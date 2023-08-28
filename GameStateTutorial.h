#ifndef GameStateTutorial_H
#define GameStateTutorial_H

#include "GameState.h"
#include "Gui.h"
#include "Game.h"

#include "SFML/Graphics.hpp"

///
///Tutorial
///

class GameStateTutorial : public GameState
{
    sf::View view;

    std::vector<Label*> labels;
    std::vector<Button*> buttons;
public:

    virtual void draw (const float dt) override;

    virtual void update (const float dt) override;

    virtual void handleInput (const float dt) override;

    GameStateTutorial (Game* game);

    ~GameStateTutorial ();
};

#endif // GameStateTutorial_H
