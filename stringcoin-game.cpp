// Name:       Tom Kwok Kei
// Student ID: 1155172220
// Email:      1155172220@link.cuhk.edu.hk

#include <iostream>
#include "stringcoin.h"
using namespace std;

int main()
{
    long long network = 1111111111111111100;
    printNetwork(network);
    int input; // for storing user input.
    int player = 1; // initial player
    int score1 = 0; // old score of player 1
    int score2 = 0; // old score of player 2
    while (network > 99) {
        cout << "Player " << player << "'s move (1-17): ";
        cin >> input;
        //check if the input is within 1-17
        if (input > 17 || input < 1) {
            cout << "Invalid. Try again!" << endl;
            continue;
        }
        
        //check if the position of the respected input is cut or not
        else if (!stringState(network, input)) {
            cout << "Invalid. Try again!" << endl;
            continue;
        }
        
        // if the input is valid, proceed to the next step
        else {
            updateNetwork(network, input, player);
            //if it was player 1's turn
            if (player == 1) {
                // end the game instantly if all strings are cut, avoid printing extra turn message
                if (network < 100) {
                    printNetwork(network);
                    break;
                }
                //if player 1 scores, player 1 keeps picking
                if (playerScore(network, player) > score1) {
                    player = 1;
                    score1 = playerScore(network, player);
                    cout << "Player " << player << " scores! Gets extra turn." << endl;
                    printNetwork(network);
                }
                //if player 1 did not score, swap to player 2
                else {
                    player = 2;
                    printNetwork(network);
                }
            }
            //if it was player 2's turn
            else if (player == 2) {
                // end the game instantly if all strings are cut, avoid printing extra turn message
                if (network < 100) {
                    printNetwork(network);
                    break;
                }
                //if player 2 scores, player 2 keeps picking
                if (playerScore(network, player) > score2) {
                    player = 2;
                    score2 = playerScore(network, player);
                    cout << "Player " << player << " scores! Gets extra turn." << endl;
                    printNetwork(network);
                }
                //if player 2 did not score, swap to player 1
                else {
                    player = 1;
                    printNetwork(network);
                }
            }     
        }
    }
    
    //message of player 1 winning
    if (playerScore(network, 1) > playerScore(network, 2)) {
        cout << "Player 1 wins!";
    }

    //message of player 2 winning
    else if (playerScore(network, 2) > playerScore(network, 1)) {
        cout << "Player 2 wins!";
    }

    //message of a draw game
    else {
        cout << "Draw game!";
    }

}


