#include <iostream>
#include "library.h"

using namespace std;

int main() {
  ifstream infile("data4books.txt");
  Library library;

  library.buildLibrary(infile);

  ifstream infile2("data4patrons.txt");
  library.buildPatrons(infile2);

  ifstream infile3("data4commands.txt");
  library.performCommands(infile3);
  
  return 0;
} 