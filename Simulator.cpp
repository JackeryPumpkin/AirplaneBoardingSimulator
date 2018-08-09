//
//  @file Simulator.cpp
//  Project 2
//
//  @author Zachary Duncan on 4/19/18.
//  Copyright © 2018 Zachary Duncan. All rights reserved.
//

#include "Simulator.hpp"
#include <fstream>
#include <iomanip>


void Simulator::addEngine(Engine *engine) {
    engines.push_back(engine);
}

void Simulator::addFile(const string &fileName) {
    fileNames.push_back(fileName);
    ofstream *resultFile = new ofstream(RESULT_PREFIX + fileName);
    
    resultFiles.push_back(resultFile);
}

void Simulator::run() {
    //Determines the number of PriorityQueues that will be needed as
    //there will always need to be a tree for each engine testing each file
    for (int i = 0; i < fileNames.size() * engines.size(); i++) {
        Heap_PriorityQueue<Passenger> *h = new Heap_PriorityQueue<Passenger>;
        queues.push_back(h);
    }
    
    int queueCount = 0;
    
    //Goes through each Engine
    for (int e = 0; e < engines.size() ; e++) {
        
        //Goes through each file
        for (int f = 0; f < fileNames.size(); f++) {
            
            string line;
            int field = 0;
            string fields[3];
            ifstream flightFile(fileNames[f]);
            
            //Checks if file is valid, then goes through each line
            if (flightFile.is_open()) {
                if (e == 0) {
                    *resultFiles[f] << "===========================================" << endl
                                    << "========= ORIGINAL PASSENGER ORDER ========" << endl
                                    << "===========================================" << endl;
                    
                    *resultFiles[f] << setw(11) << left << "NAME" << setw(4) << "ROW" << setw(5) << "TYPE" << setw(3) << "KEY" << endl;
                }
                
                while (getline(flightFile, line)) {
                    
                    for (int l = 0; l < line.length(); l++) {
                        if (line[l] == ' ') {
                            field++;
                        } else {
                            fields[field] += line[l];
                        }
                    }
                    
                    Passenger p(fields[0], fields[1][0], stoi(fields[2]));
                    if (e == 0) { //This if-check is here so that the original passenger list print only once
                        *resultFiles[f] << p << endl;
                    }
                    
                    engines[e]->prioritize(p);
                    queues[queueCount]->add(p);
                    
                    field = 0;
                    
                    for (int i = 0; i < 3; i++) {
                        fields[i] = "";
                    }
                }
            } else {
                cout << fileNames[f] << " file was not found." << endl;
            }
            
            flightFile.close();
            
            queueCount++;
        }
    }
    
    //For each priority queue display the top item, then remove it
    int prevRow = 99;
    queueCount = 0;
    for (int e = 0; e < engines.size(); e++) {
        
        for (int f = 0; f < fileNames.size(); f++) {
            double time = 0.0;
            
            *resultFiles[f] << endl << endl
            << "===========================================" << endl
            << "========= FILE: " << fileNames[f] << " ==========" << endl
            << "========= ENGINE: " << engines[e]->getName() << " ==============" << endl
            << "===========================================" << endl;
            
            *resultFiles[f] << setw(11) << left << "NAME" << setw(4) << "ROW" << setw(5) << "TYPE" << setw(4) << "KEY" << "TIME TO BOARD" << endl;
            
            while (!queues[queueCount]->isEmpty()) {
                time += prevRow <= queues[queueCount]->peek().getRowNumber() ? 25 : 1;
                prevRow = queues[queueCount]->peek().getRowNumber();
                
                *resultFiles[f] << queues[queueCount]->peek() << " " << time << endl;
                queues[queueCount]->remove();
            }
            
            *resultFiles[f] << endl << "MINUTES ELAPSED: " << setprecision(time >= 10 ? 4 : 3) << time/60 << endl;
            time = 0;
            
            delete queues[queueCount];
            queueCount++;
            
            if (e == engines.size() - 1) {
                resultFiles[f]->close();
            }
        }
    }
}
