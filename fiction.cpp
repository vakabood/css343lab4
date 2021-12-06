#include "fiction.h"

//---------------------------------------------------------------------------
// Constructor
Fiction::Fiction() {
    author = "";
    bookTitle = "";
    year = 0;
    bookFormat = 'H';
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

//---------------------------------------------------------------------------
// setCommandData()
void Fiction::setCommandData(ifstream& inFile) {
    inFile.get();
    getline(inFile, bookTitle, ',');
    inFile >> year;
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
    else {
        return false;
    }
}

//---------------------------------------------------------------------------
// operator==
// Overloaded equality operator
bool Fiction::operator==(const NodeData& bookToCompare) const {
    const Fiction& book = dynamic_cast<const Fiction&>(bookToCompare);
    return author == book.author && bookTitle == book.bookTitle;
}


