//---------------------------------------------------------------------------
// _PATRON_ACTION.H
// Class PatronAction is a support class of Patron.
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
//---------------------------------------------------------------------------
// PatronAction class: contains all the functions/actions a patron can do.
//               -- has the getters and setters for associated patron and
//                  item.
//
// Assumptions/implementation:
//      -- patron.h has been implemented
//      -- item.h has been implemented
//---------------------------------------------------------------------------
#ifndef _PATRON_ACTION_H
#define _PATRON_ACTION_H

#include <iostream>
#include <fstream>
#include "patron.h"
#include "item.h"

// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
// PatronAction class represents actions a patron can take.
class PatronAction {
// << operator - prints class data to output stream
friend ostream & operator<<(ostream &, const PatronAction &);

public:
  // Constructor - Creates the PatronAction
  PatronAction();

  // Destructor - Deallocates the PatronAction
  virtual ~PatronAction();

  // Getter - gets the associated Patron
  virtual Patron getAssociatedPatron() const;

  // Setter - sets the associated patron
  virtual bool setAssociatedPatron(Patron);

  // Getter - gets the associated item
  virtual Item& getAssociatedItem() const;

  // Setter - sets the associated item
  virtual bool setAssociatedItem(Item&);

  // Sets the data for the member variables
  virtual void setData(ifstream&);

  // operator<< helper
  virtual ostream displayHelper() const;
  
  // creates the patron action
  virtual PatronAction* create() const = 0;

  // Performs the patron action
  virtual void perform() const = 0;

protected:
  Patron* associatedPatron;  // the patron associated with the action
  Item* associatedItem;      // the item associated with the action
};

#endif