#include "book.h"
using namespace std;

//----------------------------------------------------------------------------
// Default Constructor
Book::Book() {
    totalCopies = 0;
    numCheckedOut = 0;
}

//----------------------------------------------------------------------------
// Copy Constructor
Book::Book(const Book& book) {
    author = book.author;
    dateOfPublication = book.dateOfPublication;
    bookTitle = book.bookTitle;
    bookFormat = book.bookFormat;
    totalCopies = book.totalCopies;
    numCheckedOut = book.numCheckedOut;
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

//----------------------------------------------------------------------------


