//---------------------------------------------------------------------------
// FICTION.H
// Class Fiction represents the fiction genre of a book
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
//---------------------------------------------------------------------------
// Fiction class: 
//      -- Represents the fiction genre of a book
//      -- Derived from book
//---------------------------------------------------------------------------
#ifndef _FICTION_H
#define _FICTION_H


#include <iostream>
#include <fstream>
#include "book.h"

// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
//Fiction class represents the fiction genre/subclass of the book object
class Fiction : public Book {
// << operator - prints class data to output stream
friend ostream & operator<<(ostream &, const Fiction &);

public:
  // Default constructor
  Fiction();

  // Destructor
  virtual ~Fiction();

  // Creates an Item that is a fiction book
  virtual Item* create() const;

  // Sets the data for the member variables
  virtual bool setData(ifstream&);
  
  // operator<< helper
  virtual void displayHelper(ostream &) const;
  
  // Comparison operators
  virtual bool operator==(const NodeData &) const;
  virtual bool operator<(const NodeData &) const;
};

#endif