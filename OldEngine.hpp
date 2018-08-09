//
//  @file OldEngine.hpp
//  Project 2
//
//  @author Zachary Duncan on 4/20/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#ifndef OldEngine_hpp
#define OldEngine_hpp

#include <stdio.h>
#include "Passenger.hpp"
#include "Engine.hpp"

class OldEngine : public Engine {
    const string _NAME = "Old Engine";
public:
    // This overrides Engine's method to take a reference to a Passenger and assigns to it a OldEngine priority value
    // @param a reference to a Passenger
    virtual void prioritize(Passenger &p) override;
    
    // This returns the name of the OldEngine
    // @return _NAME
    virtual string getName() override;
};

#endif /* OldEngine_hpp */
