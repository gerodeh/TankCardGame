#include "GameStateCustomization.h"

//
///
///
///Deck builder menu
///
///
//

void GameStateCustomization::CreateGeneralCards(std::vector<std::vector<Card*>>& generalcards)
{
    std::vector<Card*> tmpvector;

    tmpvector.push_back(new Card(this->game, Card::CardNames::T_34_76));
    tmpvector[0]->CardID = 0;
    tmpvector.push_back(new Card(this->game, Card::CardNames::T_34_85));
    tmpvector[1]->CardID = 1;
    tmpvector.push_back(new Card(this->game, Card::CardNames::IS_2));
    tmpvector[2]->CardID = 2;
    tmpvector.push_back(new Card(this->game, Card::CardNames::SU_100));
    tmpvector[3]->CardID = 3;
    tmpvector.push_back(new Card(this->game, Card::CardNames::KV_1));
    tmpvector[4]->CardID = 4;
    tmpvector.push_back(new Card(this->game, Card::CardNames::LTvz38));
    tmpvector[5]->CardID = 5;
    tmpvector.push_back(new Card(this->game, Card::CardNames::TigerI));
    tmpvector[6]->CardID = 6;
    tmpvector.push_back(new Card(this->game, Card::CardNames::Hetzer));
    tmpvector[7]->CardID = 7;

    generalcards.push_back(tmpvector);
    tmpvector.clear();

    tmpvector.push_back(new Card(this->game, Card::CardNames::PzIII));
    tmpvector[0]->CardID = 0;
    tmpvector.push_back(new Card(this->game, Card::CardNames::TigerII));
    tmpvector[1]->CardID = 1;
    tmpvector.push_back(new Card(this->game, Card::CardNames::IS_1));
    tmpvector[2]->CardID = 2;
    tmpvector.push_back(new Card(this->game, Card::CardNames::KV_1));
    tmpvector[3]->CardID = 3;
    tmpvector.push_back(new Card(this->game, Card::CardNames::MS_1));
    tmpvector[4]->CardID = 4;
    tmpvector.push_back(new Card(this->game, Card::CardNames::SU_152));
    tmpvector[5]->CardID = 5;
    tmpvector.push_back(new Card(this->game, Card::CardNames::ISU_152));
    tmpvector[6]->CardID = 6;
    tmpvector.push_back(new Card(this->game, Card::CardNames::Panther));
    tmpvector[7]->CardID = 7;

    generalcards.push_back(tmpvector);
    tmpvector.clear();

    tmpvector.push_back(new Card(this->game, Card::CardNames::Lowe));
    tmpvector[0]->CardID = 0;
    tmpvector.push_back(new Card(this->game, Card::CardNames::MarderI));
    tmpvector[1]->CardID = 1;
    tmpvector.push_back(new Card(this->game, Card::CardNames::PzI));
    tmpvector[2]->CardID = 2;
    tmpvector.push_back(new Card(this->game, Card::CardNames::StugIIIG));
    tmpvector[3]->CardID = 3;
    tmpvector.push_back(new Card(this->game, Card::CardNames::T_34_76));
    tmpvector[4]->CardID = 4;
    tmpvector.push_back(new Card(this->game, Card::CardNames::T_34_85));
    tmpvector[5]->CardID = 5;
    tmpvector.push_back(new Card(this->game, Card::CardNames::PzIII));
    tmpvector[6]->CardID = 6;
    tmpvector.push_back(new Card(this->game, Card::CardNames::Panther));
    tmpvector[7]->CardID = 7;

    generalcards.push_back(tmpvector);
    tmpvector.clear();
}

GameStateCustomization::GameStateCustomization(Game* game)
{
    std::srand((unsigned)time(NULL));

    this->game = game;

    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());

    this->view.setSize(pos);

    pos *= 0.5f;

    this->view.setCenter(pos);

    CreateGeneralCards(this->generalcards);
    CreateGeneralCards(this->generalcards2);

    this->maxPage = this->generalcards.size();

    currentScene = SceneNum::Main;

    /// Main scene

    std::vector<Label*> tmplabels;

    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"Построение колоды и настройка игры", this->game->font, 30), GuiComponent::componentAlignment::Top, GuiComponent::componentAlignment::Top, sf::Color::Black, sf::Color::White, 3));
    tmplabels[0]->NAME = "TopLabel";
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"Колода 1-ого игрока", this->game->font, 20), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Left, sf::Color::Black, sf::Color::White, 3));
    tmplabels[1]->NAME = "1st Deck Label";
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"Колода 2-ого игрока", this->game->font, 20), GuiComponent::componentAlignment::Right, GuiComponent::componentAlignment::Right, sf::Color::Black, sf::Color::White, 3));
    tmplabels[2]->NAME = "2nd Deck Label";
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"Макс. кол-во карт в колоде:", this->game->font, 20), GuiComponent::componentAlignment::Center, GuiComponent::componentAlignment::Center, sf::Color::Black, sf::Color::White, 3));
    tmplabels[3]->NAME = "DeckSizeLabel";
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"Hotseat:", this->game->font, 20), GuiComponent::componentAlignment::Center, GuiComponent::componentAlignment::Center, sf::Color::Black, sf::Color::White, 3));
    tmplabels[4]->NAME = "PlayerOrAILabel";
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"0", this->game->font, 30), GuiComponent::componentAlignment::Center, GuiComponent::componentAlignment::Center, sf::Color::Black, sf::Color::White, 3));
    tmplabels[5]->NAME = "1PDeckSizeLabelNUM";
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"0", this->game->font, 30), GuiComponent::componentAlignment::Center, GuiComponent::componentAlignment::Center, sf::Color::Black, sf::Color::White, 3));
    tmplabels[6]->NAME = "2PDeckSizeLabelNUM";
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"Карт:", this->game->font, 30), GuiComponent::componentAlignment::Center, GuiComponent::componentAlignment::Center, sf::Color::Black, sf::Color::White, 3));
    tmplabels[7]->NAME = "1PDeckSizeLabel";
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"Карт:", this->game->font, 30), GuiComponent::componentAlignment::Center, GuiComponent::componentAlignment::Center, sf::Color::Black, sf::Color::White, 3));
    tmplabels[8]->NAME = "2PDeckSizeLabel";
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"Макс. кол-во карт меньше 12!", this->game->font, 20), GuiComponent::componentAlignment::Center, GuiComponent::componentAlignment::BottomRight, sf::Color::Black, sf::Color::White, 3));
    tmplabels[9]->NAME = "WarningLabel";

    labels.push_back(tmplabels);

    tmplabels.clear();

    std::vector<Button*> tmpbuttons;

    tmpbuttons.push_back(new Button(&this->game->window, sf::Text(L"Вернуться", this->game->font, 35), GuiComponent::componentAlignment::BottomLeft, GuiComponent::componentAlignment::BottomLeft, sf::Vector2f(300, 50), sf::Color(255,255,255)));
    tmpbuttons[0]->NAME = "Return";
    tmpbuttons.push_back(new Button(&this->game->window, sf::Text(L"Играть", this->game->font, 35), GuiComponent::componentAlignment::BottomRight, GuiComponent::componentAlignment::BottomRight, sf::Vector2f(220, 50), sf::Color(32,176,39)));
    tmpbuttons[1]->NAME = "Start";
    tmpbuttons.push_back(new Button(&this->game->window, sf::Text(L"?", this->game->font, 60), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Left, sf::Vector2f(155, 300), sf::Color(255,255,255)));
    tmpbuttons[2]->NAME = "1st Deck";
    tmpbuttons.push_back(new Button(&this->game->window, sf::Text(L"?", this->game->font, 60), GuiComponent::componentAlignment::Right, GuiComponent::componentAlignment::Right, sf::Vector2f(155, 300), sf::Color(255,255,255)));
    tmpbuttons[3]->NAME = "2nd Deck";
    tmpbuttons.push_back(new Button(&this->game->window, sf::Text(L"12", this->game->font, 45), GuiComponent::componentAlignment::Right, GuiComponent::componentAlignment::Center, sf::Vector2f(200, 50), sf::Color(255,255,255), sf::Color::Black, 2));
    tmpbuttons[4]->NAME = "DeckSize";
    tmpbuttons.push_back(new Button(&this->game->window, sf::Text("", this->game->font, 45), GuiComponent::componentAlignment::Right, GuiComponent::componentAlignment::Right, sf::Vector2f(50, 50), sf::Color(255,255,255), sf::Color::Black, 2));
    tmpbuttons[5]->NAME = "PlayerOrAI";
    tmpbuttons[5]->GetButtonRect().setTexture(&this->game->texturemanager.GetTextureRef("crossMark"));

    buttons.push_back(tmpbuttons);

    tmpbuttons.clear();

    /// 1st General Deck scene

    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"Все карты", this->game->font, 40), GuiComponent::componentAlignment::Top, GuiComponent::componentAlignment::Top, sf::Color::Black, sf::Color::White, 3));
    tmplabels[0]->NAME = "TopLabel";
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"Страница:", this->game->font, 30), GuiComponent::componentAlignment::Top, GuiComponent::componentAlignment::Top, sf::Color::Black, sf::Color::White, 3));
    tmplabels[1]->NAME = "PageLabel";
    tmplabels.push_back(new Label(&this->game->window, sf::Text("1", this->game->font, 30), GuiComponent::componentAlignment::Top, GuiComponent::componentAlignment::Top, sf::Color::Black, sf::Color::White, 3));
    tmplabels[2]->NAME = "CurrentPage";
    tmplabels.push_back(new Label(&this->game->window, sf::Text("/", this->game->font, 30), GuiComponent::componentAlignment::Top, GuiComponent::componentAlignment::Top, sf::Color::Black, sf::Color::White, 3));
    tmplabels[3]->NAME = "Slash";
    tmplabels.push_back(new Label(&this->game->window, sf::Text("1", this->game->font, 30), GuiComponent::componentAlignment::Top, GuiComponent::componentAlignment::Top, sf::Color::Black, sf::Color::White, 3));
    tmplabels[4]->NAME = "MaxPage";
    tmplabels[4]->SetString(sf::String(std::to_string(maxPage)));
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"ЛКМ - взять карту в колоду\nПКМ - войти в режим осмотра карты", this->game->font, 15), GuiComponent::componentAlignment::Bottom, GuiComponent::componentAlignment::Bottom, sf::Color::Black, sf::Color::White, 3));
    tmplabels[5]->NAME = "Hint";
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"0", this->game->font, 30), GuiComponent::componentAlignment::Center, GuiComponent::componentAlignment::TopLeft, sf::Color::Black, sf::Color::White, 3));
    tmplabels[6]->NAME = "1PDeckSizeLabelNUM";
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"Карт:", this->game->font, 30), GuiComponent::componentAlignment::Center, GuiComponent::componentAlignment::TopLeft, sf::Color::Black, sf::Color::White, 3));
    tmplabels[7]->NAME = "1PDeckSizeLabel";

    labels.push_back(tmplabels);

    tmplabels.clear();

    tmpbuttons.push_back(new Button(&this->game->window, sf::Text(L"Вернуться", this->game->font, 35), GuiComponent::componentAlignment::BottomLeft, GuiComponent::componentAlignment::BottomLeft, sf::Vector2f(300, 50), sf::Color(255,255,255)));
    tmpbuttons[0]->NAME = "ReturnMain";
    tmpbuttons[0]->Move(10, -10);
    tmpbuttons.push_back(new Button(&this->game->window, sf::Text(L"Колода 1-ого игрока", this->game->font, 25), GuiComponent::componentAlignment::BottomRight, GuiComponent::componentAlignment::BottomRight, sf::Vector2f(300, 50), sf::Color(255,255,255)));
    tmpbuttons[1]->NAME = "FirstPlayerDeck";
    tmpbuttons[1]->Move(-10, -10);
    tmpbuttons.push_back(new Button(&this->game->window, sf::Text(L">", this->game->font, 35), GuiComponent::componentAlignment::Right, GuiComponent::componentAlignment::Center, sf::Vector2f(70, 300), sf::Color(255,255,255)));
    tmpbuttons[2]->NAME = "Forward";
    tmpbuttons.push_back(new Button(&this->game->window, sf::Text(L"<", this->game->font, 35), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Vector2f(70, 300), sf::Color(255,255,255)));
    tmpbuttons[3]->NAME = "Back";

    buttons.push_back(tmpbuttons);

    tmpbuttons.clear();


    ///2nd General Deck scene

    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"Все карты", this->game->font, 40), GuiComponent::componentAlignment::Top, GuiComponent::componentAlignment::Top, sf::Color::Black, sf::Color::White, 3));
    tmplabels[0]->NAME = "TopLabel";
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"Страница:", this->game->font, 30), GuiComponent::componentAlignment::Top, GuiComponent::componentAlignment::Top, sf::Color::Black, sf::Color::White, 3));
    tmplabels[1]->NAME = "PageLabel";
    tmplabels.push_back(new Label(&this->game->window, sf::Text("1", this->game->font, 30), GuiComponent::componentAlignment::Top, GuiComponent::componentAlignment::Top, sf::Color::Black, sf::Color::White, 3));
    tmplabels[2]->NAME = "CurrentPage";
    tmplabels.push_back(new Label(&this->game->window, sf::Text("/", this->game->font, 30), GuiComponent::componentAlignment::Top, GuiComponent::componentAlignment::Top, sf::Color::Black, sf::Color::White, 3));
    tmplabels[3]->NAME = "Slash";
    tmplabels.push_back(new Label(&this->game->window, sf::Text("1", this->game->font, 30), GuiComponent::componentAlignment::Top, GuiComponent::componentAlignment::Top, sf::Color::Black, sf::Color::White, 3));
    tmplabels[4]->NAME = "MaxPage";
    tmplabels[4]->SetString(sf::String(std::to_string(maxPage)));
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"ЛКМ - взять карту в колоду\nПКМ - войти в режим осмотра карты", this->game->font, 15), GuiComponent::componentAlignment::Bottom, GuiComponent::componentAlignment::Bottom, sf::Color::Black, sf::Color::White, 3));
    tmplabels[5]->NAME = "Hint";
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"0", this->game->font, 30), GuiComponent::componentAlignment::Center, GuiComponent::componentAlignment::TopLeft, sf::Color::Black, sf::Color::White, 3));
    tmplabels[6]->NAME = "2PDeckSizeLabelNUM";
    tmplabels.push_back(new Label(&this->game->window, sf::Text(L"Карт:", this->game->font, 30), GuiComponent::componentAlignment::Center, GuiComponent::componentAlignment::TopLeft, sf::Color::Black, sf::Color::White, 3));
    tmplabels[7]->NAME = "2PDeckSizeLabel";

    labels.push_back(tmplabels);

    tmplabels.clear();

    tmpbuttons.push_back(new Button(&this->game->window, sf::Text(L"Вернуться", this->game->font, 35), GuiComponent::componentAlignment::BottomLeft, GuiComponent::componentAlignment::BottomLeft, sf::Vector2f(300, 50), sf::Color(255,255,255)));
    tmpbuttons[0]->NAME = "ReturnMain2";
    tmpbuttons[0]->Move(10, -10);
    tmpbuttons.push_back(new Button(&this->game->window, sf::Text(L"Колода 2-ого игрока", this->game->font, 25), GuiComponent::componentAlignment::BottomRight, GuiComponent::componentAlignment::BottomRight, sf::Vector2f(300, 50), sf::Color(255,255,255)));
    tmpbuttons[1]->NAME = "SecondPlayerDeck";
    tmpbuttons[1]->Move(-10, -10);
    tmpbuttons.push_back(new Button(&this->game->window, sf::Text(L">", this->game->font, 35), GuiComponent::componentAlignment::Right, GuiComponent::componentAlignment::Center, sf::Vector2f(70, 300), sf::Color(255,255,255)));
    tmpbuttons[2]->NAME = "Forward2";
    tmpbuttons.push_back(new Button(&this->game->window, sf::Text(L"<", this->game->font, 35), GuiComponent::componentAlignment::Left, GuiComponent::componentAlignment::Center, sf::Vector2f(70, 300), sf::Color(255,255,255)));
    tmpbuttons[3]->NAME = "Back2";

    buttons.push_back(tmpbuttons);

    tmpbuttons.clear();

    backgrdColor = sf::Color(237,119,41);
}

void GameStateCustomization::draw (const float dt)
{
    this->game->window.setView(view);

    for (auto comp : this->labels[currentScene])
    {
        if (comp->NAME != "WarningLabel") comp->Render(this->game->window);
        if (comp->NAME == "WarningLabel" && maxDeckSize < 12) comp->Render(this->game->window);
    }
    for (auto comp : this->buttons[currentScene])
    {
        comp->Render(this->game->window);
    }
    if (currentScene == SceneNum::FirstGeneralDeck)
    {
        for (auto comp : this->generalcards[currentPage-1])
        {
            if (!scaleMode && comp->isScaled == false) comp->Render(this->game->window);
            if (scaleMode && comp->isScaled == true) comp->Render(this->game->window);
        }
    }
    if (currentScene == SceneNum::SecondGeneralDeck)
    {
        for (auto comp : this->generalcards2[currentPage2-1])
        {
            if (!scaleMode && comp->isScaled == false) comp->Render(this->game->window);
            if (scaleMode && comp->isScaled == true) comp->Render(this->game->window);
        }
    }
}

void GameStateCustomization::update (const float dt)
{
    this->view.setSize(this->game->window.getSize().x, this->game->window.getSize().y);
    this->view.setCenter(this->game->window.getSize().x *0.5f, this->game->window.getSize().y*0.5f);

    switch (currentScene)
    {
        case SceneNum::Main:
            for (auto comp : this->labels[currentScene])
            {
                if (comp->NAME == "TopLabel"){ comp->SetPosition(GuiComponent::componentAlignment::Top); comp->Move(0,20); }
                if (comp->NAME == "1st Deck Label"){ comp->SetPosition(GuiComponent::componentAlignment::Left); comp->Move(60,-200); }
                if (comp->NAME == "2nd Deck Label"){ comp->SetPosition(GuiComponent::componentAlignment::Right); comp->Move(-60,-200); }
                if (comp->NAME == "DeckSizeLabel"){ comp->SetPosition(GuiComponent::componentAlignment::Center); comp->Move(0, -50); }
                if (comp->NAME == "PlayerOrAILabel"){ comp->SetPosition(GuiComponent::componentAlignment::Center); comp->Move(-20, 70); }
                if (comp->NAME == "1PDeckSizeLabel"){ comp->SetPosition(GuiComponent::componentAlignment::Left ); comp->Move(140, 200); }
                if (comp->NAME == "2PDeckSizeLabel"){ comp->SetPosition(GuiComponent::componentAlignment::Right ); comp->Move(-160, 200); }
                if (comp->NAME == "1PDeckSizeLabelNUM"){ comp->SetPosition(GuiComponent::componentAlignment::Left ); comp->Move(200, 199); }
                if (comp->NAME == "2PDeckSizeLabelNUM"){ comp->SetPosition(GuiComponent::componentAlignment::Right ); comp->Move(-100, 199); }
                if (comp->NAME == "WarningLabel"){ comp->SetPosition(GuiComponent::componentAlignment::BottomRight ); comp->Move(-10, -100); }
            }
            for (auto comp : this->buttons[currentScene])
            {
                if (comp->NAME == "Return") { comp->SetPosition(GuiComponent::componentAlignment::BottomLeft); comp->Move(10, -10); }
                if (comp->NAME == "Start") { comp->SetPosition(GuiComponent::componentAlignment::BottomRight); comp->Move(-10, -10); }
                if (comp->NAME == "1st Deck") { comp->SetPosition(GuiComponent::componentAlignment::Left); comp->Move(80, 0); }
                if (comp->NAME == "2nd Deck") { comp->SetPosition(GuiComponent::componentAlignment::Right); comp->Move(-80, 0); }
                if (comp->NAME == "DeckSize") { comp->SetPosition(GuiComponent::componentAlignment::Center); comp->Move(0, 0); }
                if (comp->NAME == "PlayerOrAI") { comp->SetPosition(GuiComponent::componentAlignment::Center); comp->Move(100, 70); }
            }
        break;

        case SceneNum::FirstGeneralDeck:
            for (auto comp : this->labels[currentScene])
            {
                if (comp->NAME == "TopLabel"){ comp->SetPosition(GuiComponent::componentAlignment::Top); comp->Move(0,20); }
                if (comp->NAME == "PageLabel"){ comp->SetPosition(GuiComponent::componentAlignment::Top); comp->Move(-70,120); }
                if (comp->NAME == "MaxPage"){ comp->SetPosition(GuiComponent::componentAlignment::Top); comp->Move(120,121); }
                if (comp->NAME == "Slash"){ comp->SetPosition(GuiComponent::componentAlignment::Top); comp->Move(80,120); }
                if (comp->NAME == "CurrentPage"){ comp->SetPosition(GuiComponent::componentAlignment::Top); comp->Move(40,121); }
                if (comp->NAME == "Hint"){ comp->SetPosition(GuiComponent::componentAlignment::Bottom); comp->Move(0,-100); }
                if (comp->NAME == "1PDeckSizeLabelNUM"){ comp->SetPosition(GuiComponent::componentAlignment::TopLeft ); comp->Move(130, 22); }
                if (comp->NAME == "1PDeckSizeLabel"){ comp->SetPosition(GuiComponent::componentAlignment::TopLeft ); comp->Move(20, 20); }
            }
            for (auto comp : this->buttons[currentScene])
            {
                if (comp->NAME == "ReturnMain") { comp->SetPosition(GuiComponent::componentAlignment::BottomLeft); comp->Move(10, -10); }
                if (comp->NAME == "FirstPlayerDeck") { comp->SetPosition(GuiComponent::componentAlignment::BottomRight); comp->Move(-10, -10); }
                if (comp->NAME == "Forward") { comp->SetPosition(GuiComponent::componentAlignment::Center); comp->Move(400, 0);comp->GetLabel().SetString(">");  }
                if (comp->NAME == "Forward" && currentPage == maxPage) { comp->GetLabel().SetString("X"); }
                if (comp->NAME == "Back") { comp->SetPosition(GuiComponent::componentAlignment::Center); comp->Move(-375, 0); comp->GetLabel().SetString("<"); }
                if (comp->NAME == "Back" && currentPage == 1) { comp->GetLabel().SetString("X"); }
            }
            for (auto comp : generalcards[currentPage-1])
            {
                comp->setPosition(GuiComponent::componentAlignment::Center);
                if (comp->CardID >= 0 && comp->CardID <= 3 && comp->isScaled == false) { comp->move(sf::Vector2f(-225+(160*comp->CardID),-100)); continue; }
                if (comp->CardID >= 4 && comp->CardID <= 7 && comp->isScaled == false) { comp->move(sf::Vector2f(-225+(160*(comp->CardID-4)),110)); continue; }
            }
        break;

        case SceneNum::SecondGeneralDeck:
            for (auto comp : this->labels[currentScene])
            {
                if (comp->NAME == "TopLabel"){ comp->SetPosition(GuiComponent::componentAlignment::Top); comp->Move(0,20); }
                if (comp->NAME == "PageLabel"){ comp->SetPosition(GuiComponent::componentAlignment::Top); comp->Move(-70,120); }
                if (comp->NAME == "MaxPage"){ comp->SetPosition(GuiComponent::componentAlignment::Top); comp->Move(120,121); }
                if (comp->NAME == "Slash"){ comp->SetPosition(GuiComponent::componentAlignment::Top); comp->Move(80,120); }
                if (comp->NAME == "CurrentPage"){ comp->SetPosition(GuiComponent::componentAlignment::Top); comp->Move(40,121); }
                if (comp->NAME == "Hint"){ comp->SetPosition(GuiComponent::componentAlignment::Bottom); comp->Move(0,-100); }
                if (comp->NAME == "2PDeckSizeLabelNUM"){ comp->SetPosition(GuiComponent::componentAlignment::TopLeft ); comp->Move(130, 22); }
                if (comp->NAME == "2PDeckSizeLabel"){ comp->SetPosition(GuiComponent::componentAlignment::TopLeft ); comp->Move(20, 20); }
            }
            for (auto comp : this->buttons[currentScene])
            {
                if (comp->NAME == "ReturnMain2") { comp->SetPosition(GuiComponent::componentAlignment::BottomLeft); comp->Move(10, -10); }
                if (comp->NAME == "SecondPlayerDeck") { comp->SetPosition(GuiComponent::componentAlignment::BottomRight); comp->Move(-10, -10); }
                if (comp->NAME == "Forward2") { comp->SetPosition(GuiComponent::componentAlignment::Center); comp->Move(400, 0);comp->GetLabel().SetString(">");  }
                if (comp->NAME == "Forward2" && currentPage2 == maxPage) { comp->GetLabel().SetString("X"); }
                if (comp->NAME == "Back2") { comp->SetPosition(GuiComponent::componentAlignment::Center); comp->Move(-375, 0); comp->GetLabel().SetString("<"); }
                if (comp->NAME == "Back2" && currentPage2 == 1) { comp->GetLabel().SetString("X"); }
            }
            for (auto comp : generalcards2[currentPage2-1])
            {
                comp->setPosition(GuiComponent::componentAlignment::Center);
                if (comp->CardID >= 0 && comp->CardID <= 3 && comp->isScaled == false) { comp->move(sf::Vector2f(-225+(160*comp->CardID),-100)); continue; }
                if (comp->CardID >= 4 && comp->CardID <= 7 && comp->isScaled == false) { comp->move(sf::Vector2f(-225+(160*(comp->CardID-4)),110)); continue; }
            }
        break;

    }

    for (auto comp : generalcards[currentPage-1])
    {
        ///Card Highlight
        if (comp->GetSpriteRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
        {
            if (!comp->isSelected) comp->GetBackRect().setFillColor(sf::Color(130,130,130));
            continue;
        }
        if (!comp->isSelected) comp->GetBackRect().setFillColor(sf::Color(210,210,210));
    }

    for (auto comp : generalcards2[currentPage2-1])
    {
        ///Card Highlight
        if (comp->GetSpriteRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
        {
            if (!comp->isSelected) comp->GetBackRect().setFillColor(sf::Color(130,130,130));
            continue;
        }
        if (!comp->isSelected) comp->GetBackRect().setFillColor(sf::Color(210,210,210));
    }

    ///Button Highlight
    for (auto comp : this->buttons[currentScene])
    {
        if (comp->GetButtonRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
        {
            if (comp->NAME == "Start") { comp->SetFillColor(sf::Color(37,153,42)); continue; }
            if (comp->NAME == "DeckSize" && typeMode == false) { comp->SetFillColor(sf::Color(240,240,240)); continue; }
            if (comp->NAME == "DeckSize" && typeMode == true) { comp->SetFillColor(sf::Color(200,200,200)); comp->SetOutLineColor(sf::Color::Blue); continue; }
            comp->SetFillColor(sf::Color(210,210,210));
            continue;
        }
        if (comp->NAME == "Start") { comp->SetFillColor(sf::Color(32,176,39)); continue; }
        if (comp->NAME == "DeckSize" && typeMode == true) { comp->SetFillColor(sf::Color(210,210,210)); comp->SetOutLineColor(sf::Color::Blue); continue; }
        else if (comp->NAME == "DeckSize" && typeMode == false) comp->SetFillColor(sf::Color(255,255,255)); comp->SetOutLineColor(sf::Color::Black);
        comp->SetFillColor(sf::Color(255, 255, 255));
    }
}

void GameStateCustomization::handleDeckSizeInput(sf::Event& event)
{
    if (typeMode && this->buttons[SceneNum::Main][4]->GetLabel().GetString() == "0") this->buttons[SceneNum::Main][4]->GetLabel().SetString(sf::String(""));
    if (typeMode && event.key.code == sf::Keyboard::Num0) { this->buttons[SceneNum::Main][4]->GetLabel().SetString(sf::String(this->buttons[SceneNum::Main][4]->GetLabel().GetString()+"0")); }
    if (typeMode && event.key.code == sf::Keyboard::Num1) { this->buttons[SceneNum::Main][4]->GetLabel().SetString(sf::String(this->buttons[SceneNum::Main][4]->GetLabel().GetString()+"1")); }
    if (typeMode && event.key.code == sf::Keyboard::Num2) { this->buttons[SceneNum::Main][4]->GetLabel().SetString(sf::String(this->buttons[SceneNum::Main][4]->GetLabel().GetString()+"2")); }
    if (typeMode && event.key.code == sf::Keyboard::Num3) { this->buttons[SceneNum::Main][4]->GetLabel().SetString(sf::String(this->buttons[SceneNum::Main][4]->GetLabel().GetString()+"3")); }
    if (typeMode && event.key.code == sf::Keyboard::Num4) { this->buttons[SceneNum::Main][4]->GetLabel().SetString(sf::String(this->buttons[SceneNum::Main][4]->GetLabel().GetString()+"4")); }
    if (typeMode && event.key.code == sf::Keyboard::Num5) { this->buttons[SceneNum::Main][4]->GetLabel().SetString(sf::String(this->buttons[SceneNum::Main][4]->GetLabel().GetString()+"5")); }
    if (typeMode && event.key.code == sf::Keyboard::Num6) { this->buttons[SceneNum::Main][4]->GetLabel().SetString(sf::String(this->buttons[SceneNum::Main][4]->GetLabel().GetString()+"6")); }
    if (typeMode && event.key.code == sf::Keyboard::Num7) { this->buttons[SceneNum::Main][4]->GetLabel().SetString(sf::String(this->buttons[SceneNum::Main][4]->GetLabel().GetString()+"7")); }
    if (typeMode && event.key.code == sf::Keyboard::Num8) { this->buttons[SceneNum::Main][4]->GetLabel().SetString(sf::String(this->buttons[SceneNum::Main][4]->GetLabel().GetString()+"8")); }
    if (typeMode && event.key.code == sf::Keyboard::Num9) { this->buttons[SceneNum::Main][4]->GetLabel().SetString(sf::String(this->buttons[SceneNum::Main][4]->GetLabel().GetString()+"9")); }
    if (typeMode && event.key.code == sf::Keyboard::BackSpace) { this->buttons[SceneNum::Main][4]->GetLabel().SetString(sf::String("0")); }
    if (typeMode && event.key.code == sf::Keyboard::Enter) { typeMode = false; }
    if (this->buttons[SceneNum::Main][4]->GetLabel().GetString() == "") this->buttons[SceneNum::Main][4]->GetLabel().SetString(sf::String("0"));
    if (this->buttons[SceneNum::Main][4]->GetLabel().GetString().getSize() > 2) this->buttons[SceneNum::Main][4]->GetLabel().SetString(sf::String("99"));
    if (std::stoi((std::string)this->buttons[SceneNum::Main][4]->GetLabel().GetString()) > 99) this->buttons[SceneNum::Main][4]->GetLabel().SetString(sf::String("99"));
    maxDeckSize = std::stoi((std::string)this->buttons[SceneNum::Main][4]->GetLabel().GetString());
    std::cout << "Max deck size for players: " << maxDeckSize << std::endl;
}

void GameStateCustomization::handleMouseBtnReleaseFirstGeneralDeck(sf::Event& event)
{
    for (auto& comp : generalcards[currentPage-1])
    {
        if (comp->GetSpriteRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
        {
            if (!scaleMode && event.mouseButton.button == sf::Mouse::Left)
            {
                if (!comp->isSelected)
                {
                    comp->GetBackRect().setFillColor(sf::Color(62,82,224));
                    comp->isSelected = true;
                    this->deck1.push_back(new Card(this->game, comp->GetCardName()));
                    this->deck1.back()->CardID = this->deck1.size()-1;
                    comp->CardPositionInPlayerDeck = this->deck1.back()->CardID;
                    std::cout << "the card was added to 1 player deck with this card ID: " << this->deck1.back()->CardID << std::endl;
                    labels[SceneNum::Main][5]->SetString(std::to_string(this->deck1.size()));
                    labels[SceneNum::FirstGeneralDeck][6]->SetString(std::to_string(this->deck1.size()));
                }
                else if (comp->isSelected)
                {
                    comp->GetBackRect().setFillColor(sf::Color(210,210,210));
                    comp->isSelected = false;
                    auto it = deck1.begin();
                    std::advance(it, comp->CardPositionInPlayerDeck);
                    delete this->deck1.at(comp->CardPositionInPlayerDeck);
                    this->deck1.erase(it);
                    comp->CardPositionInPlayerDeck = -1;
                    sortDeckByID(deck1, 1);
                    std::cout << "the card was deleted from 1 player deck with this card ID: " << comp->CardPositionInPlayerDeck << std::endl;
                    labels[SceneNum::Main][5]->SetString(std::to_string(this->deck1.size()));
                    labels[SceneNum::FirstGeneralDeck][6]->SetString(std::to_string(this->deck1.size()));
                }
            }
            else if (scaleMode && event.mouseButton.button == sf::Mouse::Right && comp->isScaled == true)
            {
                comp->setScale(1);
                this->scaleMode = false;
                break;
            }
            else if (!scaleMode && event.mouseButton.button == sf::Mouse::Right && comp->isScaled == false)
            {
                comp->setScale(2);
                this->scaleMode = true;
            }
        }
    }
}

void GameStateCustomization::handleMouseBtnReleaseSecondGeneralDeck(sf::Event& event)
{
    for (auto& comp : generalcards2[currentPage2-1])
    {
        if (comp->GetSpriteRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
        {
            if (!scaleMode && event.mouseButton.button == sf::Mouse::Left)
            {
                if (!comp->isSelected)
                {
                    comp->GetBackRect().setFillColor(sf::Color(62,82,224));
                    comp->isSelected = true;
                    this->deck2.push_back(new Card(this->game, comp->GetCardName()));
                    this->deck2.back()->CardID = this->deck2.size()-1;
                    comp->CardPositionInPlayerDeck = this->deck2.back()->CardID;
                    std::cout << "the card was added to 2 player deck with this card ID: " << this->deck2.back()->CardID << std::endl;
                    labels[SceneNum::Main][6]->SetString(std::to_string(this->deck2.size()));
                    labels[SceneNum::SecondGeneralDeck][6]->SetString(std::to_string(this->deck2.size()));
                }
                else if (comp->isSelected)
                {
                    comp->GetBackRect().setFillColor(sf::Color(210,210,210));
                    comp->isSelected = false;
                    auto it = deck2.begin();
                    std::advance(it, comp->CardPositionInPlayerDeck);
                    delete this->deck2.at(comp->CardPositionInPlayerDeck);
                    this->deck2.erase(it);
                    comp->CardPositionInPlayerDeck = -1;
                    sortDeckByID(deck2, 2);
                    std::cout << "the card was deleted from 1 player deck with this card ID: " << comp->CardPositionInPlayerDeck << std::endl;
                    labels[SceneNum::Main][6]->SetString(std::to_string(this->deck2.size()));
                    labels[SceneNum::SecondGeneralDeck][6]->SetString(std::to_string(this->deck2.size()));
                }
            }
            else if (scaleMode && event.mouseButton.button == sf::Mouse::Right && comp->isScaled == true)
            {
                comp->setScale(1);
                this->scaleMode = false;
                break;
            }
            else if (!scaleMode && event.mouseButton.button == sf::Mouse::Right && comp->isScaled == false)
            {
                comp->setScale(2);
                this->scaleMode = true;
            }
        }
    }
}



void GameStateCustomization::handleInput (const float dt)
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

            case sf::Event::KeyPressed:
                if (currentScene == SceneNum::Main) { handleDeckSizeInput(event); }
            break;

            case sf::Event::MouseButtonReleased:

                if (currentScene == SceneNum::FirstGeneralDeck) handleMouseBtnReleaseFirstGeneralDeck(event);

                if (currentScene == SceneNum::SecondGeneralDeck) handleMouseBtnReleaseSecondGeneralDeck(event);

                for (auto comp : this->buttons[currentScene])
                {
                    if (comp->GetButtonRect().getGlobalBounds().contains(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window))))
                    {
                        //Main scene
                        if (comp->NAME == "Start" && CanStartBattle() == true){ this->game->pushState(new GameStateBattle(this->game, &deck1, &deck2, maxDeckSize, playerIsBot, maxPHealth)); }
                        if (comp->NAME == "Return"){ this->game->popState();  }
                        if (comp->NAME == "1st Deck"){ changeScene(SceneNum::FirstGeneralDeck); }
                        if (comp->NAME == "2nd Deck"){ changeScene(SceneNum::SecondGeneralDeck); }
                        if (comp->NAME == "DeckSize" && typeMode == false){ typeMode = true; }
                        else if (comp->NAME == "DeckSize" && typeMode == true){ typeMode = false; }

                        if (comp->NAME == "PlayerOrAI" && this->playerIsBot == false){ playerIsBot = true; comp->GetButtonRect().setTexture(&this->game->texturemanager.GetTextureRef("crossMark")); }
                        else if (comp->NAME == "PlayerOrAI" && this->playerIsBot == true){ playerIsBot = false; comp->GetButtonRect().setTexture(&this->game->texturemanager.GetTextureRef("checkMark")); }

                        //First General scene
                        if (comp->NAME == "ReturnMain" && scaleMode == false) { changeScene(SceneNum::Main); this->currentPage = 1; }
                        if (comp->NAME == "FirstPlayerDeck") { std::cout << "\a"; }//changeScene(SceneNum::FirstPlayerDeck);
                        if (comp->NAME == "Forward" && currentPage < maxPage && scaleMode == false) { this->currentPage++; this->labels[SceneNum::FirstGeneralDeck][2]->SetString(sf::String(std::to_string(currentPage))); }
                        if (comp->NAME == "Back" && currentPage > 1 && scaleMode == false) { this->currentPage--; this->labels[SceneNum::FirstGeneralDeck][2]->SetString(sf::String(std::to_string(currentPage))); }

                        //Second General Scene
                        if (comp->NAME == "ReturnMain2" && scaleMode == false) { changeScene(SceneNum::Main); this->currentPage2 = 1; }
                        if (comp->NAME == "SecondPlayerDeck") { std::cout << "\a"; }//changeScene(SceneNum::SecondPlayerDeck);
                        if (comp->NAME == "Forward2" && currentPage2 < maxPage && scaleMode == false) { this->currentPage2++; this->labels[SceneNum::SecondGeneralDeck][2]->SetString(sf::String(std::to_string(currentPage2))); }
                        if (comp->NAME == "Back2" && currentPage2 > 1 && scaleMode == false) { this->currentPage2--; this->labels[SceneNum::SecondGeneralDeck][2]->SetString(sf::String(std::to_string(currentPage2))); }
                    }
                }
            break;


        }
    }
}

void GameStateCustomization::changeScene(GameStateCustomization::SceneNum newcurrentscene)
{
    this->currentScene = newcurrentscene;
}

void GameStateCustomization::sortDeckByID(std::vector<Card*>& deck, int generaldecknum)
{
    if (generaldecknum == 1)
    {
        int counter = 0;
        for (auto& comp : deck)
        {
            comp->CardID = counter;
            counter++;
        }
        counter = 0;
        int page = 1;
        for (auto& vect : generalcards)
        {
            for (auto& comp : generalcards[page-1])
            {
                if (comp->CardPositionInPlayerDeck != -1) { comp->CardPositionInPlayerDeck = counter; counter++; }
            }
            if (page != maxPage) page++;
        }
    }
    if (generaldecknum == 2)
    {
        int counter = 0;
        for (auto& comp : deck)
        {
            comp->CardID = counter;
            counter++;
        }
        counter = 0;
        int page = 1;
        for (auto& vect : generalcards2)
        {
            for (auto& comp : generalcards2[page-1])
            {
                if (comp->CardPositionInPlayerDeck != -1) { comp->CardPositionInPlayerDeck = counter; counter++; }
            }
            if (page != maxPage) page++;
        }
    }
}
void GameStateCustomization::buildBotsDeck()
{
    int decksetup = 1; //rand() % 5 + 1;
    std::cout << "bot's deck setup: " << decksetup << std::endl;

    int tmpID;
    int tmpPage;

    int i = 0;
    int j = 0;


    for (int i=0; i<maxDeckSize; i++)
    {
        this->deck2.push_back(new Card(this->game, Card::CardNames::T_34_76));
    }

}

bool GameStateCustomization::CanStartBattle()
{
    if (playerIsBot == true && AIchooseDeck == true)
    {
        buildBotsDeck();
    }

    if (this->deck1.size() == maxDeckSize && this->deck2.size() == maxDeckSize && maxDeckSize >= 12)
    {
        return true;
    }
    return false;
}

GameStateCustomization::~GameStateCustomization()
{
    int page = 0;
    int counter = 1;
    int sizeofarray;
    for (auto comp : generalcards[page])
    {
        sizeofarray = generalcards[page].size();
        delete comp;
        counter++;
        if (counter == sizeofarray && page != maxPage) page++;
    }

    page = 0;
    counter = 1;
    for (auto comp : generalcards2[page])
    {
        sizeofarray = generalcards2[page].size();
        delete comp;
        counter++;
        if (counter == sizeofarray && page != maxPage) page++;
    }

    int scene = 0;
    counter = 1;
    for (auto comp : buttons[scene])
    {
        sizeofarray = buttons[scene].size();
        delete comp;
        counter++;
        if (counter == sizeofarray && scene != 3) scene++;
    }

    scene = 0;
    counter = 1;
    for (auto comp : labels[scene])
    {
        sizeofarray = labels[scene].size();
        delete comp;
        counter++;
        if (counter == sizeofarray && scene != 3) scene++;
    }


    counter = 1;
    sizeofarray = deck1.size();
    for (auto comp : deck1)
    {
        delete comp;
    }

    counter = 0;
    sizeofarray = deck2.size();
    for (auto comp : deck2)
    {
        delete comp;
        counter++;
        std::cout << "I believe " << counter << " card of 2nd deck which was allocated was deleted properly" << std::endl;
    }

    std::cout << "It seems ~GameStateCustomization was invoked (probably)" << std::endl;
}

