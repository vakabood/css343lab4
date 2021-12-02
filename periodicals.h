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

  // Sets the data for the member variables
  virtual void setData(ifstream&) const;

  // Comparison operators
  virtual bool operator==(const Periodical &) const;
  virtual bool operator!=(const Periodical &) const;
  virtual bool operator<(const Periodical &) const;
  virtual bool operator>(const Periodical &) const;
  virtual bool operator<=(const Periodical &) const;
  virtual bool operator>=(const Periodical &) const;
};

#endif