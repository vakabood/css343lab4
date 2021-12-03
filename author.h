//---------------------------------------------------------------------------
// AUTHOR.H
// Class Author
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
//---------------------------------------------------------------------------
// Author class:
//      -- Represents the author of a item in the library 
//      -- Derived from Person
//---------------------------------------------------------------------------
#ifndef _AUTHOR_H
#define _AUTHOR_H

#include <string>
#include "person.h"

// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
// Author class represents the author of a item in the library
class Author : public Person {
// << operator - prints class data to output stream
friend ostream & operator<<(ostream &, const Author &);

public:
  // Constructor - creates author with the given name
  Author(string = "");

  // Destructor - deallocates author
  virtual ~Author();

  // operator<< helper
  virtual ostream displayHelper() const;

  // Comparison operators
  virtual bool operator==(const Author &) const;
  virtual bool operator!=(const Author &) const;
  virtual bool operator<(const Author &) const;
  virtual bool operator>(const Author &) const;
  virtual bool operator<=(const Author &) const;
  virtual bool operator>=(const Author &) const;

};

#endif