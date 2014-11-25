//
//  Card.h
//  War Program
//
//  Created by Chris on 1/23/14.
//  Copyright (c) 2014 The Casual Programmer. All rights reserved.
//

#ifndef __War_Program__Card__
#define __War_Program__Card__

#include <iostream>

class Card {
    
public:
    int suitValue;//1 spade , 2 heart, 3 diamond, 4 club
    int rankValue;
    Card(int suitChar, int rankInt);
    int getValue();
    void displayCard();
    std::string valueToString(int rankInt);
    std::string suitToString(int suitChar);
    
};
#endif /* defined(__War_Program__Card__) */

