#include "childrensBook.h"

//------------------------------------------------------------------------------
// Constructor
ChildrensBook::ChildrensBook() : Book(){
    author = "";
    bookTitle = "";
    year = 0;
    bookFormat = 'H';
}

//------------------------------------------------------------------------------
// Destructor
ChildrensBook::~ChildrensBook() {

}

//------------------------------------------------------------------------------
// getAuthor
// returns author of book
string ChildrensBook::getAuthor() const{
    return author;
}

//------------------------------------------------------------------------------
// create
// Creates and returns a new ChildrensBook object
Item* ChildrensBook::create() const {
    return new ChildrensBook();
}

//------------------------------------------------------------------------------
// setData
// sets data for book
void ChildrensBook::setData(ifstream& infile) {
    infile.get();
    getline(infile, author, ',');

    infile.get();
    getline(infile, bookTitle, ',');

    infile.get();
    infile >> year;
}

//------------------------------------------------------------------------------
// setCommandData
// Sets the data of the ChildrensBook object
void ChildrensBook::setCommandData(ifstream& inFile) {
    inFile.get();
    inFile >> bookFormat;

    inFile.get();
    getline(inFile, bookTitle, ',');

    inFile.get();
    getline(inFile, author, ',');
}

//------------------------------------------------------------------------------
// display
// Displays the data of the ChildrensBook object
ostream& ChildrensBook::display(ostream& out) const {
    out << left << numOfCopiesIn << setw(22) << author << setw(22) << bookTitle 
    << setw(4) <<  year << setw(4) << bookFormat << endl;
    return out;
}

//------------------------------------------------------------------------------
// operator<
bool ChildrensBook::operator<(const NodeData& bookToCompare) const {
    const ChildrensBook& book = dynamic_cast<const ChildrensBook&>(bookToCompare);
    if (bookTitle < book.bookTitle) {
        return true;
    }
    else if (bookTitle == book.bookTitle) {
        if (author < book.author) {
            return true;
        }
    }
    else {
        return false;
    }
}

//------------------------------------------------------------------------------
// operator==
bool ChildrensBook::operator==(const NodeData& bookToCompare) const {
    const ChildrensBook& book = dynamic_cast<const ChildrensBook&>(bookToCompare);
    return bookTitle == book.bookTitle && author == book.author;
}

//------------------------------------------------------------------------------
// operator<<
// Displays book information
ostream& operator<<(ostream& os, const ChildrensBook& item) {
    return item.display(os);
}
