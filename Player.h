#include <string>
using namespace std;

#include "Deck.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
    Deck deck;
    Deck warCardsDrawn;
    int id;
    string name;

public:
    Player();
    Player(int, string);
    void setDeck(Deck);
    string getName();
    Card drawWarCards();
    Card drawCard();
    void takeDeck();
    void winRound(Card);
    Card loseRound();
    void winWar(Deck);
    Deck loseWar();
    void win();
    void lose();
    bool hasNoCards();
    bool canPlayWar();
};

#endif