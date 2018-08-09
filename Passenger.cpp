//
//  @file Passenger.cpp
//  
//
//  @author Zachary Duncan on 4/13/18.
//

#include "Passenger.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

Passenger::Passenger() {
    lastName = "";
    type = 'G';
    rowNumber = NULL;
}

Passenger::Passenger(string name, char type, int row): lastName(name), type(type), rowNumber(row) {
}

int Passenger::getKey() {
    return key;
}

void Passenger::addToKey(int n) {
    key += n;
}

string Passenger::getName() {
    return lastName;
}

char Passenger::getType() {
    return type;
}

int Passenger::getRowNumber() {
    return rowNumber;
}

bool Passenger::operator>(Passenger &right) {
    return this->getKey() > right.getKey();
}

bool Passenger::operator<(Passenger &right) {
    return this->getKey() < right.getKey();
}

bool Passenger::operator==(Passenger &right) {
    return this->getKey() == right.getKey();
}

ostream& operator<<(ostream &out, Passenger p) {
    out << setw(11) << left << p.getName() << setw(4) << p.getRowNumber() << setw(5) << p.getType() << setw(3) << p.getKey();
    
    return out;
}

ofstream& operator<<(ofstream &out, Passenger p) {
    out << setw(11) << left << p.getName() << setw(4) << p.getRowNumber() << setw(5) << p.getType() << setw(3) << p.getKey();
    
    return out;
}







