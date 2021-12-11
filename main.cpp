#include <iostream>
#include "library.h"

using namespace std;

int main() {
  cout << "//-----------------------------------" <<
  "----------------------------------------" << endl;
  // initializes data for books
  ifstream infile("data4books.txt");
  Library library;

  // builds library from book file
  library.buildLibrary(infile);

  // build hash table from patron data
  ifstream infile2("data4patrons.txt");
  library.buildPatrons(infile2);

  // performs commands command data file
  ifstream infile3("data4commands.txt");
  library.performCommands(infile3);
  cout << "//-----------------------------------" <<
  "----------------------------------------" << endl;
  return 0;
} 