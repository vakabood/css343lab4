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
#include "person.h"
#include "patronAction.h"


// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
// Patron class represents a patron of the library
class Patron : public Person {
// << operator - prints class data to output stream
friend ostream & operator<<(ostream &, const Patron &);

private:
  // Constructor
  Patron();

  // Destructor
  ~Patron();

  // Copy Constructor
  Patron(Patron&);
  
  // Defines this to Patron
  virtual Patron operator=(const Patron&);
  
  list<PatronAction*> history;   // the patron's past actions
  int patronId;    // unique 4 digit id number
};

#endif