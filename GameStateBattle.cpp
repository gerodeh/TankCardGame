#include "GameStateBattle.h"

//
///
///
///Battle
///
///
//

GameStateBattle::GameStateBattle(Game* game, std::vector<Card*>* deck1, std::vector<Card*>* deck2, int maxdecksize, bool playerIsBot, int maxPHealth)
{
    srand (time(NULL));

    this->game = game;

    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());

    this->view.setSize(pos);

    this->view.setCenter(pos.x*0.5f, pos.y*0.5f);

    backgrdColor = sf::Color(237,119,41);

    //if (maxdecksize < 8) this->maxdecksize = 8;
    //else this->maxdecksize = maxdecksize;

    this->playerIsBot = playerIsBot;
    this->maxPHealth = maxPHealth;

    health1P = maxPHealth;
    health2P = maxPHealth;

    labels.push_back(new Label(&this->game->window, sf::Text(L"WASD - передвижение\nкамерой\n\nC - центрирование\n\nКнопка выхода\nслева сверху\nвне зоны видимости", this->game->font, 10), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Left, sf::Color::Black, sf::Color::White, 3));
    labels[0]->NAME = "Hint";
    labels.push_back(new Label(&this->game->window, sf::Text(L"0", this->game->font, 25), GuiComponent::componentAlignment::BottomLeft, GuiComponent::componentAlignment::Center, sf::Color::Black, sf::Color::White, 3));
    labels[1]->NAME = "MainDeck";
    labels.push_back(new Label(&this->game->window, sf::Text(L"0", this->game->font, 25), GuiComponent::componentAlignment::BottomLeft, GuiComponent::componentAlignment::Center, sf::Color::Black, sf::Color::White, 3));
    labels[2]->NAME = "DiscardDeck";

    buttons.push_back(new Button(&this->game->window, sf::Text(L"Выйти", this->game->font, 20), GuiComponent::componentAlignment::TopLeft, GuiComponent::componentAlignment::TopLeft, sf::Vector2f(125, 50), sf::Color(255,255,255)));
    buttons[0]->NAME = "Exit";
    buttons.push_back(new Button(&this->game->window, sf::Text(L"Основная\nколода", this->game->font, 20), GuiComponent::componentAlignment::BottomLeft, GuiComponent::componentAlignment::Center, sf::Vector2f(150, 200), sf::Color(255,255,255)));
    buttons[1]->NAME = "MainDeck";
    buttons.push_back(new Button(&this->game->window, sf::Text(L"Колода\nсброса", this->game->font, 20), GuiComponent::componentAlignment::BottomLeft, GuiComponent::componentAlignment::Center, sf::Vector2f(150, 200), sf::Color(255,255,255)));
    buttons[2]->NAME = "DiscardDeck";


    for (auto comp : *deck1)
    {
        this->deck1.push_back(new Card(this->game, comp->cardName));

    }
    for (auto comp : *deck2)
    {
        this->deck2.push_back(new Card(this->game, comp->cardName));
    }


    this->game->window.setSize(sf::Vector2u(this->game->standartWsizeX, this->game->standartWsizeY));
    this->view.setSize(sf::Vector2f(this->game->standartWsizeX, this->game->standartWsizeY));
    this->view.setCenter(this->game->standartWsizeX*0.5f, this->game->standartWsizeY*0.5f);

    labels[1]->Move(1000,360);
    labels[2]->Move(0, 360);
    buttons[1]->Move(1000, 300);
    buttons[2]->Move(0, 300);

    for (int i=0; i<16; i++)
    {
        cardslots.push_back(new Button(&this->game->window, sf::Text(L"", this->game->font, 20), GuiComponent::componentAlignment::Center, GuiComponent::componentAlignment::Center, sf::Vector2f(150, 200), sf::Color(252,142,68), sf::Color(0,0,0), 2.5f));
        cardslots[i]->NAME = "1P_" + i;
        cardslots[i]->numero = i;
    }
    for (int i=0; i<16; i++)
    {
        if (i >= 0 && i <= 3) { cardslots[i]->Move(sf::Vector2f(-225+(155*i),-250)); continue; }
        if (i >= 4 && i <= 7) { cardslots[i]->Move(sf::Vector2f(-225+(155*(i-4)),-45)); continue; }
        if (i >= 8 && i <= 11) { cardslots[i]->Move(sf::Vector2f(-225+(155*(i-8)),170)); continue; }
        if (i >= 12 && i <= 15) { cardslots[i]->Move(sf::Vector2f(-225+(155*(i-12)),375)); continue; }
    }

    this->game->window.setSize(sf::Vector2u(pos));
    this->view.setSize(pos);
    this->view.setCenter(pos.x*0.5f, pos.y*0.5f);

    ShuffleDeck(this->deck1);

    this->cardsInMainDeck1 = this->maxdecksize;

    PullCard1P(-1);
    PullCard1P(-1);
    PullCard1P(-1);
}

GameStateBattle::~GameStateBattle()
{
    for (auto comp : buttons)
    {
        delete comp;
    }
    for (auto comp : labels)
    {
        delete comp;
    }
    for (auto comp : cardslots)
    {
        delete comp;
    }
    buttons.clear();
    labels.clear();
    cardslots.clear();

    for (auto comp : deck1)
    {
        delete comp;
    }
    for (auto comp : deck2)
    {
        delete comp;
    }
    deck1.clear();
    deck2.clear();

    std::cout << "~GameStateBattle was invoked" << std::endl;
}

void GameStateBattle::draw(const float dt)
{
    this->game->window.setView(view);

    for (auto comp : this->buttons)
    {
        comp->Render(this->game->window);
    }
    for (auto comp : this->labels)
    {
        comp->Render(this->game->window);
    }
    for (auto comp : this->cardslots)
    {
        comp->Render(this->game->window);
    }
    for (auto comp : deckInHand1)
    {
        comp->Render(this->game->window);
    }
    for (auto comp : deckOnField1)
    {
        comp->Render(this->game->window);
    }
}

void GameStateBattle::update(const float dt)
{
    //this->view.setSize(this->game->window.getSize().x, this->game->window.getSize().y);
    //this->view.setCenter(this->game->window.getSize().x *0.5f, this->game->window.getSize().y*0.5f);

    for (auto comp : this->labels)
    {
        if (comp->NAME == "Hint") { comp->SetPosition(GuiComponent::componentAlignment::Left); comp->Move(5, 0); }
        if (comp->NAME == "MainDeck") { comp->SetString(std::to_string(this->deck1.size())); }
        if (comp->NAME == "DiscardDeck") { comp->SetString(std::to_string(this->discarddeck1.size())); }
    }
    for (auto comp : this->buttons)
    {
        if (comp->NAME == "Exit") { comp->SetPositionByView(GuiComponent::componentAlignment::TopLeft, this->view); comp->Move(-200, -200); }
    }
}

void GameStateBattle::CameraMovement(const float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { this->view.move(0,-900*dt); camY+=10; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { this->view.move(-900*dt, 0); camX-=10; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { this->view.move(0, 900*dt); camY-=10; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { this->view.move(900*dt, 0); camX+=10; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) { this->view.setCenter(sf::Vector2f(this->game->standartWsizeX*0.5f, this->game->standartWsizeY*0.5f)); camX = 0; camY = 0; }

    if (camX > 300) {camX -= 10; this->view.move(-900*dt,0); }
    if (camX < -300) {camX += 10; this->view.move(900*dt, 0); }
    if (camY > 300) {camY -= 10; this->view.move(0,900*dt); }
    if (camY < -300) {camY += 10; this->view.move(0,-900*dt); }
}

void GameStateBattle::handleInput(const float dt)
{
    CameraMovement(dt);

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
                    //this->view.setCenter(event.size.width*0.5f, event.size.height*0.5f);
                }
                else
                {
                    this->game->window.setSize(sf::Vector2u(this->game->standartWsizeX, this->game->standartWsizeY));
                    this->game->window.setPosition(sf::Vector2i((int)((this->game->scrXmetric*0.5f)-this->game->standartWsizeX*0.5f ), (int)((this->game->scrYmetric*0.5f)-this->game->standartWsizeY*0.5f )));
                    this->view.setCenter(sf::Vector2f(this->game->standartWsizeX*0.5f, this->game->standartWsizeY*0.5f));
                }
                std::cout << this->game->window.getSize().x << " " << this->game->window.getSize().y << std::endl;
            break;

            case sf::Event::KeyPressed:
            break;

            case sf::Event::MouseButtonReleased:
                for (auto comp : buttons)
                {
                    if (comp->GetButtonRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
                    {
                        if (comp->NAME == "Exit") { this->~GameStateBattle(); this->game->popState(); }
                    }
                }
                for (auto comp : deckInHand1)
                {
                    if (comp->GetSpriteRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
                    {
                        if (!comp->isSelected && alreadySelected == false) { comp->isSelected = true; alreadySelected = true; comp->GetBackRect().setFillColor(sf::Color(62,82,224)); }
                        else if (comp->isSelected && alreadySelected == true) { comp->isSelected = false; alreadySelected = false; comp->GetBackRect().setFillColor(sf::Color(210,210,210)); }
                        else if (!comp->isSelected && alreadySelected == true)
                        {
                            for (auto comp : deckInHand1)
                            {
                                if (comp->isSelected) { comp->isSelected = false; comp->GetBackRect().setFillColor(sf::Color(210,210,210)); }
                            }
                            comp->isSelected = true;
                            comp->GetBackRect().setFillColor(sf::Color(62,82,224));
                        }
                    }
                }
                for (auto slot : cardslots) /// For first player /// Only For Playing Card (Not Moving)
                {
                    if (slot->GetButtonRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
                    {
                        if (slot->numero >= 8 && slot->numero<=15 && slot->isActive == false && alreadySelected)
                        {
                            slot->isActive = true; PlayCard1P(slot->GetButtonRect().getPosition());
                        }
                    }
                }
            break;
        }
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
    ///Cards Slots Highlight
    if (!playerIsBot)
    {
        for (auto comp : cardslots)
        {
            if (comp->GetButtonRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
            {
                comp->SetFillColor(sf::Color(247,177,130));
                continue;
            }
            comp->SetFillColor(sf::Color(252,142,68));
        }
    }
    else if (playerIsBot)
    {
        for (int i=8; i<16; i++)
        {
            if (cardslots[i]->GetButtonRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
            {
                cardslots[i]->SetFillColor(sf::Color(247,177,130));
                continue;
            }
            cardslots[i]->SetFillColor(sf::Color(252,142,68));
        }
    }

    ///Card Highlight
    for (auto comp : deckInHand1)
    {
        if (comp->GetSpriteRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
        {
            if (!comp->isSelected) comp->GetBackRect().setFillColor(sf::Color(130,130,130));
            continue;
        }
        if (!comp->isSelected) comp->GetBackRect().setFillColor(sf::Color(210,210,210));
    }
}

void GameStateBattle::NextTurn()
{
    this->turnnum++;
}

void GameStateBattle::PlayCard1P (sf::Vector2f slotpos)
{
    cardsInHand1--;
    int tmp;
    for (auto comp : deckInHand1)
    {
        if (comp->isSelected)
        {
            this->deckOnField1.push_back(comp);
            comp->setPosition(slotpos);
            comp->isSelected = false;
            comp->GetBackRect().setFillColor(sf::Color(210,210,210));
            tmp = comp->posInHand;
            comp->posInHand = -1;
        }
    }

    auto it = deckInHand1.begin();
    std::advance(it, tmp-1);
    deckInHand1.erase(it);

    PullCard1P(tmp);


    alreadySelected = false;
}

void GameStateBattle::ShuffleDiscardedCards1P ()
{

}

void GameStateBattle::PullCard1P (int newposinhand)
{
    this->cardsInHand1++;


    if (newposinhand == -1 || newposinhand == 3)
    {
        deckInHand1.push_back(this->deck1.back());
        deck1.pop_back();

        deckInHand1.back()->setPosition(sf::Vector2f(this->game->standartWsizeX*0.5f, this->game->standartWsizeY*0.5f));

        this->deckInHand1.back()->move(sf::Vector2f(-305+(160*this->cardsInHand1), 670));
        this->deckInHand1.back()->posInHand = cardsInHand1;

        std::cout << deckInHand1.back()->GetCardNameInString() << " was added to hand" << std::endl;
    }
    else if (newposinhand == 1 || newposinhand == 2)
    {
        auto it = deckInHand1.begin();
        std::advance(it, newposinhand-1);
        this->deckInHand1.insert(it, this->deck1.back());
        this->deck1.pop_back();

        deckInHand1.at(newposinhand-1)->setPosition(sf::Vector2f(this->game->standartWsizeX*0.5f, this->game->standartWsizeY*0.5f));

        this->deckInHand1.at(newposinhand-1)->posInHand = newposinhand;
        this->deckInHand1.at(newposinhand-1)->move(sf::Vector2f(-305+(160*newposinhand), 670));

        std::cout << deckInHand1.at(newposinhand-1)->GetCardNameInString() << " was added to hand" << std::endl;
    }








    return;
}

void GameStateBattle::Swap(Card* a, Card* b)
{
    Card* tmp = a;
    a = b;
    b = tmp;
}

void GameStateBattle::ShuffleDeck(std::vector<Card*>& deck)
{
    for (int i = deck.size() - 1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i + 1);

        // Swap arr[i] with the element
        // at random index
        Swap(deck[i], deck[j]);
    }
}
