#ifndef GameStateSettings_H
#define GameStateSettings_H

#include "GameState.h"
#include "Gui.h"
#include "Game.h"
#include "windows.h"

#include "SFML/Graphics.hpp"

///
///Settings
///

class GameStateSettings : public GameState
{
    sf::View view;

    std::vector<Label*> labels;
    std::vector<Button*> buttons;
public:

    virtual void draw (const float dt) override;

    virtual void update (const float dt) override;

    virtual void handleInput (const float dt) override;

    GameStateSettings(Game* game);

    ~GameStateSettings () override;

    void setFullscreenMode();
    void cancelFullscreenMode();
};

#endif // GameStateSettings_H
