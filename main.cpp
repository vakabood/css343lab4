#include <iostream>
#include "library.h"

using namespace std;

int main() {
  Library library;
  library.buildLibrary("books.txt");
  library.buildPatrons("patrons.txt");
  library.performCommands("commands.txt");

  return 0;
} 