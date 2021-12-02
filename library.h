//---------------------------------------------------------------------------
// LIBRARY.H
// Class library reads off a file and builds a library and patrons in it.
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
//---------------------------------------------------------------------------
// Library class: contains all the books, items, and Patrons.
//               -- able to add and remove items/patrons from the library.
//               -- able to build the library and patrons while reading the
//                  file.
//
// Assumptions/implementation:
//      -- data files to read exist
//---------------------------------------------------------------------------
#ifndef _LIBRARY_H
#define _LIBRARY_H

#include <list>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "patron.h"
#include "item.h"
#include "actionFactory.h"
#include "itemFactory.h"
#include "bintree.h"
#include "nodedata.h"

// Only for class code, OK to use namespace
using namespace std;


//---------------------------------------------------------------------------
// Library class represents the collection of all the books, items, Patrons
class Library {
public:
  // Constructor - creates library
  Library();

  // Destructor - deallocates library
  virtual ~Library();

  // Adds item to the library database
  bool addItem(Item);

  // Removes item from library database
  bool removeItem(Item);

  // Finds the item in library database
  NodeData* findItem(NodeData) const;

  // Adds a patron to library
  bool addPatron(Patron);

  // Removes a patron from library
  bool removePatron(Patron);

  // Mass build of library items using datafile
  void buildLibrary(ifstream&);

  // Mass build library patrons using datafile
  void buildPatrons(ifstream&);

  // Performs patron actions
  void performCommands(ifstream&);

private:
  BinTree itemTypes[10];
  unordered_map<int, Patron*> libraryPatrons; // stores all the library patrons
  ActionFactory patronActionFactory;  // factory to create patron actions
  ItemFactory libraryItemFactory;   // factory to create library items
};

#endif