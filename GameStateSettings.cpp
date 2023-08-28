#include "GameStateSettings.h"

//
///
///
///Settings
///
///
//


GameStateSettings::GameStateSettings (Game* game)
{
    this->game = game;

    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());

    this->view.setSize(pos);

    pos *= 0.5f;

    this->view.setCenter(pos);

    labels.push_back(new Label(&this->game->window, sf::Text(L"Настройки", this->game->font, 30), GuiComponent::componentAlignment::Top, GuiComponent::componentAlignment::Top, sf::Color::Black));
    labels[0]->Move(0, 20);
    labels[0]->NAME = "TopLabel";
    buttons.push_back(new Button(&this->game->window, sf::Text(L"Вернуться", this->game->font, 35), GuiComponent::componentAlignment::Bottom, GuiComponent::componentAlignment::Bottom, sf::Vector2f(300, 50), sf::Color(255,255,255)));
    buttons[0]->NAME = "Return";
    buttons[0]->Move(0, -20);
    buttons.push_back(new Button(&this->game->window, sf::Text(L"Полноэкранный режим", this->game->font, 20), GuiComponent::componentAlignment::Center, GuiComponent::componentAlignment::Center, sf::Vector2f(300, 50), sf::Color(255,255,255)));
    buttons[1]->NAME = "Fullscreen";
    buttons[1]->Move(0, 0);

    backgrdColor = sf::Color(237,119,41);
}

GameStateSettings::~GameStateSettings () { std::cout << "Destructor of GameStateSettings" << std::endl; }

void GameStateSettings::draw(const float dt)
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

void GameStateSettings::update (const float dt)
{
    this->view.setSize(this->game->window.getSize().x, this->game->window.getSize().y);
    this->view.setCenter(this->game->window.getSize().x *0.5f, this->game->window.getSize().y*0.5f);

    for (auto comp : labels)
    {
        if (comp->NAME == "TopLabel"){ comp->SetPosition(GuiComponent::componentAlignment::Top); comp->Move(0,20); }

    }
    for (auto comp : buttons)
    {
        if (comp->NAME == "Return") { comp->SetPosition(GuiComponent::componentAlignment::Bottom); comp->Move(0,-20); }
        if (comp->NAME == "Fullscreen") { comp->SetPosition(GuiComponent::componentAlignment::Center); comp->Move(0,0); }
    }
    ///Button Highlight
    for (auto comp : buttons)
    {
        if (comp->GetButtonRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
        {
            comp->SetFillColor(sf::Color(210,210,210));
            continue;
        }
        comp->SetFillColor(sf::Color(255, 255, 255));
    }
}

void GameStateSettings::handleInput (const float dt)
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
                std::cout << this->game->window.getSize().x << " " << this->game->window.getSize().y << std::endl;
                break;

            case sf::Event::MouseButtonReleased:
                for (auto comp : buttons)
                {
                    if (comp->GetButtonRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
                    {
                        if (comp->NAME == "Return"){ this->game->popState();}
                        if (comp->NAME == "Fullscreen" && this->game->fullscreen == false) setFullscreenMode();
                        else if (comp->NAME == "Fullscreen" && this->game->fullscreen == true) cancelFullscreenMode();
                    }
                }
                break;


        }
    }
}

void GameStateSettings::setFullscreenMode()
{
    this->game->window.close();
    this->game->window.create(sf::VideoMode(this->game->scrXmetric, this->game->scrYmetric), "Tank Card Game", sf::Style::Fullscreen);
    this->game->fullscreen = true;
    this->game->window.setFramerateLimit(60);
}

void GameStateSettings::cancelFullscreenMode()
{
    this->game->window.close();
    this->game->window.create(sf::VideoMode(950, 750), "Tank Card Game", sf::Style::Default);
    this->game->fullscreen = false;
    this->game->window.setFramerateLimit(60);
}

