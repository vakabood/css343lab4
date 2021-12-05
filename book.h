//---------------------------------------------------------------------------
// BOOK.H
// Class Book represents a book
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
//---------------------------------------------------------------------------
// Book class: 
//      -- Represents a book in the library
//      -- Derived from Item
//---------------------------------------------------------------------------
#ifndef _BOOK_H
#define _BOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include "author.h"
#include "date.h"
#include "item.h"


// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
//Book class represents a book object
class Book : public Item {
// << operator - prints out the book
friend ostream & operator<<(ostream &, const Book &);

public:
  // Constructor - creates a book
  Book();

  // Destructor - deallocates the book
  virtual ~Book() = 0;

  // returns the number of copies of the book the library owns
  int getTotalCopies() const;

  // returns the number of copies of the book that are currently 
  //    checked out
  int getNumCheckedOut() const; 

  // creates an Item that is a Book
  virtual Item* create() const = 0;

  // Sets the data for the member variables
  virtual bool setData(ifstream&) = 0;

  // operator<< helper
  virtual void displayHelper(ostream &) const = 0;

  // == operator - returns if two books are equal
  virtual bool operator==(const NodeData &) const = 0;

  // < operator - returns true if current book is less than given book
  virtual bool operator<(const NodeData &) const = 0;

protected:
  string author;  // the author of the book
  int year; // the year of publication of the book
  int month; // the month of publication of the book
  string bookTitle; // the title of the book
  char bookFormat; // the format --> 'H' = hardcover
};

#endif