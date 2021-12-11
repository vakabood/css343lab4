//---------------------------------------------------------------------------
// RETURN.H
// Class return checks out an item and is the subclass of patronAction.
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// Return class: contains a create and perform function which help with the
//               return action.
//        Derived from PatronAction
// Assumptions:
//      -- Patron and PatronAction have been implemented
//---------------------------------------------------------------------------
#ifndef _RETURN_H
#define _RETURN_H

#include <iostream>
#include <fstream>
#include "patronAction.h"

// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
// Return class represents the checkout action a patron can take.
class Return : public PatronAction {

public:
  // Constructor
  Return();

  // Destructor
  virtual ~Return();

  // Returns an instance of PatronAction that is a Return object
  virtual PatronAction* create() const;

  // Sets the data for the member variables
  virtual bool setData(Library*, ifstream&);

  //Displays the return
  virtual void display() const;
  
  // Performs the return action
  virtual bool perform();

private:
  char itemType; // type of item to be returned
  Item* tempItem; // temporary item pointer
};
#endif