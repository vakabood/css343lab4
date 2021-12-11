#include "childrensBook.h"

//------------------------------------------------------------------------------
// Constructor
ChildrensBook::ChildrensBook() : Book(){
    author = "";
    genre = "CHILDREN";
    bookTitle = "";
    year = 0;
    bookFormat = 'H';
    totalCopies = 5;
    numOfCopiesIn = 5;
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
    cout << left << 
    setw(MAX_TITLE_LENGTH + 2) << bookTitle.substr(0, MAX_TITLE_LENGTH) << 
    setw(MAX_AUTHOR_LENGTH + 2) << 
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
    return false;
}

//------------------------------------------------------------------------------
// operator==
bool ChildrensBook::operator==(const NodeData& bookToCompare) const {
    const ChildrensBook& book = dynamic_cast<const ChildrensBook&>(bookToCompare);
    return bookTitle == book.bookTitle && author == book.author;
}

void ChildrensBook::displayData() const {
    cout << left << setw(7) << numOfCopiesIn << left << setw(MAX_TITLE_LENGTH + 5) <<
    bookTitle.substr(0, MAX_TITLE_LENGTH) << setw(MAX_AUTHOR_LENGTH) << 
    author.substr(0, MAX_AUTHOR_LENGTH) << right << setw(8) << year << endl;
}

void ChildrensBook::displayHeader() const {
    cout << genre << " BOOKS" << endl;
    cout << left << setw(7) << "AVAIL" << left << setw(MAX_TITLE_LENGTH + 5) <<
    "TITLE" << setw(MAX_AUTHOR_LENGTH) << 
    "AUTHOR" << right << setw(8) << "YEAR" << endl;
}