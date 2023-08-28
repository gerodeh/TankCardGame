#include "Card.h"

void Card::InitCard()
{
     switch (this->cardName)
    {
        case Card::CardNames::T_34_76:
        this->hp = cur_hp = 2;
        this->dmg = cur_dmg = 1;
        this->acr = cur_acr = 3;
        this->penetration = 0;
        this->income = 1;
        this->cost = 2;
        this->cardType  = Card::CardTypes::MediumTank;
        this->cardNation = Card::CardNations::USSR;
        this->cardAbility = Card::CardAbilities::Protection_1_if_1;
        this->cardAttackDirection = Card::CardAttackDirections::Forward;
        this->sprite.setTexture(&this->game->texturemanager.GetTextureRef("T-34-76"));
        //this->labels[4]->SetString(sf::String(L"1 защита с шансом \n1/6"));
        break;

        case Card::CardNames::T_34_85:
        this->hp = cur_hp = 2;
        this->dmg = cur_dmg = 2;
        this->acr = cur_acr = 4;
        this->penetration = 0;
        this->income = 2;
        this->cost = 3;
        this->cardType  = Card::CardTypes::MediumTank;
        this->cardNation = Card::CardNations::USSR;
        this->cardAbility = Card::CardAbilities::None;
        this->cardAttackDirection = Card::CardAttackDirections::Forward;
        this->sprite.setTexture(&this->game->texturemanager.GetTextureRef("T-34-85"));
        break;

        case Card::CardNames::SU_100:
        this->hp = cur_hp = 2;
        this->dmg = cur_dmg = 2;
        this->acr = cur_acr = 3;
        this->penetration = 0;
        this->income = 2;
        this->cost = 3;
        this->cardType  = Card::CardTypes::TankDestroyer;
        this->cardNation = Card::CardNations::USSR;
        this->cardAbility = Card::CardAbilities::Damage_1_if_Wehrmacht;
        this->cardAttackDirection = Card::CardAttackDirections::Forward;
        this->sprite.setTexture(&this->game->texturemanager.GetTextureRef("SU-100"));
        //this->labels[4]->SetString(sf::String(L"+1 DMG против\nнемецких танков"));
        break;

        case Card::CardNames::IS_2:
        this->hp = cur_hp = 4;
        this->dmg = cur_dmg = 3;
        this->acr = cur_acr = 3;
        this->penetration = 0;
        this->income = 3;
        this->cost = 6;
        this->cardType  = Card::CardTypes::HeavyTank;
        this->cardNation = Card::CardNations::USSR;
        this->cardAbility = Card::CardAbilities::ImmediateAttack;
        this->cardAttackDirection = Card::CardAttackDirections::Forward;
        this->sprite.setTexture(&this->game->texturemanager.GetTextureRef("IS-2"));
        //this->labels[4]->SetString(sf::String(L"Бьет сразу после\nвыхода на поле"));
        break;

        case Card::CardNames::MS_1:
        this->hp = cur_hp = 1;
        this->dmg = cur_dmg = 0;
        this->acr = cur_acr = 3;
        this->penetration = 0;
        this->income = 0;
        this->cost = 0;
        this->cardType  = Card::CardTypes::LightTank;
        this->cardNation = Card::CardNations::USSR;
        this->cardAbility = Card::CardAbilities::None;
        this->cardAttackDirection = Card::CardAttackDirections::Forward;
        this->sprite.setTexture(&this->game->texturemanager.GetTextureRef("MS-1"));
        break;

        case Card::CardNames::LTvz38:
        this->hp = cur_hp = 1;
        this->dmg = cur_dmg = 1;
        this->acr = cur_acr = 3;
        this->penetration = 0;
        this->income = 1;
        this->cost = 2;
        this->cardType  = Card::CardTypes::LightTank;
        this->cardNation = Card::CardNations::Wehrmacht;
        this->cardAbility = Card::CardAbilities::Heal_1HP_Ally_After_Play;
        this->cardAttackDirection = Card::CardAttackDirections::Forward;
        this->sprite.setTexture(&this->game->texturemanager.GetTextureRef("LT vz.38"));
        //this->labels[4]->SetString(sf::String(L"Лечит 1 ОЗ\nсоюзному танку после\nвыхода на поле"));
        //this->labels[4]->SetScale(sf::Vector2f(0.8f,0.8f));
        this->scaleofdescr = 0.8f;
        break;

        case Card::CardNames::TigerI:
        this->hp = cur_hp = 4;
        this->dmg = cur_dmg = 2;
        this->acr = cur_acr = 4;
        this->penetration = 0;
        this->income = 3;
        this->cost = 5;
        this->cardType  = Card::CardTypes::HeavyTank;
        this->cardNation = Card::CardNations::Wehrmacht;
        this->cardAbility = Card::CardAbilities::Protection_1_VS_MT;
        this->cardAttackDirection = Card::CardAttackDirections::Forward;
        this->sprite.setTexture(&this->game->texturemanager.GetTextureRef("TigerI"));
        //this->labels[4]->SetString(sf::String(L"Лечит 1 ОЗ\nсоюзному танку после\nвыхода на поле"));
        break;

        case Card::CardNames::Hetzer:
        this->hp = cur_hp = 1;
        this->dmg = cur_dmg = 1;
        this->acr = cur_acr = 4;
        this->penetration = 1;
        this->income = 1;
        this->cost = 2;
        this->cardType  = Card::CardTypes::TankDestroyer;
        this->cardNation = Card::CardNations::Wehrmacht;
        this->cardAbility = Card::CardAbilities::None;
        this->cardAttackDirection = Card::CardAttackDirections::Forward;
        this->sprite.setTexture(&this->game->texturemanager.GetTextureRef("Hetzer"));
        break;

        case Card::CardNames::TigerII:
        this->hp = cur_hp = 4;
        this->dmg = cur_dmg = 2;
        this->acr = cur_acr = 4;
        this->penetration = 0;
        this->income = 4;
        this->cost = 6;
        this->armor = cur_armor = 1;
        this->cardType  = Card::CardTypes::HeavyTank;
        this->cardNation = Card::CardNations::Wehrmacht;
        this->cardAbility = Card::CardAbilities::DodgeLess_1_VS_MT_and_LT;
        this->cardAttackDirection = Card::CardAttackDirections::Forward;
        this->sprite.setTexture(&this->game->texturemanager.GetTextureRef("TigerII"));
        break;

        case Card::CardNames::PzIII:
        this->hp = cur_hp = 1;
        this->dmg = cur_dmg = 1;
        this->acr = cur_acr = 4;
        this->penetration = 0;
        this->income = 1;
        this->cost = 1;
        this->cardType  = Card::CardTypes::MediumTank;
        this->cardNation = Card::CardNations::Wehrmacht;
        this->cardAbility = Card::CardAbilities::None;
        this->cardAttackDirection = Card::CardAttackDirections::Forward;
        this->sprite.setTexture(&this->game->texturemanager.GetTextureRef("Pz.III"));
        break;
    }

    labels[0]->SetString(std::to_string(this->cur_hp));
    labels[1]->SetString(std::to_string(this->cur_dmg));
    labels[2]->SetString(std::to_string(this->cost));
    labels[3]->SetString(std::to_string(this->cur_acr));
    if (cur_armor > 0 || armor > 0) labels[5]->SetString(std::to_string(this->cur_armor));
}

Card::Card(Game* game, Card::CardNames cardname)
{
    this->game = game;
    this->cardName = cardname;

    this->backrect.setFillColor(sf::Color(210,210,210));
    this->backrect.setSize(sf::Vector2f(157,207));
    setOriginByAlignment(backrect, this->game->window, GuiComponent::componentAlignment::Center);
    this->sprite.setSize(sf::Vector2f(150,200));
    setOriginByAlignment(sprite, this->game->window, GuiComponent::componentAlignment::Center);
    this->backrect.setPosition(sf::Vector2f(0, 0));

    this->labels.push_back(new Label(&this->game->window, sf::Text("0", this->game->fontforCards, 17), sf::Vector2f(0,0), sf::Color::Black));
    labels[0]->NAME = "HP";
    labels[0]->SetOrigin(GuiComponent::componentAlignment::Center);
    labels[0]->SetPosition(59,84);
    this->labels.push_back(new Label(&this->game->window, sf::Text("0", this->game->fontforCards, 17), sf::Vector2f(0,0), sf::Color::Black));
    labels[1]->NAME = "DMG";
    labels[1]->SetOrigin(GuiComponent::componentAlignment::Center);
    labels[1]->SetPosition(-59, 84);
    this->labels.push_back(new Label(&this->game->window, sf::Text("0", this->game->fontforCards, 14), sf::Vector2f(0,0), sf::Color::Black));
    labels[2]->NAME = "COST";
    labels[2]->SetOrigin(GuiComponent::componentAlignment::Center);
    labels[2]->SetPosition(59,13);
    this->labels.push_back(new Label(&this->game->window, sf::Text("0", this->game->fontforCards, 14), sf::Vector2f(0,0), sf::Color::Black));
    labels[3]->NAME = "ACR";
    labels[3]->SetOrigin(GuiComponent::componentAlignment::Center);
    labels[3]->SetPosition(-64, 56.5f);
    this->labels.push_back(new Label(&this->game->window, sf::Text("", this->game->fontforCards, 12), sf::Vector2f(0,0), sf::Color::Black));
    labels[4]->NAME = "DESCRIPTION";
    labels[4]->SetOrigin(GuiComponent::componentAlignment::Center);
    labels[4]->SetPosition(-55, 12);
    this->labels.push_back(new Label(&this->game->window, sf::Text("", this->game->fontforCards, 15), sf::Vector2f(0,0), sf::Color::Black));
    labels[5]->NAME = "ARMOR";
    labels[5]->SetOrigin(GuiComponent::componentAlignment::Center);
    labels[5]->SetPosition(-62, 14);


    InitCard();
}

Card::~Card()
{ //IT CRASHES THE GAME FOR SOME REASON
    /*delete labels[0];
    delete labels[1];
    delete labels[2];
    delete labels[3];
    delete labels[4];
    labels.clear();
    labels.shrink_to_fit();*/
}

Card::CardNames Card::GetCardName()
{
    return this->cardName;
}

void Card::Render(sf::RenderWindow& renderwindow)
{
    renderwindow.draw(this->backrect);
    renderwindow.draw(this->sprite);
    for (auto lbl : labels)
    {
        lbl->Render(renderwindow);
    }
}

void Card::setPosition(const sf::Vector2f& position)
{
    this->sprite.setPosition(position);
    this->backrect.setPosition(position);
    for (int i=0; i<6; i++)
    {
        this->labels[i]->SetPosition(position);
    }
    labels[0]->Move(59,84);
    labels[1]->Move(-59, 84);
    labels[2]->Move(59,13);
    labels[3]->Move(-64, 56.5f);
    labels[4]->Move(-66, 8);
    labels[5]->Move(54,48);
}

void Card::setPosition(const GuiComponent::componentAlignment& position)
{
    setPositionByAlignment(this->sprite, this->game->window, position);
    setPositionByAlignment(this->backrect, this->game->window, position);
    for (int i=0; i<6; i++)
    {
        this->labels[i]->SetPosition(position);
    }
    if (isScaled)
    {
        labels[0]->Move(59*scaled,84*scaled);
        labels[1]->Move(-59*scaled, 84*scaled);
        labels[2]->Move(59*scaled,13*scaled);
        labels[3]->Move(-64*scaled, 56.5f*scaled);
        labels[4]->Move(-66*scaled, 8*scaled);
        labels[5]->Move(54*scaled, 48*scaled);
    }
    if (!isScaled)
    {
        labels[0]->Move(59,84);
        labels[1]->Move(-59, 84);
        labels[2]->Move(59,13);
        labels[3]->Move(-64, 56.5f);
        labels[4]->Move(-66, 8);
        labels[5]->Move(54,48);
    }

}

void Card::move(const sf::Vector2f& offset)
{
    this->sprite.move(offset);
    this->backrect.move(offset);
    if (!isScaled)
    {
        for (int i=0; i<6; i++)
        {
            this->labels[i]->Move(offset);
        }
    }
    if (isScaled)
    {
        for (int i=0; i<6; i++)
        {
            this->labels[i]->Move(offset*scaled);
        }
    }
}
 void Card::setScale(float factor)
 {
    //sf::Vector2f tmpforsprite = this->sprite.getPosition();
    //sf::Vector2f tmpforlabels;
    this->sprite.setScale(factor, factor);
    //this->sprite.setPosition(0,0);
    //setOriginByAlignment(sprite, this->game->window, GuiComponent::componentAlignment::Center);

    this->backrect.setScale(factor, factor);
    //this->backrect.setPosition(0,0);
    //setOriginByAlignment(backrect, this->game->window, GuiComponent::componentAlignment::Center);

    for (int i=0; i<6; i++)
    {
        this->labels[i]->SetScale(sf::Vector2f(factor, factor));
    }
    if (factor == 1) this->labels[4]->SetScale(sf::Vector2f(scaleofdescr, scaleofdescr));
    if (factor != 1) this->labels[4]->SetScale(sf::Vector2f(scaleofdescr*factor, scaleofdescr*factor));
    //labels[0]->Move(59*factor,84*factor);
    //labels[1]->Move(-59*factor, 84*factor);
    //labels[2]->Move(59*factor,13*factor);
    //labels[3]->Move(-64*factor, 56.5*factor);
    //labels[4]->Move(-66*factor, 8*factor);

    if (factor != 1) this->isScaled = true;
    if (factor == 1) this->isScaled = false;
    this->scaled = factor;
 }

sf::RectangleShape& Card::GetSpriteRect()
{
    return this->sprite;
}

sf::RectangleShape& Card::GetBackRect()
{
    return this->backrect;
}

std::string Card::GetCardNameInString()
{
    switch (this->cardName)
    {
        case Card::CardNames::T_34_76:
            return "T-34-76";
        break;

        case Card::CardNames::T_34_85:
            return "T-34-85";
        break;

        case Card::CardNames::SU_100:
            return "SU-100";
        break;

        case Card::CardNames::IS_2:
            return "IS-2";
        break;

        case Card::CardNames::MS_1:
            return "MS-1";
        break;

        case Card::CardNames::LTvz38:
            return "Ltvz38";
        break;

        case Card::CardNames::TigerI:
            return "TigerI";
        break;

        case Card::CardNames::Hetzer:
            return "Hetzer";
        break;

        case Card::CardNames::TigerII:
            return "TigerII";
        break;

        case Card::CardNames::PzIII:
            return "PzIII";
        break;
    }
    return "Nothing";
}

/*
Card::Card(const Card& other)
{
    this->game = other.game;

    this->sprite = other.sprite;

    this->backrect = other.backrect;

    this->labels = other.labels;

    this->scaled = other.scaled;

    this->cardType = other.cardType;
    this->cardNation = other.cardNation;
    this->cardAbility = other.cardAbility;
    this->cardAttackDirection = other.cardAttackDirection;

    this->canAttackBase = other.canAttackBase;
    this->canPierce = other.canPierce;

    this->isSelected = other.isSelected;
    this->isScaled = other.isScaled;

    this->scaleofdescr = other.scaleofdescr;

    this->armor = other.armor;
    this->income = other.income;
    this->cost = other.cost;
    this->hp = other.hp;
    this->dmg = other.dmg;
    this->acr = other.acr;
    this->penetration = other.penetration;

    this->cur_armor = other.cur_armor;
    this->cur_hp = other.cur_hp;
    this->cur_dmg = other.cur_dmg;
    this->cur_acr = other.cur_acr;

    this->cardName = other.cardName;

    this->CardID = other.CardID;

    this->CardPositionInPlayerDeck = other.CardPositionInPlayerDeck;
}*/
