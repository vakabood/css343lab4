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
public:
  // Constructor - Creates the Item object
  Item();

  // Destructor - Deallocates the Item object
  virtual ~Item();

  // Copy constructor
  Item(const Item&);

  // creates an item
  virtual Item* create() const = 0;

  // Sets the data for the member variables
  virtual void setData(ifstream&);

  // == operator - returns if two items are equal
  virtual bool operator==(const Item &) const = 0;

  // != operator - returns if two items are not equal
  virtual bool operator!=(const Item &) const = 0;

  // < operator - returns true if current item is less than given item
  virtual bool operator<(const Item &) const = 0;

  // > operator - returns true if current item is greater than given item
  virtual bool operator>(const Item &) const = 0;

  // <= operator - returns true if current item is less than or equal to the given item
  virtual bool operator<=(const Item &) const = 0;

  // >= operator - returns true if current item is greater than or equal to given item
  virtual bool operator>=(const Item &) const = 0;

};

#endif