#include "book.h"
using namespace std;

//----------------------------------------------------------------------------
// Default Constructor
Book::Book() {
    author = "";
    year = 0;
    bookTitle = "";
    bookFormat = 'H';
}

//----------------------------------------------------------------------------
// Destructor
Book::~Book() {
    // nothing to do
}

//----------------------------------------------------------------------------
// getAuthor
// returns the author of the book
string Book::getAuthor() const{
    return author;
}

//----------------------------------------------------------------------------
// getYear
// returns the year of the book
int Book::getYear() const{
    return year;
}

//----------------------------------------------------------------------------
// getTitle
// returns the title of the book
string Book::getBookTitle() const{
    return bookTitle;
}

//----------------------------------------------------------------------------
// setData
// sets the data of the book
void Book::setData(ifstream& inFile) {
    inFile.get();
    getline(inFile, author, ',');

    inFile.get();
    getline(inFile, bookTitle, ',');

    inFile.get();
    inFile >> year;
}

void Book::display() const {
    cout << left << setw(20) << bookTitle << setw(16) << author << setw(4) << 
        year << endl;
}

//------------------------------------------------------------------------------
// operator<<
// Displays book information
ostream& operator<<(ostream& os, const Book& item) {
    item.displayHelper(os);
}

