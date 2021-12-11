//---------------------------------------------------------------------------
// PATRON.H
// Class patron is the subclass of Person and it focuses on the patrons of
// the library.
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// Patron class: can call the history of the patron using their patronId.
//        Derived from Person
//
// Assumptions/implementation:
//      -- Library exists
//      -- patronAction is implemented
//---------------------------------------------------------------------------
#ifndef _PATRON_H
#define _PATRON_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class PatronAction;

// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
// Patron class represents a patron of the library
class Patron {

public:
// Constructor
  Patron();

  // Destructor
  virtual ~Patron();

  // Sets the data for the patron
  virtual void setData(ifstream&);

  // Adds a command to the patron's history
  virtual void addCommandToHistory(PatronAction*);

  // Displays the patron's history
  virtual void displayHistory() const;
  
  // patron equality operator
  virtual bool operator==(const Patron &) const;

  // patron inequality operator
  virtual bool operator!=(const Patron &) const;
  
  // getters for class data
  // returns the patronId
  int getPatronId() const;

  // returns the name of the patron
  string getName() const;

  // returns the action history of the patron
  vector<PatronAction*> getHistory() const;
protected:
  vector<PatronAction*> history;   // the patron's past actions
  int patronId;    // unique 4 digit id number
  string patronName; // name of the patron
};

#endif