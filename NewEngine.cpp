//
//  @file NewEngine.cpp
//  Project 2
//
//  @author Zachary Duncan on 4/28/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#include "NewEngine.hpp"
#include "Passenger.hpp"
#include <iostream>

using namespace std;

void NewEngine::prioritize(Passenger &p) {
    if (p.getType() == 'H') {
        p.addToKey(3);
    } else if (p.getRowNumber() < 5) {
        p.addToKey(2);
    } else if (p.getType() == 'E' || p.getRowNumber() == 10 || p.getRowNumber() == 11) {
        p.addToKey(1);
    }
}

string NewEngine::getName() {
    return _NAME;
}
