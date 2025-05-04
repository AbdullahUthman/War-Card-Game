#include <string>
using namespace std;
#ifndef CARD_H
#define CARD_H

class Card
{
private:
    string rank;
    int rankValue;
    string suit;

public:
    string getRank();
    void setRank(string);
    int getRankValue();
    void setRankValue(int);
    void setSuit(string);
    string getSuit();
    void displayDetails();
    bool operator<(const Card &) const;
    bool operator>(const Card &) const;
    bool operator==(const Card &) const;
};

#endif
