#include <iostream>
#include "library.h"

using namespace std;

int main() {
  ifstream infile("data4books.txt");
  Library library;

  library.buildLibrary(infile);
  library.display();

  return 0;
} 