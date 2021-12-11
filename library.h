//---------------------------------------------------------------------------
// LIBRARY.H
// Class library reads off a file and builds a library and patrons in it.
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// Library class: contains all the books, items, and Patrons.
//               -- able to add and remove items/patrons from the library.
//               -- able to build the library and patrons while reading the
//                  file.
//
// Assumptions/implementation:
//      -- data files to read exist
//      -- data files are formatted correctly
//---------------------------------------------------------------------------
#ifndef _LIBRARY_H
#define _LIBRARY_H

#include <iostream>
#include <fstream>
#include "actionFactory.h"
#include "itemFactory.h"
#include "bintree.h"
#include "hashtable.h"
#include "consts.h"

// Only for class code, OK to use namespace
using namespace std;

//const int MAX_GENRES = 26;

//---------------------------------------------------------------------------
// Library class represents the collection of all the books, items, Patrons
class Library {
public:
  // Constructor - creates library
  Library();

  // Destructor - deallocates library
  virtual ~Library();

  // Removes item from library database
  bool removeItem(Item&);

  // Checks if the Item is in the library. Returns the item if found. 
  Item* inLibrary(char, Item*&) const;

  // Mass build of library items using datafile
  void buildLibrary(ifstream&);

  // Mass build library patrons using datafile
  void buildPatrons(ifstream&);

  // Performs patron actions
  void performCommands(ifstream&);

  // Display the inventory of the library
  void display() const;

  //getters
  // returns the Patron with the given id
  Patron* getPatron(int) const;


private:
  BinTree itemTypes[MAX_GENRES]; // array of trees for each itemType
  HashTable libraryPatrons; // stores all the library patrons
  ActionFactory patronActionFactory;  // factory to create patron actions
  ItemFactory libraryItemFactory;   // factory to create library items
  char itemType; // character representing itemType
  char actionType; // character representing actionType
};

#endif