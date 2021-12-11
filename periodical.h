//---------------------------------------------------------------------------
// _PERIODICAL_H
// Class Periodical is the subclass of Book.
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// Periodical class: contains operator functions for sorting purposes.
//          Derived from Book
// Assumptions:
//      -- The text is formatted correctly when reading
//      -- The genre is a periodical book
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

public:
  // Constructor
  Periodical();
  
  // Destructor
  virtual ~Periodical();

  // Returns month of publication
  int getMonth() const;

  // Creates an Item that is a periodical
  virtual Item* create() const;

  // Sets the data for the member variables
  virtual void setData(ifstream&);

  //sets the data of the periodical object
  virtual void setCommandData(ifstream&);

  //Displays the data of the periodical book object without the number of
  // copies
  virtual void display() const;

  //Displays the data of the periodical book object with the number of copies
  virtual void displayData() const;

  // Displays the headers
  virtual void displayHeader() const;
  
  // Comparison operators
  // Returns true if the two periodicals are equal
  virtual bool operator==(const NodeData &) const;

  // Returns true if the two periodicals are not equal
  virtual bool operator<(const NodeData &) const;

private:
  int month; // month of publication
};

#endif