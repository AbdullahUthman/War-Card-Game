#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Game.h"

Game::Game(Player playerA, Player playerB)
{
    this->playerA = playerA;
    this->playerB = playerB;
}

void Game::startGame()
{
    srand(time(0));
    mainDeck.initialize();
    Deck deckB = mainDeck.distribute(2);
    Deck deckA = mainDeck.distribute(1);
    deckB.shuffle();
    deckA.shuffle();
    playerB.setDeck(deckB);
    playerA.setDeck(deckA);
    cout << endl;
}

void Game::playRound()
{
    while (!checkVictory())
    {
        cout << endl
             << playerA.getName() << ", hit enter to draw your card.";
        cin.get();
        cout << endl;
        Card cardA = playerA.drawCard();
        if (checkVictory())
        {
            cout << "-----------------------------------" << endl;
            endGame();
        }

        cout << endl
             << playerB.getName() << ", hit enter to draw your card.";
        cin.get();
        cout << endl;
        Card cardB = playerB.drawCard();
        if (checkVictory())
        {
            endGame();
        }

        if (cardA == cardB)
        {
            if (!checkVictory())
            {
                cout << "-----------------------------------" << endl;
                declareWar();
                continue;
            }

            else
            {
                cout << "-----------------------------------" << endl;
                endGame();
                return;
            }
        }
        else if (cardA > cardB)
        {
            playerA.winRound(playerB.loseRound());
            if (!checkVictory())
            {
                cout << "-----------------------------------" << endl;
                continue;
            }

            else
            {
                cout << "-----------------------------------" << endl;
                endGame();
                return;
            }
        }
        else
        {
            playerB.winRound(playerA.loseRound());
            if (!checkVictory())
            {
                cout << "-----------------------------------" << endl;
                continue;
            }

            else
            {
                cout << "-----------------------------------" << endl;
                endGame();
                return;
            }
        }
    }
}

bool Game::checkVictory()
{
    if (playerA.hasNoCards() || playerB.hasNoCards())
    {
        return true;
    }

    else
    {
        return false;
    }
}

void Game::declareWinner()
{
    if (playerB.hasNoCards())
    {
        cout << endl;
        playerA.win();
        cout << endl;
        playerB.lose();
    }
    else
    {
        cout << endl;
        playerB.win();
        playerA.lose();
    }
}

void Game::declareWar()
{
    while (!checkVictory())
    {
        cout << endl
             << "It's a War!" << endl;
        if (!playerB.canPlayWar())
        {
            cout << endl
                 << playerB.getName() << " has insufficient cards" << endl;
            playerB.takeDeck();
            endGame();
            return;
        }

        else if (!playerA.canPlayWar())
        {
            playerA.takeDeck();
            cout << endl
                 << playerA.getName() << " has insufficient cards" << endl;
            playerA.takeDeck();
            endGame();
            return;
        }

        else
        {

            cout << playerA.getName() << ", Hit enter to draw four cards";
            cin.get();
            cout << endl;
            Card cardA = playerA.drawWarCards();
            if (checkVictory())
            {
                cout << "-----------------------------------" << endl;
                endGame();
                return;
            }

            cout << endl
                 << playerB.getName() << ", Hit enter to draw four cards";
            cin.get();
            cout << endl;
            Card cardB = playerB.drawWarCards();
            if (checkVictory())
            {
                cout << "-----------------------------------" << endl;
                endGame();
                return;
            }

            if (cardA == cardB)
            {
                if (!checkVictory())
                {
                    cout << "-----------------------------------" << endl;
                    continue;
                }

                else
                {
                    cout << "-----------------------------------" << endl;
                    endGame();
                    return;
                }
            }
            else if (cardA > cardB)
            {
                Deck temp = playerB.loseWar();
                playerA.winWar(temp);
                if (!checkVictory())
                {
                    cout << "-----------------------------------" << endl;
                    return;
                }

                else
                {
                    cout << "-----------------------------------" << endl;
                    endGame();
                    return;
                }
            }
            else
            {
                Deck temp = playerA.loseWar();
                playerB.winWar(temp);
                if (!checkVictory())
                {
                    cout << "-----------------------------------" << endl;
                    return;
                }

                else
                {
                    cout << "-----------------------------------" << endl;
                    endGame();
                    return;
                }

                break;
            }
        }
    }
}

void Game::endGame()
{
    declareWinner();
    char choice;
    cin.ignore();
    do
    {
        cout << endl
             << "Do you want to play Again? (y/n)" << endl;
        cin >> choice;

        switch (choice)
        {
        case 'Y':
        case 'y':
            startGame();
            playRound();
            break;

        case 'N':
        case 'n':
            cout << endl
                 << "Thank you for playing" << endl;
            exit(0);

        default:
            cout << endl
                 << "Invalid choice! Enter again: " << endl;
            cin >> choice;
        }
    } while (choice != 'n' && choice != 'N');
}