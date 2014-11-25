//
//  Card.cpp
//  War Program
//
//  Created by Chris on 1/23/14.
//  Copyright (c) 2014 The Casual Programmer. All rights reserved.
//

#include "Card.h"
using namespace std;
//construct card and assign member variables
Card::Card (int suitChar, int rankInt) {
    rankValue = rankInt;//ten-K = 10 // only number value
    suitValue = suitChar;//D for diamond, C for club, H for heard, S for spade
}

//returns integer value of card
int Card::getValue() {
    if (rankValue >= 10) {
        return 10;
    }
    else {
        return rankValue;
    }
}

void Card::displayCard() {
    std::cout << valueToString(rankValue) << " of " << suitToString(suitValue) << "\n";
    //output the string value of rank and the suit
}

std::string Card::valueToString(int rankInt) {
    switch (rankInt) {
        case 1:
            return "Ace";
            break;
        case 2:
            return "Two";
            break;
        case 3:
            return "Three";
            break;
        case 4:
            return "Four";
            break;
        case 5:
            return "Five";
            break;
        case 6:
            return "Six";
            break;
        case 7:
            return "Seven";
            break;
        case 8:
            return "Eight";
            break;
        case 9:
            return "Nine";
            break;
        case 10:
            return "Ten";
            break;
        case 11:
            return "Jack";
            break;
        case 12:
            return "Queen";
            break;
        case 13:
            return "King";
            break;
    }
    return "null";
}

std::string Card::suitToString(int suitChar) {
    switch (suitChar) {
        case 1://diamond
            return "Spades";
            break;
        case 2://heart
            return "Hearts";
            break;
        case 3://spade
            return "Diamonds";
            break;
        case 4://club
            return "Clubs";
            break;
    }
    return "null";
}
























//