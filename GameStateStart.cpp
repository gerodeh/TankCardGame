#include "GameStateStart.h"

//
///
///
///Main menu
///
///
//

void GameStateStart::draw (const float dt)
{
    this->game->window.setView(view);
    for (auto comp : this->labels)
    {
        comp->Render(this->game->window);
    }
    for (auto comp : this->buttons)
    {
        comp->Render(this->game->window);
    }
}

void GameStateStart::update (const float dt)
{
    this->view.setSize(this->game->window.getSize().x, this->game->window.getSize().y);
    this->view.setCenter(this->game->window.getSize().x *0.5f, this->game->window.getSize().y*0.5f);

    ///constant save of GUI position
    for (auto comp : labels)
    {
        if (comp->NAME == "TopLabel"){ comp->SetPosition(GuiComponent::componentAlignment::Center); comp->Move(0,-160); }
    }
    for (auto comp : buttons)
    {
        if (comp->NAME == "Start") { comp->SetPosition(GuiComponent::componentAlignment::Center); }
        if (comp->NAME == "Settings") { comp->SetPosition(GuiComponent::componentAlignment::Center); comp->Move(0, 50); }
        if (comp->NAME == "Tutorial") { comp->SetPosition(GuiComponent::componentAlignment::Center); comp->Move(0, 100); }
        if (comp->NAME == "Exit") { comp->SetPosition(GuiComponent::componentAlignment::Center); comp->Move(0, 150); }
        if (comp->NAME == "Language") { comp->SetPosition(GuiComponent::componentAlignment::BottomRight);  }
    }

    ///Button Highlight
    for (auto comp : buttons)
    {
        if (comp->GetButtonRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
        {
            if (comp->NAME == "Exit"){
                comp->SetFillColor(sf::Color(224,73,73));
                continue;
            }
            comp->SetFillColor(sf::Color(210, 210, 210));
                continue;
        }
        if (comp->NAME == "Exit")
        {
            comp->SetFillColor(sf::Color(180, 0, 0));
            continue;
        }
        comp->SetFillColor(sf::Color(255, 255, 255));
    }
}

void GameStateStart::handleInput (const float dt)
{
    sf::Event event;
    while (this->game->window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                game->window.close();
                break;

            case sf::Event::Resized:
                if (event.size.width >= this->game->standartWsizeX && event.size.height >= this->game->standartWsizeY)
                {
                    this->view.setSize(event.size.width, event.size.height);
                    this->view.setCenter(event.size.width*0.5f, event.size.height*0.5f);
                }
                else
                {
                    this->game->window.setSize(sf::Vector2u(this->game->standartWsizeX, this->game->standartWsizeY));
                    this->game->window.setPosition(sf::Vector2i((int)((this->game->scrXmetric*0.5f)-this->game->standartWsizeX*0.5f ), (int)((this->game->scrYmetric*0.5f)-this->game->standartWsizeY*0.5f )));
                    this->view.setCenter(sf::Vector2f(this->game->standartWsizeX*0.5f, this->game->standartWsizeY*0.5f));
                }
                break;

            case sf::Event::MouseButtonReleased:
                for (auto comp : buttons)
                {
                    if (comp->GetButtonRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
                    {
                        if (comp->NAME == "Start") { game->pushState(new GameStateCustomization(this->game)); }
                        if (comp->NAME == "Exit"){ game->window.close(); }
                        if (comp->NAME == "Settings"){ game->pushState(new GameStateSettings(this->game)); }
                        if (comp->NAME == "Tutorial"){ game->pushState(new GameStateTutorial(this->game)); }
                    }
                }
                break;
        }
    }
}

GameStateStart::GameStateStart (Game* game)
{
    this->game = game;

    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());

    this->view.setSize(pos);

    pos *= 0.5f;

    this->view.setCenter(pos);

    labels.push_back(new Label(&this->game->window, sf::Text("Tank Card Game", this->game->font, 45), Label::componentAlignment::Center, Label::componentAlignment::Center, sf::Color::Black, sf::Color::White, 3));
    labels[0]->NAME = "TopLabel";
    buttons.push_back(new Button(&this->game->window, sf::Text(L"Играть", this->game->font, 35), GuiComponent::componentAlignment::Center,GuiComponent::componentAlignment::Center, sf::Vector2f(300, 50)));
    buttons[0]->NAME = "Start";
    buttons.push_back(new Button(&this->game->window, sf::Text(L"Настройки", this->game->font, 35), GuiComponent::componentAlignment::Center,GuiComponent::componentAlignment::Center, sf::Vector2f(300, 50)));
    buttons[1]->NAME = "Settings";
    buttons.push_back(new Button(&this->game->window, sf::Text(L"Обучение", this->game->font, 35), GuiComponent::componentAlignment::Center,GuiComponent::componentAlignment::Center, sf::Vector2f(300, 50)));
    buttons[2]->NAME = "Tutorial";
    buttons.push_back(new Button(&this->game->window, sf::Text(L"Выход", this->game->font, 35), GuiComponent::componentAlignment::Center,GuiComponent::componentAlignment::Center, sf::Vector2f(300, 50), sf::Color(180,0,0)));
    buttons[3]->NAME = "Exit";
    buttons.push_back(new Button(&this->game->window, sf::Text(L"Rus", this->game->font, 25), GuiComponent::componentAlignment::BottomRight,GuiComponent::componentAlignment::BottomRight, sf::Vector2f(60, 50), sf::Color(180,0,0)));
    buttons[4]->NAME = "Language";

    backgrdColor = sf::Color(237,119,41);

}

GameStateStart::~GameStateStart () {}
