#include <iostream>
#include "Player.h"
#include "Deck.h"

Player::Player()
{
    id = 0;
    name = "N/A";
}

Player::Player(int id, string name)
{
    this->name = name;
    this->id = id;
}

void Player::setDeck(Deck deck)
{
    this->deck = deck;
    cout << endl
         << name << " has a deck of " << deck.getSize() << " cards" << endl;
}

string Player::getName()
{
    return name;
}

Card Player::drawWarCards()
{
    Card drawnCard; // adds 4 cards to the 'warCardsDrawn' vector, removes them from the deck and returns the 4th one
    for (int i = 0; i < 4; i++)
    {
        drawnCard = deck.removeCard();
        warCardsDrawn.addCard(drawnCard);
    }
    cout << name << " drew ";
    deck.displayCard(drawnCard);
    cout << " at last" << endl;
    return drawnCard;
}

Card Player::drawCard()
{
    Card drawnCard = deck.removeCard();
    cout << name << " drew ";
    deck.displayCard(drawnCard);
    cout << endl;
    return drawnCard;
}

void Player::takeDeck()
{
    deck.clearDeck();
}

void Player::win()
{
    cout << name << " has won the game! " << endl;
}

void Player::lose()
{
    cout << name << " has lost the game" << endl;
}

void Player::winRound(Card cardWon)
{
    cout << endl
         << name << " won both cards" << endl;
    deck.addCard(cardWon);
}

Card Player::loseRound()
{
    cout << endl
         << name << " lost his card" << endl;
    Card cardLost = deck.removeCard();
    return cardLost;
}

void Player::winWar(Deck cardsWon)
{
    cout << endl
         << name << " won the war" << endl;
    Card temp;
    for (int i = 0; i < 4; i++)
    { // to add own cards drawn, back to the deck
        temp = warCardsDrawn.removeCard();
        deck.addCard(temp);
    }

    for (int i = 0; i < 4; i++)
    { // to add the other players' cards won, to the deck
        temp = cardsWon.removeCard();
        deck.addCard(temp);
    }
}

Deck Player::loseWar()
{
    cout << endl
         << name << " lost the war" << endl;
    return warCardsDrawn;
}

bool Player::hasNoCards()
{
    if (deck.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Player::canPlayWar()
{
    if (deck.getSize() >= 4)
    {
        return true;
    }

    else
    {
        return false;
    }
}