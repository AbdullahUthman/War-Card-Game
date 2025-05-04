#include <vector>
#include "Card.h"
#ifndef DECK_H
#define DECK_H

class Deck
{
private:
    vector<Card> cards;

public:
    int getSize();
    void addCard(Card);
    void initialize();
    Card removeCard();
    void clearDeck();
    void displayCard(Card);
    void shuffle();
    Deck distribute(int);
    bool isEmpty();
};

#endif