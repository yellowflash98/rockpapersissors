
#include <iostream>
#include <random>
#include <algorithm>
#include "RockPaperScissors.h"

#include<string>


 using namespace std;
 string removeWhiteSpaces(string str)
 {
     /*
      char whiteSpaceChars[] = " \f\n\r\t\v";

      for (unsigned int i = 0; i < strlen(whiteSpaceChars); i++) {
      str.erase (remove(str.begin(), str.end(), whiteSpaceChars[i]), str.end());
      }
      return str;
      */
     /*
      string trimmedSring;
      trimmedSring = str.substr(str.find_first_not_of(' '), (str.find_last_not_of(' ') - str.find_first_not_of(' ')) + 1);
      return trimmedSring;
      */
     int position;
     position = str.find_first_not_of(" \f\n\r\t\v");
     str.erase(0, position);

     position = str.find_last_not_of(" \f\n\r\t\v");
     if (string::npos != position)
         str.erase(position+1);
     return str;
 }


 string convertToLowerCase(string str)
 {

     transform(str.begin(), str.end(), str.begin(), ::tolower);
     return str;
 }

 int selectYourMove() {
     int playerSelection;

     do {
         std::cout << "Enter (R)ock, (P)aper, or (S)cissors for your move: ";
         //printf(ANSI_UNDERLINED_PRE);

         string playerChoice;
         getline(cin, playerChoice);

         //cout << "playerChoice = " << playerChoice << endl;

         //printf(ANSI_UNDERLINED_POST);

         playerChoice = removeWhiteSpaces(playerChoice) ;
         //cout << "playerChoice2 = " << playerChoice << endl;
         playerChoice = convertToLowerCase(playerChoice) ;
         //cout << "playerChoice3 = " << playerChoice << endl;

         if ( strcmp(playerChoice.c_str(), "r" ) == 0 or strcmp(playerChoice.c_str(), "(r)ock" ) == 0 or strcmp(playerChoice.c_str(), "rock" ) == 0 )
             playerSelection = 0;

         else if ( strcmp(playerChoice.c_str(), "p" ) == 0 or strcmp(playerChoice.c_str(), "(p)aper" ) == 0 or strcmp(playerChoice.c_str(), "paper" ) == 0 )
             playerSelection = 1;

         else if ( strcmp(playerChoice.c_str(), "s" ) == 0 or strcmp(playerChoice.c_str(), "(s)cissors" ) == 0 or strcmp(playerChoice.c_str(), "scissors" ) == 0 )
             playerSelection = 2;

         else {
             playerSelection = -1;
             //cout << "You Entered an invalid choice for your move :(" <<endl;
         }

     }
     while (playerSelection == -1) ;

     return playerSelection;
 }

 int selectAIMove ( int argc, int seed) {
     std::minstd_rand rng;

     if (argc >= 2)
         rng.seed(seed);
     else
         rng.seed( time(nullptr));


     std::uniform_int_distribution<> int_dis(0, 2);
     int computerSelection = int_dis(rng);
     return computerSelection;

 }


 int selectReplay() {
     int replaySelection;
     cout << "Would you like to replay the game?" << endl;
     do {
         std::cout << "Enter (Y)es or (N)o: ";
         //printf(ANSI_UNDERLINED_PRE);

         string replayChoice;
         getline(cin, replayChoice);

         //cout << "playerChoice = " << playerChoice << endl;

         //printf(ANSI_UNDERLINED_POST);

         replayChoice = removeWhiteSpaces(replayChoice) ;
         //cout << "playerChoice2 = " << playerChoice << endl;
         replayChoice = convertToLowerCase(replayChoice) ;
         //cout << "playerChoice3 = " << playerChoice << endl;

         if ( strcmp(replayChoice.c_str(), "y" ) == 0 or strcmp(replayChoice.c_str(), "(y)es" ) == 0 or strcmp(replayChoice.c_str(), "yes" ) == 0 )
             replaySelection = 0;

         else if ( strcmp(replayChoice.c_str(), "n" ) == 0 or strcmp(replayChoice.c_str(), "(n)o" ) == 0 or strcmp(replayChoice.c_str(), "no" ) == 0 )
             replaySelection = 1;

         else {
             replaySelection = -1;
             cout << "Would you like to replay the game?" << endl;
             //cout << "You Entered an invalid replay choice :(" <<endl;
         }

     }
     while (replaySelection == -1) ;

     return replaySelection;
 }

