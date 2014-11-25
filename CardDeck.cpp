//
//  CardDeck.cpp
//  War Program
//
//  Created by Chris on 1/23/14.
//  Copyright (c) 2014 The Casual Programmer. All rights reserved.
//

#include "CardDeck.h"
#include "Card.h"
#include <algorithm>    // std::random_shuffle
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

CardDeck::CardDeck() {
    //creates deck with 52 cards use CREATEDECK
    int count = 0;
    cardCount = 0;
    for (int i = 1; i <= 4; i++) {//Suit Value For Loop
        for (int j = 1; j <= 13; j++) {//Rank Value For Loop
                newDeck[count] = new Card(i, j);
                count++;
                cardCount++;
        }//endNestedFor
    }//endOuterFor
}//endConstructor

void CardDeck::displayCardAt(int location) {
    if (newDeck[location] != NULL) {
        Card display = *newDeck[location];
        display.displayCard();
    } else {
        //do nothing because its null
    }
}

Card CardDeck::deal(int n) {
    return *newDeck[n-1]; //draws the card from index 1 less than number of cards
    //in an array of 52 cards, 0-51 is range, so pulling top card(52nd) is index 51
}

int CardDeck::cardsLeft() {
    return cardCount; //cards left
}

void CardDeck::shuffle(int n) {
    std::cout << "\n... Shuffling ...\n";
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int r = i + (rand() % (n-i)); // Random remaining position.
        Card temp = *newDeck[i];
        *newDeck[i] = *newDeck[r];
        *newDeck[r] = temp;
    }
    std::cout << "Deck has been shuffled\n";
}



