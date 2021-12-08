#include "childrensBook.h"

//------------------------------------------------------------------------------
// Constructor
ChildrensBook::ChildrensBook() : Book(){
    author = "";
    bookTitle = "";
    year = 0;
    bookFormat = 'H';
    totalCopies = 5;
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

    //infile.get();
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
void ChildrensBook::display() const{
    cout << left << setw(7) << numOfCopiesIn << left << setw(MAX_TITLE_LENGTH + 5) <<
    bookTitle.substr(0, MAX_TITLE_LENGTH) << setw(MAX_AUTHOR_LENGTH) << 
    author.substr(0, MAX_AUTHOR_LENGTH) << right << setw(8) << year << endl;
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
ostream& operator<<(ostream& out, const ChildrensBook& item) {
    out << left << item.numOfCopiesIn << setw(22) << item.author << setw(22) << item.bookTitle 
    << setw(4) <<  item.year << setw(4) << item.bookFormat << endl;
    return out;
}
