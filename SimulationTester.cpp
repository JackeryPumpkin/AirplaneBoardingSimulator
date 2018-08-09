//
//  @file SimulationTester.cpp
//
//
//  @author Zachary Duncan on 4/13/18.
//


#include "Passenger.hpp"
#include "OldEngine.hpp"
#include "NewEngine.hpp"
#include "Simulator.hpp"
#include <iostream>

using namespace std;

void description();

int main() {
    description();
    
    Engine *oldEngine = new OldEngine;
    Engine *newEngine = new NewEngine;
    const string AIR70 = "airworthy70.txt";
    const string AIR85 = "airworthy85.txt";
    const string AIR100 = "airworthy100.txt";
    
    Simulator sim;
    
    sim.addEngine(oldEngine);
    sim.addEngine(newEngine);
    sim.addFile(AIR70);
    sim.addFile(AIR85);
    sim.addFile(AIR100);
    
    sim.run();
    
    return EXIT_SUCCESS;
}

void description() {
    cout
    << "Overview:" << endl
    << "This program reads in data from multiple text files and" << endl
    << "creates Passenger objects from each datum. It then assigns" << endl
    << "them a priority value from as many different priority-calulating" << endl
    << "engines as are given to the simulation. Finally, it outputs to" << endl
    << "new RESULTS files all of the Passengers in their prioritized" << endl
    << "orders for each airplane configuration and engine." << endl;
}
