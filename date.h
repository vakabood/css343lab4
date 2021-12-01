//---------------------------------------------------------------------------
// DATE.H
// Class Date represents a date object containing month and year
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
//---------------------------------------------------------------------------
#ifndef _DATE_H
#define _DATE_H

#include <iostream>

// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
// Date class represents the Dates containing Month and Year
class Date {
// << operator - prints class data to output stream
virtual friend ostream & operator<<(ostream &, const Date &);

public:
  // Constructor - creates a date with year
  Date(int year);

  // Constructor - creates a date with month and year
  Date(int month, int year);

  // Copy constructor
  Date(const Date&);

  // Comparison operators
  virtual bool operator==(const Date &) const;
  virtual bool operator!=(const Date &) const;
  virtual bool operator<(const Date &) const;
  virtual bool operator>(const Date &) const;
  virtual bool operator<=(const Date &) const;
  virtual bool operator>=(const Date &) const;

private:
  int month; // month in the date
  int year; // year in the date
};

#endif