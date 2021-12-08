#include "fiction.h"

//---------------------------------------------------------------------------
// Constructor
Fiction::Fiction() {
    author = "";
    bookTitle = "";
    year = 0;
    bookFormat = 'H';
    totalCopies = 5;
    numOfCopiesIn = 5;
}

//---------------------------------------------------------------------------
// Destructor
Fiction::~Fiction() { }

//---------------------------------------------------------------------------
// create()
// Creates a fiction book object
Item* Fiction::create() const{
    return new Fiction();
}

void Fiction::setData(ifstream& infile) {
    infile.get();
    getline(infile, author, ',');

    infile.get();
    getline(infile, bookTitle, ',');

    infile.get();
    infile >> year;
}

//---------------------------------------------------------------------------
// setCommandData()
void Fiction::setCommandData(ifstream& inFile) {
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
void Fiction::display() const {
    cout << left << setw(7) << numOfCopiesIn << left << setw(MAX_AUTHOR_LENGTH) <<
    author.substr(0, MAX_AUTHOR_LENGTH) << setw(MAX_TITLE_LENGTH + 5) << 
    bookTitle.substr(0, MAX_TITLE_LENGTH) << right << setw(8) << year << endl;
}

//---------------------------------------------------------------------------
// operator<
// Overloaded less than operator
bool Fiction::operator<(const NodeData& bookToCompare) const {
    const Fiction& book = dynamic_cast<const Fiction&>(bookToCompare);
    if (author < book.author) {
        return true;
    }
    else if (author == book.author) {
        if (bookTitle < book.bookTitle) {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------------
// operator==
// Overloaded equality operator
bool Fiction::operator==(const NodeData& bookToCompare) const {
    const Fiction& book = dynamic_cast<const Fiction&>(bookToCompare);
    return author == book.author && bookTitle == book.bookTitle;
}

//------------------------------------------------------------------------------
// operator<<
// Displays book information
ostream& operator<<(ostream& os, const Fiction& item) {
    //return item.display(os);
    return os;
}


