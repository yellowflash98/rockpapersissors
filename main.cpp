#include <iostream>
#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include"RockPaperScissors.h"
#include"RockPaperScissors.function.cpp"





    int main(int argc, char** argv)

    {
        //cout << "You have entered " << argc  << " arguments:" << endl;
        //cout << "You entered following arguments:" << endl;
        //for (int i = 0; i < argc; ++i)
        //    cout << "argv[" << i << "]  = "  << argv[i] << endl;

        int seedToRandom = -1;
        if (argc >= 2) {
            seedToRandom = std::stoi(argv[1]);
        }



        //if (argc >= 2) {
        //try {
        //seedToRandom = std::stoi(argv[1]);
        //}

        //catch ( const std::exception& excep){
        //cout << "An exception occurred while converting argv[1] to seedToRandom. Exception  = " << excep.what() << endl;
        //cout << "Please Enter a valid integer as seed to the random number generator"  <<  endl;
        //}

        //std::cout << "argv[1] = " << argv[1] << " --> " << "seedToRandom = " << seedToRandom << std::endl;

        //} */

        int playerSelection = -1;
        int computerSelection = -1;
        int replaySelection = -1;

        do {

            do {
                playerSelection = selectYourMove();
                //cout << "playerSelection1 = " << playerSelection << endl;
                computerSelection = selectAIMove(argc, seedToRandom);
                //cout << "computerSelection1 = " << computerSelection << endl;

                if (computerSelection == playerSelection) {

                    if (playerSelection == 0 ) {
                       std::cout << "The ai played rock." << std::endl;
                        std::cout << "You and the AI both played rock."  << std::endl;
                    }
                    else if (playerSelection == 1 ) {
                        std::cout << "The ai played paper." << std::endl;
                        std::cout << "You and the AI both played paper." << std::endl;

                    }
                    else if (playerSelection == 2 ) {
                        std::cout << "The ai played scissors." << std::endl;
                        std::cout << "You and the AI both played scissors." << std::endl;

                    }
                    else std ::cout << "You and the AI both played same selection" << std ::endl;

                    std ::cout << "Keep playing until someone wins." << std::endl;

                }


            } while( playerSelection == computerSelection );

            //cout << "playerSelection = " << playerSelection << endl;
            //cout << "computerSelection = " << computerSelection << endl;


            if (playerSelection != computerSelection ) {

                if (playerSelection == 0 && computerSelection == 1 ) {
                    std::cout << "The ai played paper." << std::endl;
                    std::cout << "The AI wins :(" << std::endl;
                }

                else if (playerSelection == 0 && computerSelection == 2 ) {
                    std::cout << "The ai played scissors." << std::endl;
                    std::cout << "You win!" << std::endl;
                }

                else if (playerSelection == 1 && computerSelection == 0 ) {
                    std::cout << "The ai played rock." << std::endl;
                    std::cout << "You win!" << std::endl;
                }

                else  if (playerSelection == 1 && computerSelection == 2 ) {
                    std::cout << "The ai played scissors." << std::endl;
                    std::cout << "The AI wins :(" << std::endl;
                }


                else  if (playerSelection == 2 && computerSelection == 0 ) {
                    std::cout << "The ai played rock." << std::endl;
                    std:: cout << "The AI wins :(" << std::endl;
                }

                else if (playerSelection == 2 && computerSelection == 1 ) {
                    std:: cout << "The ai played paper." << std::endl;
                    std::cout << "You win!" << std::endl;
                }

                else std::cout << "You or the AI both played invalid selection" << playerSelection << std::endl;
            }



            replaySelection = selectReplay();
        }

        while (replaySelection != 1) ;




        return 0;
    }
