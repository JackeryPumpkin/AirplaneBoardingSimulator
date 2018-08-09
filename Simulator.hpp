//
//  @file Simulator.hpp
//  Project 2
//
//  @author Zachary Duncan on 4/19/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#ifndef Simulator_hpp
#define Simulator_hpp

#include <iostream>
#include <fstream>
#include <vector>
#include "Heap_PriorityQueue.h"
#include "Passenger.hpp"
#include "OldEngine.hpp"
#include "Engine.hpp"


using namespace std;

class Simulator {
private:
    vector<Engine*> engines;
    vector<Heap_PriorityQueue<Passenger>*> queues;
    vector<string> fileNames;
    vector<ofstream*> resultFiles;
    const string RESULT_PREFIX = "RESULT";
    
public:
    // This adds an engine to the list of engines to be simulated
    // @param reference to an engine
    void addEngine(Engine *engine);
    
    // This adds a file name to the list of files to be read from
    // @param reference to a file name
    void addFile(const string &fileName);
    
    // This loops through each engine, file, file line to create, prioritize and output Passengers based on engine simulations
    void run();
};

#endif /* Simulator_hpp */
