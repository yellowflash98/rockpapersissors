//
// Created by Tobin Joseph on 2019-04-14.
//

#include <iostream>
#include <string.h>
#include <random>
#include <algorithm>
//#include "rockpaperscissors.h"

using namespace std;


string removeWhiteSpaces(string str) {
    int position;
    position = str.find_first_not_of(" \f\n\r\t\v");
    str.erase(0, position);

    position = str.find_last_not_of(" \f\n\r\t\v");
    if (string::npos != position)
        str.erase(position+1);
    return str;
}


string convertToLowerCase(string str) {

    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int selectYourMove() {
    int playerSelection;

    do {
        std::cout << "Enter (R)ock, (P)aper, or (S)cissors for your move: ";

        string playerChoice;
        getline(cin, playerChoice);

        playerChoice = removeWhiteSpaces(playerChoice) ;
        playerChoice = convertToLowerCase(playerChoice) ;

        if ( strcmp(playerChoice.c_str(), "r" ) == 0 or strcmp(playerChoice.c_str(), "(r)ock" ) == 0 or strcmp(playerChoice.c_str(), "rock" ) == 0 )
            playerSelection = 0;

        else if ( strcmp(playerChoice.c_str(), "p" ) == 0 or strcmp(playerChoice.c_str(), "(p)aper" ) == 0 or strcmp(playerChoice.c_str(), "paper" ) == 0 )
            playerSelection = 1;

        else if ( strcmp(playerChoice.c_str(), "s" ) == 0 or strcmp(playerChoice.c_str(), "(s)cissors" ) == 0 or strcmp(playerChoice.c_str(), "scissors" ) == 0 )
            playerSelection = 2;

        else {
            playerSelection = -1;
            
        }

    }
    while (playerSelection == -1) ;

    return playerSelection;
}

int selectReplay() {
    int replaySelection;
    cout << "Would you like to replay the game?" << endl;
    do {
        std::cout << "Enter (Y)es or (N)o: ";

        string replayChoice;
        getline(cin, replayChoice);

        replayChoice = removeWhiteSpaces(replayChoice) ;
        replayChoice = convertToLowerCase(replayChoice) ;

        if ( strcmp(replayChoice.c_str(), "y" ) == 0 or strcmp(replayChoice.c_str(), "(y)es" ) == 0 or strcmp(replayChoice.c_str(), "yes" ) == 0 )
            replaySelection = 0;

        else if ( strcmp(replayChoice.c_str(), "n" ) == 0 or strcmp(replayChoice.c_str(), "(n)o" ) == 0 or strcmp(replayChoice.c_str(), "no" ) == 0 )
            replaySelection = 1;

        else {
            replaySelection = -1;
            cout << "Would you like to replay the game?" << endl;
        }

    }
    while (replaySelection == -1) ;

    return replaySelection;
}


int main(int argc, char** argv)
{

    
    minstd_rand rng;
    int seedToRandom;
    
    if (argc >= 2) {
        seedToRandom = stoi(argv[1]);
        rng.seed(seedToRandom);
    }
    else 
        rng.seed( time(nullptr));
        
    uniform_int_distribution<> int_dis(0, 2);
    int playerSelection = -1;
    int computerSelection = -1;
    int replaySelection = -1;

    do {

        do {
            playerSelection = selectYourMove();
            
            computerSelection = int_dis(rng);
            
            if (computerSelection == playerSelection) {

                if (playerSelection == 0 ) {
                    cout << "The ai played rock." << endl;
                    cout << "You and the AI both played rock."  << endl;
                }
                else if (playerSelection == 1 ) {
                    cout << "The ai played paper." << endl;
                    cout << "You and the AI both played paper." << endl;

                }
                else if (playerSelection == 2 ) {
                    cout << "The ai played scissors." << endl;
                    cout << "You and the AI both played scissors." << endl;

                }
                else cout << "You and the AI both played same selection" << endl;

                cout << "Keep playing until someone wins." << endl;

            }


        } while( playerSelection == computerSelection );


        if (playerSelection != computerSelection ) {

            if (playerSelection == 0 && computerSelection == 1 ) {
                cout << "The ai played paper." << endl;
                cout << "The AI wins :(" << endl;
            }

            else if (playerSelection == 0 && computerSelection == 2 ) {
                cout << "The ai played scissors." << endl;
                cout << "You win!" << endl;
            }

            else if (playerSelection == 1 && computerSelection == 0 ) {
                cout << "The ai played rock." << endl;
                cout << "You win!" << endl;
            }

            else  if (playerSelection == 1 && computerSelection == 2 ) {
                cout << "The ai played scissors." << endl;
                cout << "The AI wins :(" << endl;
            }


            else  if (playerSelection == 2 && computerSelection == 0 ) {
                cout << "The ai played rock." << endl;
                cout << "The AI wins :(" << endl;
            }

            else if (playerSelection == 2 && computerSelection == 1 ) {
                cout << "The ai played paper." << endl;
                cout << "You win!" << endl;
            }

            else cout << "You or the AI both played invalid selection" << playerSelection << endl;
        }

        replaySelection = selectReplay();
    }

    while (replaySelection != 1) ;

    return 0;
}