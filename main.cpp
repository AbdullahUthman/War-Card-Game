#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"

int main()
{
    std::string player1Name, player2Name;
    std::cout << "Player 1, Enter your name: ";
    std::cin >> player1Name;
    std::cout << "Player 2, Enter your name: ";
    std::cin >> player2Name;
    std::cout << endl;

    Player player1(1, player1Name);
    Player player2(2, player2Name);
    Game mainGame(player1, player2);
    cin.ignore();
    mainGame.startGame();
    mainGame.playRound();
    return 0;
}
