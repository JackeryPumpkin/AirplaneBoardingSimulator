//
//  @file OldEngine.cpp
//  Project 2
//
//  @author Zachary Duncan on 4/20/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#include "OldEngine.hpp"
#include "Passenger.hpp"
#include <iostream>

using namespace std;

void OldEngine::prioritize(Passenger &p) {
    switch (p.getType()) {
        case 'H':
            p.addToKey(500);
            break;
            
        case 'E':
            p.addToKey(100);
            break;
            
        case 'G':
            p.addToKey(0);
            break;
            
        default:
            cout << "This passenger was not valid" << endl;
            break;
    }
    
    if (p.getRowNumber() <= 4) {
        p.addToKey(200);
    } else if (p.getRowNumber() >= 5 && p.getRowNumber() <= 9) {
        p.addToKey(20);
    } else if (p.getRowNumber() >= 10 && p.getRowNumber() <= 11) {
        p.addToKey(80);
    } else if (p.getRowNumber() >= 12 && p.getRowNumber() <= 16) {
        p.addToKey(40);
    } else if (p.getRowNumber() >= 17 && p.getRowNumber() <= 22) {
        p.addToKey(50);
    } else if (p.getRowNumber() >= 23 && p.getRowNumber() <= 26) {
        p.addToKey(60);
    } else {
        cout << "This passenger was given an invalid row number" << endl;
    }
}

string OldEngine::getName() {
    return _NAME;
}

