#ifndef Card_H
#define Card_H

#include "Game.h"
#include "GameObject.h"
#include "Gui.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Card : public GameObject
{
public:
    enum class CardNames
    {
        T_34_76, T_34_85, IS_2, SU_100, MS_1, LTvz38, TigerI, Hetzer, TigerII, PzIII, IS_1, KV_1, SU_152, ISU_152, Panther, Lowe, MarderI, PzI,
        StugIIIG
    };
    enum class CardTypes
    {
        LightTank, MediumTank, HeavyTank, TankDestroyer, Building, AAG, Artillery, Spell
    };
    enum class CardNations
    {
        Neutral, USSR, USA, UK, France, Wehrmacht
    };
    enum class CardAbilities
    {
        None, Protection_1_if_1, Damage_1_if_Wehrmacht, ImmediateAttack, Heal_1HP_Ally_After_Play, Protection_1_VS_MT, DodgeLess_1_VS_MT_and_LT,
        Ricochet_if_1, Endurance_1_if_enemy_more_than_3, Damage_4_if_MT_and_LT, Only_1_DMG, Get_1_Acr_if_HT
    };
    enum class CardAttackDirections
    {
        Forward, ThreeLines, Right, Left
    };
private:
    Game* game;

    sf::RectangleShape sprite;

    sf::RectangleShape backrect; // back rectangle shape

    std::vector<Label*> labels;

    //Label* label HP; // Hit points
    //Label* label DMG; // Damage
    //Label* label ACR; // Accuracy

    float scaled = 1;

public:

    Card::CardTypes cardType;
    Card::CardNations cardNation;
    Card::CardAbilities cardAbility;
    Card::CardAttackDirections cardAttackDirection;

    bool canAttackBase = true;
    bool canPierce = false;


    bool isSelected = false;
    bool isScaled = false;
    bool isOnField = false;
    bool hasAttacked = false;
    bool canShoot = false;
    bool underAttack = false;

    int posOnField = -1;

    int nextturn = -1;

    int posInHand  = -1;

    float scaleofdescr = 1;

    int armor = 0;
    int income;
    int cost;
    int hp;
    int dmg;
    int acr;
    int penetration = 0;

    int cur_armor = 0;
    int cur_hp;
    int cur_dmg;
    int cur_acr;

    Card::CardNames cardName;

    int CardID = -1;

    int CardPositionInPlayerDeck = -1; // this is made for general deck

    Card() = delete;

    Card(Game* game, Card::CardNames cardname);

    Card(const Card& other) = default;

    ~Card();

    CardNames GetCardName();

    std::string GetCardNameInString();

    sf::RectangleShape& GetSpriteRect();

    sf::RectangleShape& GetBackRect();

    void InitCard();

    void Render(sf::RenderWindow& renderwindow) override;

    void Update();

    void setPosition(const sf::Vector2f& position);

    void setPosition(const GuiComponent::componentAlignment& position);

    void move(const sf::Vector2f& offset);

    void setScale(float factor);

    void setSizeX2();
};

#endif // Card_H
