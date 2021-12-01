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
virtual friend ostream & operator<<(ostream &, const Fiction &);

public:
  // Sets the data for the member variables
  virtual void setData(ifstream&);
  
  // Comparison operators
  virtual bool operator==(const Fiction &) const;
  virtual bool operator!=(const Fiction &) const;
  virtual bool operator<(const Fiction &) const;
  virtual bool operator>(const Fiction &) const;
  virtual bool operator<=(const Fiction &) const;
  virtual bool operator>=(const Fiction &) const;
};

#endif