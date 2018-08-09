//
//  @file Passenger.hpp
//  
//
//  @author Zachary Duncan on 4/13/18.
//

#ifndef Passenger_hpp
#define Passenger_hpp

#include <string>

using namespace std;

class Passenger {
private:
    int key = 0;
    string lastName;
    char type;
    int rowNumber;
    
public:
    // This initializes the Passenger object with default data member values
    Passenger();
    
    // This initializes the Passenger object with given data member values
    // @param Passenger name, type, row number
    Passenger(string, char, int);
    
    // This returns the priority key of the Passenger
    // @return the private key data member
    int getKey();
    
    // This returns the name of the Passenger
    // @return the private name data member
    string getName();
    
    // This returns the type of the Passenger
    // @return the private type data member
    char getType();
    
    // This returns the row number of the Passenger
    // @return the private rowNumber data member
    int getRowNumber();
    
    // This returns the priority key of the Passenger
    // @param an integer key to be added to key data member
    // @return the private key data member
    void addToKey(int);
    
    // This overloads the greater-than symbol for the Passenger
    // @param reference to a Passenger
    // @return the truth of whether the left Passenger is greater than the right
    bool operator>(Passenger &right);
    
    // This overloads the less-than symbol for the Passenger
    // @param reference to a Passenger
    // @return the truth of whether the left Passenger is lesser than the right
    bool operator<(Passenger &right);
    
    // This overloads the equal-to symbol for the Passenger
    // @param reference to a Passenger
    // @return the truth of whether the left Passenger is equal to than the right
    bool operator==(Passenger &right);
    
    // This overloads the double less-than symbol for the Passenger and an ostream&
    // @param reference to an ostream and a Passenger
    // @return the ostream containing the formatted information for the Passenger
    friend ostream& operator<<(ostream &out, Passenger p);
    
    // This overloads the double less-than symbol for the Passenger and an ofstream&
    // @param reference to an ofstream and a Passenger
    // @return the ofstream containing the formatted information for the Passenger
    friend ofstream& operator<<(ofstream &out, Passenger p);
};

#endif /* Passenger_hpp */
