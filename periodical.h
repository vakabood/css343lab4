//---------------------------------------------------------------------------
// _PERIODICAL_H
// Class Periodical is the subclass of Book.
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
//---------------------------------------------------------------------------
// Periodical class: contains operator functions for sorting purposes.
//          Derived from Book
//---------------------------------------------------------------------------
#ifndef _PERIODICAL_H
#define _PERIODICAL_H

#include <list>
#include <iostream>
#include <fstream>
#include "book.h"

// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
//Periodicals class represents the periodicals genre/subclass of the book object
class Periodical : public Book {
// << operator - prints class data to output stream
friend ostream & operator<<(ostream &, const Periodical &);

public:
  // Constructor
  Periodical();
  
  // Destructor
  virtual ~Periodical();

  int getMonth() const;

  // Creates an Item that is a periodical
  virtual Item* create() const;

  // Sets the data for the member variables
  virtual void setData(ifstream&);

  virtual void setCommandData(ifstream&);

  virtual ostream & display(ostream &) const;

  // operator<< helper
  virtual void displayHelper(ostream &) const;
  
  // Comparison operators
  virtual bool operator==(const NodeData &) const;
  virtual bool operator<(const NodeData &) const;

private:
  int month;
};

#endif