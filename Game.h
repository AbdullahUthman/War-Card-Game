#include "Player.h"

#ifndef Game_H
#define Game_H

class Game
{
private:
    Player playerA;
    Player playerB;
    Deck mainDeck;

public:
    Game(Player, Player);
    void startGame();
    void playRound();
    bool checkVictory();
    void declareWinner();
    void declareWar();
    void endGame();
};

#endif
