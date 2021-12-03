#include "book.h"
using namespace std;

//----------------------------------------------------------------------------
// Default Constructor
Book::Book() {
    totalCopies = 0;
    numCheckedOut = 0;
}

//----------------------------------------------------------------------------
// Destructor
Book::~Book() {
    // nothing to do
}

//----------------------------------------------------------------------------
// getTotalCopies
// returns the total number of copies of the book
int Book::getTotalCopies() const{
    return totalCopies;
}

//----------------------------------------------------------------------------
// getNumCheckedOut
// returns the number of copies checked out
int Book::getNumCheckedOut() const{
    return numCheckedOut;
}

//------------------------------------------------------------------------------
// operator<<
// Displays book information
ostream& operator<<(ostream& os, const Book& item) {
    item.displayHelper(os);
}

