//
//  CardDeck.h
//  War Program
//
//  Created by Chris on 1/23/14.
//  Copyright (c) 2014 The Casual Programmer. All rights reserved.
//

#ifndef __War_Program__CardDeck__
#define __War_Program__CardDeck__

#include <iostream>
#include "Card.h"
class CardDeck {
    
public:
    Card *newDeck[52];//member vars
    CardDeck();//constructs card deck
    void displayCardAt(int location);//IDK
    Card deal(int n);//deals a card and returns point value
    int cardsLeft();//output cards left
    void shuffle(int n);//shuffle cards
    int cardCount;
};
#endif /* defined(__War_Program__CardDeck__) */
