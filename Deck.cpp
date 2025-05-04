#include <iostream>
#include <cstdlib>
using namespace std;
#include "Card.h"
#include "Deck.h"

int Deck::getSize()
{
    return cards.size();
}

void Deck::initialize()
{
    string suit[4] = {"Diamonds", "Clubs", "Hearts", "Spades"};
    string rank[12] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Queen", "King", "Ace"};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            Card temp;
            temp.setSuit(suit[i]);
            temp.setRank(rank[j]);
            temp.setRankValue(j + 1);

            cards.push_back(temp);
        }
    }
}

void Deck::addCard(Card card)
{
    cards.push_back(card);
}

Card Deck::removeCard()
{
    Card temp = cards.back();
    cards.pop_back();
    return temp;
}

void Deck::clearDeck()
{
    cards.clear();
}

void Deck::displayCard(Card cardToDisplay)
{
    cardToDisplay.displayDetails();
}

void Deck::shuffle()
{
    for (int i = cards.size() - 1; i > 0; i--)
    {
        int n = rand() % (i + 1);
        Card temp = cards[i];
        cards[i] = cards[n];
        cards[n] = temp;
    }
}

Deck Deck::distribute(int playerId)
{
    int deckSize = cards.size() / playerId;
    Deck playerDeck;
    for (int i = 0; i < deckSize; i++)
    {
        playerDeck.addCard(this->removeCard());
    }
    return playerDeck;
}

bool Deck::isEmpty()
{
    if (cards.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
