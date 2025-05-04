#include <iostream>
#include "Card.h"

string Card::getRank()
{
    return rank;
}

void Card::setRank(string rank)
{
    this->rank = rank;
}

int Card::getRankValue()
{
    return rankValue;
}

void Card::setRankValue(int rankValue)
{
    this->rankValue = rankValue;
}

string Card::getSuit()
{
    return suit;
}

void Card::setSuit(string suit)
{
    this->suit = suit;
}

void Card::displayDetails()
{
    cout << rank << " of " << suit;
}

bool Card::operator<(const Card &card) const
{
    if (this->rankValue < card.rankValue)
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool Card::operator>(const Card &card) const
{
    if (this->rankValue > card.rankValue)
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool Card::operator==(const Card &card) const
{
    if (this->rankValue == card.rankValue)
    {
        return true;
    }

    else
    {
        return false;
    }
}