//
//  Main Game Class.cpp
//  War Program
//
//  Created by Chris on 1/23/14.
//  Copyright (c) 2014 The Casual Programmer. All rights reserved.
//
#include <iostream>
#include "Main Game Class.h"
#include "CardDeck.h"
#include "Card.h"
using namespace std;
int main(int argc, char*argv[]) {
    
    //populate deck
    CardDeck playingDeck = CardDeck();
    int count = 51;
    
    //MAIN MENU
    int userChoice;//scans user menu selection
    bool exitCondition = false;
    
    while (exitCondition != true) {
        //scan for user choice
        std::cout<<"\nPlease enter the integer corresponding to your choice: \n1. Create a new deck\n2. Show all cards in deck\n3. Shuffle the deck\n4. Play a game of war!\n5.Exit!\n";
        cin>>userChoice;
        switch (userChoice) {
            case 1: {//create new card deck
                std::cout << "\n" << "A new deck has been made..." << "\n";
                CardDeck playingDeck = CardDeck();
                count = 51;
                break;
            }
            case 2: {// show all cards in deck
                //show cards
                std::cout <<"\n";
                for (int i = 0; i < playingDeck.cardsLeft(); i++) {
                    playingDeck.displayCardAt(i);
                }
                std::cout << "There are " << playingDeck.cardsLeft() <<" cards in the deck\n";
                break;
            }
            case 3: {//shuffle
                playingDeck.shuffle(playingDeck.cardsLeft());
                break;
            }
            case 4: {//Play War!
                if (playingDeck.cardCount == 0) {
                    std::cout<< "There are no cards left in the deck!!\n Create a new deck at the main menu to play again!";
                    break;
                }
                std::cout<<"\n...dealing...\n";
                
                std::cout<<"One for you...\n";
                Card playerOne1 = playingDeck.deal(playingDeck.cardCount);
                playerOne1.displayCard();
                playingDeck.cardCount--;//lowers the count of the array to one less (so same card cannot be referenced again)
                
                std::cout<<"One for me...\n";
                Card playerTwo1 = playingDeck.deal(playingDeck.cardCount);
                playerTwo1.displayCard();
                playingDeck.cardCount--;//lower count again
                
                std::cout<<"Two for you...\n";
                Card playerOne2 = playingDeck.deal(playingDeck.cardCount);//sends the card count of the deck, draws top card
                playerOne2.displayCard();
                playingDeck.cardCount--;//lowers the count of the array to one less (so same card cannot be referenced again)
                
                std::cout<<"Two for me...\n";
                Card playerTwo2 = playingDeck.deal(playingDeck.cardCount);
                playerTwo2.displayCard();
                playingDeck.cardCount--;//lower count again
                
                int playerOnePoints = playerOne1.getValue() + playerOne2.getValue();
                int playerTwoPoints = playerTwo1.getValue() + playerTwo2.getValue();
                
                std::cout << "You have " << playerOnePoints << " points\n";
                std::cout << "I have " <<playerTwoPoints << " points\n";
                
                if (playerOnePoints > playerTwoPoints) {
                    std::cout << "You win, well played my friend\n";
                } else if (playerOnePoints < playerTwoPoints) {
                    std::cout << "I win! In your face!\n";
                } else {
                    std::cout << "It's a tie!\n";
                }
                
                std::cout << "There are " << playingDeck.cardsLeft() << " cards in the deck.\n";
                
                string choice;
                
                while (choice != "Y" || choice != "N") {
                    std::cout << "Want to play again ?? (Y/N)\n";
                    cin>>choice;
                    if (choice == "Y") {
                        break;
                    } else if (choice == "N") {
                        std::cout <<"Thanks for playing!\n";
                        exitCondition = true;
                        break;
                    } else {
                        std::cout << "Enter either Y for yes or N for no\n";
                    }
                }
                
                break;
            }
            case 5: {//Exit
                std::cout<<"\nThanks for playing! Goodbye\n";
                exitCondition = true;
                break;
            }
        }

    }
    
    return 0;//end prog
}