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
    labels.push_back(new Label(&this->game->window, sf::Text(L"Фаза:", this->game->font, 25), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Color::Black, sf::Color::White, 3));
    labels[3]->NAME = "PhaseLabel";
    labels.push_back(new Label(&this->game->window, sf::Text(L"-", this->game->font, 25), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Color::Black, sf::Color::White, 3));
    labels[4]->NAME = "PhaseState";
    labels.push_back(new Label(&this->game->window, sf::Text(L"0", this->game->font, 25), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Color::Black, sf::Color::White, 3));
    labels[5]->NAME = "TurnNum";
    labels.push_back(new Label(&this->game->window, sf::Text(L"Ход:", this->game->font, 25), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Color::Black, sf::Color::White, 3));
    labels[6]->NAME = "TurnLabel";
    labels.push_back(new Label(&this->game->window, sf::Text(L"0", this->game->font, 25), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Color::White, sf::Color::Black, 2));
    labels[7]->NAME = "MoneyNum";
    labels.push_back(new Label(&this->game->window, sf::Text(L"0", this->game->font, 25), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Color::White, sf::Color::Black, 2));
    labels[8]->NAME = "MoneyNum2P";
    labels.push_back(new Label(&this->game->window, sf::Text(L"Ход Игрока 1", this->game->font, 25), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Color::White, sf::Color::Black, 2));
    labels[9]->NAME = "TurnOfWhom";
    labels.push_back(new Label(&this->game->window, sf::Text(L"0", this->game->font, 25), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Color::White, sf::Color::Black, 2));
    labels[10]->NAME = "Health1Pnum";
    labels.push_back(new Label(&this->game->window, sf::Text(L"0", this->game->font, 25), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Color::White, sf::Color::Black, 2));
    labels[11]->NAME = "Health2Pnum";
    labels.push_back(new Label(&this->game->window, sf::Text(L"", this->game->font, 50), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Color::White, sf::Color::Black, 2));
    labels[12]->NAME = "VictoryLabel";


    buttons.push_back(new Button(&this->game->window, sf::Text(L"Выйти", this->game->font, 20), GuiComponent::componentAlignment::TopLeft, GuiComponent::componentAlignment::TopLeft, sf::Vector2f(125, 50), sf::Color(255,255,255)));
    buttons[0]->NAME = "Exit";
    buttons.push_back(new Button(&this->game->window, sf::Text(L"Основная\nколода", this->game->font, 20), GuiComponent::componentAlignment::BottomLeft, GuiComponent::componentAlignment::Center, sf::Vector2f(150, 200), sf::Color(255,255,255)));
    buttons[1]->NAME = "MainDeck";
    buttons.push_back(new Button(&this->game->window, sf::Text(L"Колода\nсброса", this->game->font, 20), GuiComponent::componentAlignment::BottomLeft, GuiComponent::componentAlignment::Center, sf::Vector2f(150, 200), sf::Color(255,255,255)));
    buttons[2]->NAME = "DiscardDeck";
    buttons.push_back(new Button(&this->game->window, sf::Text(L"След.\nфаза", this->game->font, 20), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Vector2f(70, 70), sf::Color(255,255,255)));
    buttons[3]->NAME = "NextTurn";
    buttons.push_back(new Button(&this->game->window, sf::Text(L"", this->game->font, 20), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Vector2f(80, 80), sf::Color(255,255,255), sf::Color::Black, 0));
    buttons[4]->NAME = "MoneyImage";
    buttons[4]->GetButtonRect().setTexture(&this->game->texturemanager.GetTextureRef("Coin"));
    buttons.push_back(new Button(&this->game->window, sf::Text(L"", this->game->font, 20), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Vector2f(80, 80), sf::Color(255,255,255), sf::Color::Black, 0));
    buttons[5]->NAME = "MoneyImage2P";
    buttons[5]->GetButtonRect().setTexture(&this->game->texturemanager.GetTextureRef("Coin"));
    buttons.push_back(new Button(&this->game->window, sf::Text(L"", this->game->font, 20), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Vector2f(80, 80), sf::Color(255,255,255), sf::Color::Black, 0));
    buttons[6]->NAME = "HealthImage1P";
    buttons[6]->GetButtonRect().setTexture(&this->game->texturemanager.GetTextureRef("HitPoint"));
    buttons.push_back(new Button(&this->game->window, sf::Text(L"", this->game->font, 20), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Vector2f(80, 80), sf::Color(255,255,255), sf::Color::Black, 0));
    buttons[7]->NAME = "HealthImage2P";
    buttons[7]->GetButtonRect().setTexture(&this->game->texturemanager.GetTextureRef("HitPoint"));




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
    labels[3]->Move(900,-100);
    labels[4]->Move(950,-100);
    labels[5]->Move(110,-100);
    labels[6]->Move(60,-100);
    labels[7]->Move(920, 300);
    labels[8]->Move(920, -400);
    labels[9]->Move(900, 200);
    labels[10]->Move(-5, 500);
    labels[11]->Move(-5, -400);
    labels[12]->Move(500, 0);

    buttons[1]->Move(1000, 300);
    buttons[2]->Move(0, 300);
    buttons[3]->Move(910,-160);
    buttons[4]->Move(920, 300);
    buttons[5]->Move(920, -400);
    buttons[6]->Move(0, 500);
    buttons[7]->Move(0, -400);

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
    ShuffleDeck(this->deck2);

    this->cardsInMainDeck1 = this->maxdecksize;

    PullCard1P(-1);
    PullCard1P(-1);
    PullCard1P(-1);

    if (this->Player1FirstTurn)
    {
        this->money1P = 2;
        this->money2P = 3;
        whoplays = WhoPlays::Player1;
    }
    else if (!this->Player1FirstTurn)
    {
        this->money1P = 3;
        this->money2P = 2;
        whoplays = WhoPlays::Player2;
    }
}

GameStateBattle::~GameStateBattle()
{
    for (auto comp : buttons)
    {
        delete comp;
    }
    for (auto comp : cardslots)
    {
        delete comp;
    }
    for (auto comp : labels)
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
    for (auto comp : deckOnField2)
    {
        comp->Render(this->game->window);
    }
    for (auto comp : this->labels)
    {
        comp->Render(this->game->window);
    }
}

void GameStateBattle::update(const float dt)
{
    //this->view.setSize(this->game->window.getSize().x, this->game->window.getSize().y);
    //this->view.setCenter(this->game->window.getSize().x *0.5f, this->game->window.getSize().y*0.5f);

    if (money1P > 20) { money1P = 20; }
    if (money2P > 20) { money2P = 20; }

    for (auto comp : this->labels)
    {
        if (comp->NAME == "Hint") { comp->SetPosition(GuiComponent::componentAlignment::Left); comp->Move(5, 0); }
        if (comp->NAME == "MainDeck") { comp->SetString(std::to_string(this->deck1.size())); }
        if (comp->NAME == "DiscardDeck") { comp->SetString(std::to_string(this->discarddeck1.size())); }
        if (comp->NAME == "TurnNum") { comp->SetString(std::to_string(this->turnnum)); }
        if (comp->NAME == "MoneyNum") { comp->SetString(std::to_string(this->money1P)); }
        if (comp->NAME == "MoneyNum2P") { comp->SetString(std::to_string(this->money2P)); }
        if (comp->NAME == "PhaseState" && this->phaseP1 == Phase::PlayCards) { comp->SetString(L"Покупка карт"); }
        else if (comp->NAME == "PhaseState" && this->phaseP1 == Phase::Attack) { comp->SetString(L"Атака"); }
        else if (comp->NAME == "PhaseState" && this->phaseP1 == Phase::Wait) { comp->SetString(L"-"); }
        if (comp->NAME == "TurnOfWhom" && whoplays == WhoPlays::Player1) { comp->SetString(L"Ход 1 игрока"); }
        else if (comp->NAME == "TurnOfWhom" && whoplays == WhoPlays::Player2) { comp->SetString(L"Ход 2 игрока"); }
        if (comp->NAME == "Health1Pnum") { comp->SetString(std::to_string(this->health1P)); }
        if (comp->NAME == "Health2Pnum") { comp->SetString(std::to_string(this->health2P)); }
    }
    for (auto comp : this->buttons)
    {
        if (comp->NAME == "Exit") { comp->SetPositionByView(GuiComponent::componentAlignment::TopLeft, this->view); comp->Move(-200, -200); }
        if (comp->NAME == "NextTurn" && this->phaseP1 == Phase::PlayCards) { this->buttons[3]->GetLabel().SetString(sf::String(L"След.\nфаза")); }
        else if (comp->NAME == "NextTurn" && this->phaseP1 == Phase::Attack) { this->buttons[3]->GetLabel().SetString(sf::String(L"Конец\nхода")); }
    }


    if (whoplays == WhoPlays::Player2 && this->playerIsBot) { AIplays(); }

    if (whoplays == WhoPlays::Player1)
    {
        for (auto comp : deckOnField1)
        {
            if (comp->nextturn == this->turnnum)
            {
                comp->canShoot = true;
            }
            if (comp->hasAttacked == true && comp->isSelected == false)
            {
                comp->GetBackRect().setFillColor(sf::Color(214,201,67));
            }
            if (comp->hasAttacked == false && comp->isSelected == false)
            {
                comp->GetBackRect().setFillColor(sf::Color(210,210,210));
            }
        }
    }
    if (phaseP1 == Phase::PlayCards || whoplays == WhoPlays::Player2)
    {
        for (int i=0; i<4; i++)
        {
            cardslots[i]->underAttack = false;
            if (cardslots[i]->underAttack == false) { cardslots[i]->GetButtonRect().setOutlineColor(sf::Color(0,0,0)); }
        }
    }

    if (whoplays == WhoPlays::Player1 && phaseP1 == Phase::Attack)
    {
        for (auto comp : deckOnField1)
        {
            ///Check if can attack player 2 directly
            if (comp->canShoot && comp->isSelected)
            {
                if (comp->posOnField == 8 && cardslots[0]->isActive == false && cardslots[4]->isActive == false)
                {
                    cardslots[0]->GetButtonRect().setOutlineColor(sf::Color(255,46,0));
                    cardslots[0]->underAttack = true;
                }
                if (comp->posOnField == 9 && cardslots[1]->isActive == false && cardslots[5]->isActive == false)
                {
                    cardslots[1]->GetButtonRect().setOutlineColor(sf::Color(255,46,0));
                    cardslots[1]->underAttack = true;
                }
                if (comp->posOnField == 10 && cardslots[2]->isActive == false && cardslots[6]->isActive == false)
                {
                    cardslots[2]->GetButtonRect().setOutlineColor(sf::Color(255,46,0));
                    cardslots[2]->underAttack = true;
                }
                if (comp->posOnField == 11 && cardslots[3]->isActive == false && cardslots[7]->isActive == false)
                {
                    cardslots[3]->GetButtonRect().setOutlineColor(sf::Color(255,46,0));
                    cardslots[3]->underAttack = true;
                }
                break;
            }
            for (int i=0; i<4; i++)
            {
                cardslots[i]->underAttack = false;
                if (cardslots[i]->underAttack == false) { cardslots[i]->GetButtonRect().setOutlineColor(sf::Color(0,0,0)); }
            }
        }
        for (auto comp : deckOnField1)
        {
            ///Check if can attack player 2 individual cards
            if (comp->canShoot && comp->isSelected && !comp->hasAttacked)
            {
                if (comp->posOnField == 8 && cardslots[4]->isActive == true){
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 4){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }
                else if (comp->posOnField == 8 && cardslots[0]->isActive == true && cardslots[4]->isActive == false)
                {
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 0){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }
                else if (comp->posOnField == 9 && cardslots[5]->isActive == true){
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 5){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }
                else if (comp->posOnField == 9 && cardslots[1]->isActive == true && cardslots[5]->isActive == false)
                {
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 1){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }
                else if (comp->posOnField == 10 && cardslots[6]->isActive == true){
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 6){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }
                else if (comp->posOnField == 10 && cardslots[2]->isActive == true && cardslots[6]->isActive == false)
                {
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 2){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }
                else if (comp->posOnField == 11 && cardslots[7]->isActive == true){
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 7){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }
                else if (comp->posOnField == 11 && cardslots[3]->isActive == true && cardslots[7]->isActive == false)
                {
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 3){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }
                else if (comp->posOnField == 12 && cardslots[4]->isActive == true && cardslots[8]->isActive == false)
                {
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 4){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }
                else if (comp->posOnField == 12 && cardslots[0]->isActive == true && cardslots[4]->isActive == false && cardslots[8]->isActive == false)
                {
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 0){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }
                else if (comp->posOnField == 13 && cardslots[5]->isActive == true && cardslots[9]->isActive == false)
                {
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 5){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }
                else if (comp->posOnField == 13 && cardslots[1]->isActive == true && cardslots[5]->isActive == false && cardslots[9]->isActive == false)
                {
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 1){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }
                else if (comp->posOnField == 14 && cardslots[6]->isActive == true && cardslots[10]->isActive == false)
                {
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 6){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }
                else if (comp->posOnField == 14 && cardslots[2]->isActive == true && cardslots[6]->isActive == false && cardslots[10]->isActive == false)
                {
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 2){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }
                else if (comp->posOnField == 15 && cardslots[7]->isActive == true && cardslots[11]->isActive == false)
                {
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 7){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }
                else if (comp->posOnField == 15 && cardslots[3]->isActive == true && cardslots[7]->isActive == false && cardslots[11]->isActive == false)
                {
                    for (auto p2card : deckOnField2){
                        if (p2card->posOnField == 3){
                            p2card->GetBackRect().setFillColor(sf::Color(255,46,0));
                            p2card->underAttack = true;
                        }
                    }
                }

                break;
            }
            for (auto p2card : deckOnField2)
            {
                p2card->underAttack = false;
                p2card->GetBackRect().setFillColor(sf::Color(210,210,210));
            }
        }
    }


    if (whoplays == WhoPlays::Player1 && phaseP1 == Phase::PlayCards)
    {
        for (auto comp : deckOnField1)
        {
            comp->isSelected = false;
        }
        for (auto comp : deckOnField2)
        {
            comp->underAttack = false;
        }
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
                            if (comp->NAME == "NextTurn" && this->phaseP1 == Phase::PlayCards) { this->phaseP1 = Phase::Attack; }
                            else if (comp->NAME == "NextTurn" && this->phaseP1 == Phase::Attack) { NextTurn(); this->phaseP1 = Phase::Wait; }
                        }
                    }
                    if (!FinishedGame()) {

                    for (auto comp : deckOnField1)
                    {
                        if (comp->GetSpriteRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
                        {
                            if (!comp->isSelected && alreadySelected == false) { comp->isSelected = true; alreadySelected = true; comp->GetBackRect().setFillColor(sf::Color(62,82,224)); }
                            else if (comp->isSelected && alreadySelected == true) { comp->isSelected = false; alreadySelected = false; comp->GetBackRect().setFillColor(sf::Color(210,210,210)); }
                            else if (!comp->isSelected && alreadySelected == true)
                            {
                                for (auto comp : deckOnField1)
                                {
                                    if (comp->isSelected) { comp->isSelected = false; comp->GetBackRect().setFillColor(sf::Color(210,210,210)); }
                                }
                                for (auto comp : deckInHand1)
                                {
                                    if (comp->isSelected) { comp->isSelected = false; comp->GetBackRect().setFillColor(sf::Color(210,210,210)); }
                                }
                                for (auto p2card : deckOnField2)
                                {
                                    p2card->GetBackRect().setFillColor(sf::Color(210,210,210));
                                }
                                for (int i=0; i<4; i++)
                                {
                                    cardslots[i]->underAttack = false;
                                    if (cardslots[i]->underAttack == false) { cardslots[i]->GetButtonRect().setOutlineColor(sf::Color(0,0,0)); }
                                }
                                comp->isSelected = true;
                                comp->GetBackRect().setFillColor(sf::Color(62,82,224));
                            }
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
                                for (auto comp : deckOnField1)
                                {
                                    if (comp->isSelected) { comp->isSelected = false; comp->GetBackRect().setFillColor(sf::Color(210,210,210)); }
                                }
                                comp->isSelected = true;
                                comp->GetBackRect().setFillColor(sf::Color(62,82,224));
                            }
                        }
                    }
                    if (whoplays == WhoPlays::Player1)
                    {
                        for (auto slot : cardslots) /// For first player /// Only For Playing Card (Not Moving)
                        {
                            if (slot->GetButtonRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
                            {
                                if (slot->numero >= 8 && slot->numero<=15 && slot->isActive == false && alreadySelected)
                                {
                                    for (auto comp : deckInHand1)
                                    {
                                        if (comp->isSelected && this->money1P >= comp->cost)
                                        {
                                            this->money1P -= comp->cost; comp->posOnField = slot->numero;
                                            slot->isActive = true; PlayCard1P(slot->GetButtonRect().getPosition());
                                            //placedCard = true;
                                        }
                                    }
                                }
                                if (slot->numero == 0 && slot->underAttack == true && slot->isActive == false){ /// Attack player 2 directly
                                    for (auto comp : deckOnField1){
                                        if (comp->posOnField == 8 && comp->isSelected){
                                            if (rand()%6+1 <= comp->cur_acr && comp->hasAttacked == false){
                                                this->health2P -= comp->cur_dmg;

                                            }
                                            comp->hasAttacked = true;
                                        }
                                    }
                                }
                                if (slot->numero == 1 && slot->underAttack == true && slot->isActive == false){ /// Attack player 2 directly
                                    for (auto comp : deckOnField1){
                                        if (comp->posOnField == 9 && comp->isSelected){
                                            if (rand()%6+1 <= comp->cur_acr && comp->hasAttacked == false){
                                                this->health2P -= comp->cur_dmg;
                                                comp->hasAttacked = true;
                                            }
                                        }
                                    }
                                }
                                if (slot->numero == 2 && slot->underAttack == true && slot->isActive == false){ /// Attack player 2 directly
                                    for (auto comp : deckOnField1){
                                        if (comp->posOnField == 10 && comp->isSelected){
                                            if (rand()%6+1 <= comp->cur_acr && comp->hasAttacked == false){
                                                this->health2P -= comp->cur_dmg;
                                                comp->hasAttacked = true;
                                            }
                                        }
                                    }
                                }
                                if (slot->numero == 3 && slot->underAttack == true && slot->isActive == false){ /// Attack player 2 directly
                                    for (auto comp : deckOnField1){
                                        if (comp->posOnField == 11 && comp->isSelected){
                                            if (rand()%6+1 <= comp->cur_acr && comp->hasAttacked == false){
                                                this->health2P -= comp->cur_dmg;
                                                comp->hasAttacked = true;
                                            }
                                        }
                                    }
                                }

                            }
                        }
                        /// Attack player 2 cards
                        if (phaseP1 == Phase::Attack)
                        {
                            for (auto comp : deckOnField2)
                            {
                                if (comp->GetSpriteRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
                                {
                                    if (comp->underAttack){
                                        for (auto card1P : deckOnField1){
                                            if (comp->posOnField == card1P->posOnField-8 && card1P->isSelected && card1P->cur_dmg > 0){
                                                if (rand()%6+1 <= card1P->cur_acr && card1P->hasAttacked == false){
                                                    comp->cur_hp -= card1P->cur_dmg;
                                                    comp->Update();
                                                }
                                                card1P->hasAttacked = true;

                                                if (comp->cur_hp <= 0)
                                                {
                                                    this->money1P += comp->income;
                                                    this->cardslots[comp->posOnField]->isActive = false;
                                                    this->discarddeck2.push_back(comp);
                                                    auto it = deckOnField2.begin();
                                                    for (int i=0; i<deckOnField2.size(); i++)
                                                    {
                                                        if (deckOnField2[i]->cur_hp <=0) { std::advance(it, i);  this->deckOnField2.erase(it); }
                                                    }

                                                }
                                                continue;
                                            }
                                            else if (comp->posOnField == card1P->posOnField-4 && card1P->isSelected && card1P->cur_dmg > 0){
                                                if (rand()%6+1 <= card1P->cur_acr && card1P->hasAttacked == false){
                                                    comp->cur_hp -= card1P->cur_dmg;
                                                    comp->Update();
                                                }
                                                card1P->hasAttacked = true;

                                                if (comp->cur_hp <= 0)
                                                {
                                                    this->money1P += comp->income;
                                                    this->cardslots[comp->posOnField]->isActive = false;
                                                    this->discarddeck2.push_back(comp);
                                                    auto it = deckOnField2.begin();
                                                    for (int i=0; i<deckOnField2.size(); i++)
                                                    {
                                                        if (deckOnField2[i]->cur_hp <=0) { std::advance(it, i);  this->deckOnField2.erase(it); }
                                                    }


                                                }
                                                continue;
                                            }
                                            else if (comp->posOnField == card1P->posOnField-12 && card1P->isSelected && card1P->cur_dmg > 0){
                                                if (rand()%6+1 <= card1P->cur_acr && card1P->hasAttacked == false){
                                                    comp->cur_hp -= card1P->cur_dmg;
                                                    comp->Update();
                                                }
                                                card1P->hasAttacked = true;

                                                if (comp->cur_hp <= 0)
                                                {
                                                    this->money1P += comp->income;
                                                    this->cardslots[comp->posOnField]->isActive = false;
                                                    this->discarddeck2.push_back(comp);
                                                    auto it = deckOnField2.begin();
                                                    for (int i=0; i<deckOnField2.size(); i++)
                                                    {
                                                        if (deckOnField2[i]->cur_hp <=0) { std::advance(it, i);  this->deckOnField2.erase(it); }
                                                    }
                                                }
                                                continue;
                                            }
                                        }
                                    }
                                }
                            }
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

    for (auto comp : deckOnField1)
    {
        //if (!comp->isSelected && comp->canShoot == false) comp->GetBackRect().setFillColor(sf::Color(100,100,100));
        //else if (!comp->isSelected && comp->canShoot == true) comp->GetBackRect().setFillColor(sf::Color(210,210,210));
    }
}

void GameStateBattle::NextTurn()
{
    this->turnnum++;
    if (turnnum > 2) this->firstTurnOfAllPlayers = false;
    if (turnnum == 2) { whoplays = WhoPlays::Player2; }
    if (!this->firstTurnOfAllPlayers && whoplays == WhoPlays::Player1)
    {
        this->money2P += income2P;
        whoplays = WhoPlays::Player2;
    }
    else if (!this->firstTurnOfAllPlayers && whoplays == WhoPlays::Player2)
    {
        this->money1P += income1P;
        whoplays = WhoPlays::Player1;
    }
    for (auto comp : deckOnField1)
    {
        comp->hasAttacked = false;
    }
    for (auto comp : deckOnField2)
    {
        comp->hasAttacked = false;
    }
}

void GameStateBattle::AIplays()
{
    if (!deck2.empty() && this->deckInHand2.size() == 0)
    {
        this->deckInHand2.push_back(deck2.back());
        deck2.pop_back();
    }
    else if (deck2.empty())
    {
        for (auto comp : discarddeck2)
        {
            comp->InitCard();
            comp->hasAttacked = false;
            comp->canShoot = false;
            deck2.push_back(comp);
        }
        if (!deck2.empty()) ShuffleDeck(deck2);
    }

    if (!deckInHand2.empty())
    {

        int slotnum = rand() % 8;

        for (auto slot : this->cardslots)
        {
            if (slot->numero == slotnum && slot->isActive == false)
            {
                if (this->money2P >= this->deckInHand2.back()->cost)
                {
                    this->money2P -= this->deckInHand2.back()->cost;
                    this->deckOnField2.push_back(this->deckInHand2.back());
                    this->deckInHand2.pop_back();
                    this->deckOnField2.back()->setPosition(slot->GetButtonRect().getPosition());
                    this->deckOnField2.back()->posOnField = slot->numero;
                    this->deckOnField2.back()->nextturn = this->turnnum+2;
                    slot->isActive = true;
                    std::cout << "P2 played " << deckOnField2.back()->GetCardNameInString() << " cur_hp: " << deckOnField2.back()->cur_hp << " hp: " << deckOnField2.back()->hp << std::endl;
                }
            }
        }
    }


        for (auto card2P : this->deckOnField2)
        {
            if (card2P->nextturn == this->turnnum) card2P->canShoot = true;

            if (card2P->posOnField == 4 && !cardslots[8]->isActive && !cardslots[12]->isActive && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    this->health1P -= card2P->cur_dmg;
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 4 && cardslots[8]->isActive && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 8) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 4 && cardslots[12]->isActive && !cardslots[8]->isActive && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 12) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }
            if (card2P->posOnField == 5 && !cardslots[9]->isActive && !cardslots[13]->isActive && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    this->health1P -= card2P->cur_dmg;
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 5 && cardslots[9]->isActive && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 9) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 5 && cardslots[13]->isActive && !cardslots[9]->isActive && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 13) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }
            if (card2P->posOnField == 6 && !cardslots[10]->isActive && !cardslots[14]->isActive && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    this->health1P -= card2P->cur_dmg;
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 6 && cardslots[10]->isActive && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 10) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 6 && cardslots[14]->isActive && !cardslots[10]->isActive && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 14) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }
            if (card2P->posOnField == 7 && !cardslots[11]->isActive && !cardslots[15]->isActive && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    this->health1P -= card2P->cur_dmg;
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 7 && cardslots[11]->isActive && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 11) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 7 && cardslots[15]->isActive && !cardslots[11]->isActive && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 15) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }
            if (card2P->posOnField == 0 && !cardslots[8]->isActive && !cardslots[12]->isActive && cardslots[4]->isActive == false && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    this->health1P -= card2P->cur_dmg;
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 0 && cardslots[8]->isActive && cardslots[4]->isActive == false && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 8) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 0 && cardslots[12]->isActive && !cardslots[8]->isActive && cardslots[4]->isActive == false && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 12) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }
            if (card2P->posOnField == 1 && !cardslots[9]->isActive && !cardslots[13]->isActive && cardslots[5]->isActive == false && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    this->health1P -= card2P->cur_dmg;
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 1 && cardslots[9]->isActive && cardslots[5]->isActive == false && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 9) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 1 && cardslots[13]->isActive && !cardslots[9]->isActive && cardslots[5]->isActive == false && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 13) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }
            if (card2P->posOnField == 2 && !cardslots[10]->isActive && !cardslots[14]->isActive && cardslots[6]->isActive == false && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    this->health1P -= card2P->cur_dmg;
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 2 && cardslots[10]->isActive && cardslots[6]->isActive == false && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 10) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 2 && cardslots[14]->isActive && !cardslots[10]->isActive && cardslots[6]->isActive == false && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 14) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }
            if (card2P->posOnField == 3 && !cardslots[11]->isActive && !cardslots[15]->isActive && cardslots[7]->isActive == false && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    this->health1P -= card2P->cur_dmg;
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 3 && cardslots[11]->isActive && cardslots[7]->isActive == false && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 11) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }
            else if (card2P->posOnField == 3 && cardslots[15]->isActive && !cardslots[11]->isActive && cardslots[7]->isActive == false && card2P->cur_dmg > 0){
                if (rand()%6+1 <= card2P->cur_acr && card2P->hasAttacked == false && card2P->canShoot){
                    for (int i=0; i<this->deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->posOnField == 15) { deckOnField1[i]->cur_hp -= (card2P->cur_dmg-deckOnField1[i]->cur_armor); deckOnField1[i]->Update(); }
                    }
                }
                card2P->hasAttacked = true;
            }

            for (auto card1P : deckOnField1)
            {
                if (card1P->cur_hp <= 0)
                {
                    this->money2P += card1P->income;
                    this->cardslots[card1P->posOnField]->isActive = false;
                    this->discarddeck1.push_back(card1P);
                    auto it = deckOnField1.begin();
                    for (size_t i=0; i<deckOnField1.size(); i++)
                    {
                        if (deckOnField1[i]->cur_hp <=0) std::advance(it, i);
                    }
                    this->deckOnField1.erase(it);
                }
            }
        }

    NextTurn();
    this->phaseP1 = Phase::PlayCards;
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
            comp->nextturn = this->turnnum+2;
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

    if (deck1.empty())
    {
        if (!discarddeck1.empty())
        {
            ShuffleDeck(discarddeck1);
            for (auto comp : discarddeck1)
            {
                comp->InitCard();
                comp->hasAttacked = false;
                comp->canShoot = false;
                comp->isSelected = false;
                deck1.push_back(comp);
            }
            discarddeck1.clear();
        }
    }

    if (!deck1.empty())
    {
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
}

bool GameStateBattle::FinishedGame()
{
    if (health1P <= 0)
    {
        this->labels[12]->SetString(sf::String(L"Игрок 2 победил!"));
        return true;
    }
    else if (health2P <= 0)
    {
        this->labels[12]->SetString(sf::String(L"Игрок 1 победил!"));
        return true;
    }
    return false;
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
