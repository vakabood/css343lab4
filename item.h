//---------------------------------------------------------------------------
// ITEM.H
// Class Item represents an item from the library
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
//---------------------------------------------------------------------------
// Fiction class: 
//      -- Represents an item from the library
//      -- Derived from nodedata
//---------------------------------------------------------------------------
#ifndef _ITEM_H
#define _ITEM_H

#include <iostream>
#include <fstream>
#include "nodedata.h"

// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
// Item class represents the items in a library.
class Item : public NodeData {

friend ostream & operator<<(ostream &, const Item &);

public:
  // Constructor - Creates the Item object
  Item();

  // Destructor - Deallocates the Item object
  virtual ~Item();

  // creates an item
  virtual Item* create() const = 0;

  // Sets the data for the member variables
  virtual bool setData(ifstream&) = 0;

private:
  // operator<< helper
  virtual void displayHelper(ostream &) const = 0;
};
#endif