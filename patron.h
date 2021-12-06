//---------------------------------------------------------------------------
// PATRON.H
// Class patron is the subclass of Person and it focuses on the patrons of
// the library.
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
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
#include <vector>
#include <string>

class PatronAction;


// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
// Patron class represents a patron of the library
class Patron {
// << operator - prints class data to output stream
friend ostream & operator<<(ostream &, const Patron &);

public:
// Constructor
  Patron();

  // Destructor
  virtual ~Patron();

  virtual bool setData(ifstream&);

  virtual void addCommandToHistory(PatronAction);

  virtual void displayHistory() const;

  // operator<< helper
  virtual ostream displayHelper() const;
  
  virtual bool operator==(const Patron &) const;
  virtual bool operator!=(const Patron &) const;
  
  // getters for class data
  int getPatronId() const;
  string getLastName() const;
  string getFirstName() const;  
private:
  vector<PatronAction> history;   // the patron's past actions
  int patronId;    // unique 4 digit id number
  string lastName, firstName;
};

#endif