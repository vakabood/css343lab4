//---------------------------------------------------------------------------
// DISPLAY_HISTORY.H
// Class DisplayHistory 
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
//---------------------------------------------------------------------------
// DisplayHistory class: 
//      -- Displays history of patron's actions
//      -- Derived from PatronAction
//---------------------------------------------------------------------------

#ifndef _DISPLAY_HISTORY_H
#define _DISPLAY_HISTORY_H

#include <iostream>
#include <fstream>
#include "patronAction.h"

// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
// DisplayHistory class represents the history of actions a patron has taken
class DisplayHistory : public PatronAction {
// << operator - prints class data to output stream
friend ostream & operator<<(ostream &, const DisplayHistory &);

public:
  // Constructor - Creates a new DisplayHistory object
  DisplayHistory();

  // Destructor
  virtual ~DisplayHistory();

  // Returns a PatronAction (C for checkout, R for return, etc.)
  virtual PatronAction* create() const;

  // Sets the data of the member variables
  virtual bool setData(Library *, ifstream&);

  virtual void display() const;
  
  // Prints out the history of actions
  virtual bool perform();
};
#endif