#ifndef GameStateBattle_H
#define GameStateBattle_H

#include "Gui.h"
#include "Game.h"
#include "GameState.h"
#include "Card.h"

#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>
#include <cstdlib>

///
///Battle
///

class GameStateBattle : public GameState
{
    enum SceneNum
    {
        Battle,
        LoseScreen
    };

    enum Direction
    {
        None,
        Up,
        Down,
        Left,
        Right
    };

    enum class Phase
    {
        PlayCards,
        Attack,
        Wait
    };

    enum class WhoPlays
    {
        Player1, Player2
    };

    sf::View view;

    std::vector<Label*> labels;
    std::vector<Button*> buttons;

    std::vector<Button*> cardslots; //I use button because it is more common to me

    ///
    ///FOR GAME PROCESS
    ///

    std::vector<Card*> deck1;
    std::vector<Card*> deck2;

    std::vector<Card*> discarddeck1;
    std::vector<Card*> discarddeck2;

    std::vector<Card*> deckOnField1;
    std::vector<Card*> deckOnField2;

    std::vector<Card*> deckInHand1;
    std::vector<Card*> deckInHand2;

    int maxhandsize = 3;
    int maxdecksize;
    int maxPHealth ;

    bool playerIsBot = true;
    bool Player1FirstTurn = true;
    bool alreadySelected = false; /// For checking if you choose only one card at the time
    bool selectedOnField = false;
    bool firstTurnOfAllPlayers = true;

    bool movedCard = false;
    bool placedCard = false;

    WhoPlays whoplays;

    Phase phaseP1 = Phase::PlayCards;
    Phase phaseP2 = Phase::PlayCards;

    int income1P = 2;
    int income2P = 2;

    int health1P;
    int health2P;

    int money1P;
    int money2P;

    int turnnum = 1;

    int cardsInHand1 = 0;
    int cardsInDiscardDeck1 = 0;
    int cardsInMainDeck1 = 1;

    int cardsInHand2 = 0;
    int cardsInDiscardDeck2 = 0;
    int cardsInMainDeck2 = 0;

    void CameraMovement (const float dt);
    void MoveGUI(sf::Vector2f movement);
    Direction direction = Direction::None ;
    int camX = 0;
    int camY = 0;

    void Swap(Card* a, Card* b);
    void ShuffleDeck(std::vector<Card*>& deck);

    void PullCard1P(int newposinhand = -1);
    void PlayCard1P(sf::Vector2f slotpos);
    void DiscardCard1P();
    void ShuffleDiscardedCards1P();

    void PullCard2P(int newposinhand = -1);
    void DiscardCard2P();
    void ShuffleDiscardedCards2P();

    void AIplays();

    void NextTurn();

    bool FinishedGame();
public:

    virtual void draw (const float dt) override;

    virtual void update (const float dt) override;

    virtual void handleInput (const float dt) override;

    GameStateBattle (Game* game, std::vector<Card*>* deck1, std::vector<Card*>* deck2, int maxdecksize, bool playerIsBot, int maxPHealth);

    ~GameStateBattle ();
};

#endif // GameStateBattle_H

