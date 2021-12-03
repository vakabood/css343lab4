//---------------------------------------------------------------------------
// PERSON.H
// Class Person stores the name of the Person.
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
//---------------------------------------------------------------------------
// Person class: represents a person with a name
//---------------------------------------------------------------------------
#ifndef _PERSON_H
#define _PERSON_H

#include <string>

// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
// Person class represents a generic person
class Person {
// << operator - prints class data to output stream
friend ostream & operator<<(ostream &, const Person &);

public:
  // Constructor
  Person(string);

  // Destructor
  virtual ~Person();

  // operator<< helper
  virtual ostream displayHelper() const;
  
  // Comparison operators
  virtual bool operator==(const Person &) const;
  virtual bool operator!=(const Person &) const;
  virtual bool operator<(const Person &) const;
  virtual bool operator>(const Person &) const;
  virtual bool operator<=(const Person &) const;
  virtual bool operator>=(const Person &) const;

protected:
  string name;  // the person's name
};
#endif