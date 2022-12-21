// Name:       Tom Kwok Kei
// Student ID: 1155172220
// Email:      1155172220@link.cuhk.edu.hk

#include "stringcoin.h"
#include <iostream>
#include <string>
using namespace std;

/* Returns true if position pos of the game network still has a string (not cut
   yet); returns false otherwise (that is, string was already cut). */
bool stringState(long long network, int pos) {
    // TO DO; add a return statement in order to compile
    int i;
    long long num = 1; //store the power calculation for further use.
    //for loop to do the power calculation.
    for (i = 1; i <= 19 - pos; i++)
    {
        num = num * 10;
    }
    bool state = (network / num) % 10; //divide the given network with the result of for loop, 
                                       //find the remainder of the respected division and turn it into boolean value,
                                       //1 represents true and 0 represents false.
    return state;
}

/* Prints the network to the screen. Do NOT modify! Do NOT use any arrays
   outside this function! */
void printNetwork(long long network) {
    int i;
    string s[18];    // Do NOT use any arrays outside this function!

    for (i = 1; i <= 17; i++)
        if (i <= 3 || i >= 15 || (i >= 8 && i <= 10))
            s[i] = stringState(network, i) ? "|" : " ";
        else
            s[i] = stringState(network, i) ? "--" : "  ";

    cout << "*************\n";
    for (i = 1; i <= 17; i += 7) {
        cout << "*  " << s[i] << "  " << s[i + 1] << "  " << s[i + 2]
             << "  *\n";
        if (i < 15)
            cout << "*" << s[i + 3] << "$" << s[i + 4] << "$" << s[i + 5]
                 << "$" << s[i + 6] << "*\n";
    }
    cout << "*************\n";
    cout << "Player 1 score: " << network / 10 % 10 << endl;
    cout << "Player 2 score: " << network % 10 << endl;
}

/* Returns the score of Player p in network. (Either the 18th or 19th digit in
   network.) */
int playerScore(long long network, int p) {
    // TO DO; add a return statement in order to compile
    
    //return player 1's score
    if (p == 1) {
        return (network % 100) / 10; //by returning the second digit of network
    }
    //return player 2's score
    if (p == 2) {
        return network % 10; //by returning the first digit of network
    }

}

/* Performs the task of Player p cutting a string in position pos of network.
   The reference parameter network should get updated, and if any coins are
   disconnected, the score of Player p shall be incremented, to reflect the new
   network configuration. */
void updateNetwork(long long& network, int pos, int p) {
    // TO DO
    int i;
    long long num = 1; //store the power calculation for further use.
    for (i = 1; i <= 19 - pos; i++)
    {
        num = num * 10;
    }
    network = network - num; //update the network by deducting the respected postion power

    static int coin1 = 1; //value for avoiding duplicated increment in score, 1 means connected and 0 means disconnected. 
    static int coin2 = 1;
    static int coin3 = 1;
    static int coin4 = 1;
    static int coin5 = 1;
    static int coin6 = 1;
    //first coin disconnected
    if (!stringState(network, 1) && !stringState(network, 4) && !stringState(network, 5) && !stringState(network, 8)) {
        if (coin1 == 1) {
            if (p == 1) {
                network = network + 10; //increase player 1's score by adding 10 to network 
                                        //as player 1's score is represented by the second digit.
                coin1 = 0;
            }
            if (p == 2) {
                network = network + 1; //increase player 2's score by adding 1 
                                       //as player 2's score is represented by the first digit.
                coin1 = 0;
            }
        }
        
    }
    //second coin disconnected
    if (!stringState(network, 2) && !stringState(network, 5) && !stringState(network, 6) && !stringState(network, 9)) {
        if (coin2 == 1) {
            if (p == 1) {
                network = network + 10; //increase player 1's score by adding 10 to network 
                                        //as player 1's score is represented by the second digit.
                coin2 = 0;
            }
            if (p == 2) {
                network = network + 1; //increase player 2's score by adding 1 
                                       //as player 2's score is represented by the first digit.
                coin2 = 0;
            }
        }
    }
    //third coin disconnected
    if (!stringState(network, 3) && !stringState(network, 6) && !stringState(network, 7) && !stringState(network, 10)) {
        if (coin3 == 1) {
            if (p == 1) {
                network = network + 10; //increase player 1's score by adding 10 to network 
                                        //as player 1's score is represented by the second digit.
                coin3 = 0;
            }
            if (p == 2) {
                network = network + 1; //increase player 2's score by adding 1 
                                       //as player 2's score is represented by the first digit.
                coin3 = 0;
            }
        }
    }
    //fourth coin disconnected
    if (!stringState(network, 8) && !stringState(network, 11) && !stringState(network, 12) && !stringState(network, 15)) {
        if (coin4 == 1) {
            if (p == 1) {
                network = network + 10; //increase player 1's score by adding 10 to network 
                                        //as player 1's score is represented by the second digit.
                coin4 = 0;
            }
            if (p == 2) {
                network = network + 1; //increase player 2's score by adding 1 
                                       //as player 2's score is represented by the first digit.
                coin4 = 0;
            }
        }
    }
    //fifth coin disconnected
    if (!stringState(network, 9) && !stringState(network, 12) && !stringState(network, 13) && !stringState(network, 16)) {
        if (coin5 == 1) {
            if (p == 1) {
                network = network + 10; //increase player 1's score by adding 10 to network 
                                        //as player 1's score is represented by the second digit.
                coin5 = 0;
            }
            if (p == 2) {
                network = network + 1; //increase player 2's score by adding 1 
                                       //as player 2's score is represented by the first digit.
                coin5 = 0;
            }
        }
    }
    //sixth coin disconnected
    if (!stringState(network, 10) && !stringState(network, 13) && !stringState(network, 14) && !stringState(network, 17)) {
        if (coin6 == 1) {
            if (p == 1) {
                network = network + 10; //increase player 1's score by adding 10 to network 
                                        //as player 1's score is represented by the second digit.
                coin6 = 0;
            }
            if (p == 2) {
                network = network + 1; //increase player 2's score by adding 1 
                                       //as player 2's score is represented by the first digit.
                coin6 = 0;
            }
        }
    }

    
}

/*
//first coin disconnected
if (!stringState(network, 1) && !stringState(network, 4) && !stringState(network, 5) && !stringState(network, 8)) {
    if (p == 1) {
        network = network + 10; //increase player 1's score by adding 10 to network 
                                //as player 1's score is represented by the second digit.
    }
    if (p == 2) {
        network = network + 1; //increase player 2's score by adding 1 
        //as player 2's score is represented by the first digit.
    }
}
//second coin disconnected
if (!stringState(network, 2) && !stringState(network, 5) && !stringState(network, 6) && !stringState(network, 9)) {
    if (p == 1) {
        network = network + 10; //increase player 1's score by adding 10 to network 
        //as player 1's score is represented by the second digit.
    }
    if (p == 2) {
        network = network + 1; //increase player 2's score by adding 1 
        //as player 2's score is represented by the first digit.
    }
}
//third coin disconnected
if (!stringState(network, 3) && !stringState(network, 6) && !stringState(network, 7) && !stringState(network, 10)) {
    if (p == 1) {
        network = network + 10; //increase player 1's score by adding 10 to network 
        //as player 1's score is represented by the second digit.
    }
    if (p == 2) {
        network = network + 1; //increase player 2's score by adding 1 
        //as player 2's score is represented by the first digit.
    }
}
//fourth coin disconnected
if (!stringState(network, 8) && !stringState(network, 11) && !stringState(network, 12) && !stringState(network, 15)) {
    if (p == 1) {
        network = network + 10; //increase player 1's score by adding 10 to network 
        //as player 1's score is represented by the second digit.
    }
    if (p == 2) {
        network = network + 1; //increase player 2's score by adding 1 
        //as player 2's score is represented by the first digit.
    }
}
//fifth coin disconnected
if (!stringState(network, 9) && !stringState(network, 12) && !stringState(network, 13) && !stringState(network, 16)) {
    if (p == 1) {
        network = network + 10; //increase player 1's score by adding 10 to network 
        //as player 1's score is represented by the second digit.
    }
    if (p == 2) {
        network = network + 1; //increase player 2's score by adding 1 
        //as player 2's score is represented by the first digit.
    }
}
//sixth coin disconnected
if (!stringState(network, 10) && !stringState(network, 13) && !stringState(network, 14) && !stringState(network, 17)) {
    if (p == 1) {
        network = network + 10; //increase player 1's score by adding 10 to network 
                                //as player 1's score is represented by the second digit.
    }
    if (p == 2) {
        network = network + 1; //increase player 2's score by adding 1 
                               //as player 2's score is represented by the first digit.
    }
}*/


/*
//player 1's turn
     if (p == 1) {
         //only the first coin disconnected
         if (!stringState(network, 1) && !stringState(network, 4) && !stringState(network, 5) && !stringState(network, 8)) {
             network = network + 10; //increase player 1's score by adding 10 to network
                                     //as player 1's score is represented by the second digit.
         }
         //only the second coin disconnected
         else if (!stringState(network, 2) && !stringState(network, 5) && !stringState(network, 6) && !stringState(network, 9)) {
             network = network + 10;
         }
         //only the third coin disconnected
         else if (!stringState(network, 3) && !stringState(network, 6) && !stringState(network, 7) && !stringState(network, 10)) {
             network = network + 10;
         }
         //only the fourth coin disconnected
         else if (!stringState(network, 8) && !stringState(network, 11) && !stringState(network, 12) && !stringState(network, 15)) {
             network = network + 10;
         }
         //only the fifth coin disconnected
         else if (!stringState(network, 9) && !stringState(network, 12) && !stringState(network, 13) && !stringState(network, 16)) {
             network = network + 10;
         }
         //only the sixth coin disconnected
         else if (!stringState(network, 10) && !stringState(network, 13) && !stringState(network, 14) && !stringState(network, 17)) {
             network = network + 10;
         }

         //first coin and second coin both disconnected at the same time
         else if ((!stringState(network, 1) && !stringState(network, 4) && !stringState(network, 5) && !stringState(network, 8))
                && (!stringState(network, 2) && !stringState(network, 5) && !stringState(network, 6) && !stringState(network, 9))) {
             network = network + 10;
         }
     }
*/