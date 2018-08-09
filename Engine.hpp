//
//  @file Engine.hpp
//  Project 2
//
//  @author Zachary Duncan on 4/20/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#ifndef Engine_hpp
#define Engine_hpp

#include "Passenger.hpp"

class Engine {
public:
    // This takes a reference to a Passenger and assigns to it a priority value
    // @param a reference to a Passenger
    virtual void prioritize(Passenger &p) = 0;
    
    // This returns the name of the current engine being used
    // @return late-bound Engine* name
    virtual string getName() = 0;
};

#endif /* Engine_hpp */
