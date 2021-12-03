//---------------------------------------------------------------------------
// CHILDRENSBOOK.H
// Class ChildrensBook represents a book from the children's book genre
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
//---------------------------------------------------------------------------
// ChildrensBook class: 
//      -- stores information regarding a children's book
//      -- Derived from Book
//---------------------------------------------------------------------------
#ifndef _CHILDRENSBOOK_H
#define _CHILDRENSBOOK_H

#include <iostream>
#include <fstream>
#include "book.h"

// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
// ChildrensBook class represents a book from the children's book genre
class ChildrensBook : public Book {
// << operator - prints class data to output stream
friend ostream & operator<<(ostream &, const ChildrensBook &);

public:
  // Constructor - creates a children's book
  ChildrensBook();

  // Destructor - deallocates children's book
  virtual ~ChildrensBook();

  // Creates an Item that is a children's book
  virtual Item* create() const;

  // Sets the data for the member variables
  virtual void setData(ifstream&);

  // operator<< helper
  virtual ostream displayHelper() const;
  
  // == operator - returns if two  children's books are equal
  virtual bool operator==(const ChildrensBook &) const;

  // != operator - returns if two children's books are not equal
  virtual bool operator!=(const ChildrensBook &) const;

  // < operator - returns true if current children's book is less than 
  //    given children's book
  virtual bool operator<(const ChildrensBook &) const;

  // > operator - returns true if current children's book is greater than 
  //    given children's book
  virtual bool operator>(const ChildrensBook &) const;

  // <= operator - returns true if current children's book is less than or 
  //    equal to the given children's book
  virtual bool operator<=(const ChildrensBook &) const;

  // >= operator - returns true if current children's book is greater than or 
  //    equal to given children's book
  virtual bool operator>=(const ChildrensBook &) const;
};

#endif