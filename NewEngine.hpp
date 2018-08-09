//
//  @file NewEngine.hpp
//  Project 2
//
//  @author Zachary Duncan on 4/28/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#ifndef NewEngine_hpp
#define NewEngine_hpp

#include <stdio.h>
#include "Passenger.hpp"
#include "Engine.hpp"

class NewEngine : public Engine {
    const string _NAME = "New Engine";
public:
    // This overrides Engine's method to take a reference to a Passenger and assigns to it a NewEngine priority value
    // @param a reference to a Passenger
    virtual void prioritize(Passenger &p) override;
    
    // This returns the name of the NewEngine
    // @return _NAME
    virtual string getName() override;
};

#endif /* NewEngine_hpp */
