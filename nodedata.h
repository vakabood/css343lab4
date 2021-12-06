#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// simple class containing one string to use for testing
// not necessary to comment further

class NodeData {
   friend ostream & operator<<(ostream &, const NodeData &);

public:
   NodeData();          // default constructor, data is set to an empty string
   ~NodeData();          

   // set class data from data file
   // returns true if the data is set, false when bad data, i.e., is eof
   virtual void setData(ifstream&) = 0;                

   virtual bool operator==(const NodeData &) const = 0;
   virtual bool operator<(const NodeData &) const = 0;

private:
  // operator<< helper
  virtual void displayHelper(ostream &) const = 0;    
};

#endif
