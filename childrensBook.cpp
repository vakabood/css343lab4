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
// create
// Creates and returns a new ChildrensBook object
Item* ChildrensBook::create() const {
    return new ChildrensBook();
}

//------------------------------------------------------------------------------
// setCommandData
// Sets the data of the ChildrensBook object
void ChildrensBook::setCommandData(ifstream& inFile) {
    inFile.get();
    getline(inFile, bookTitle, ',');
    inFile >> year;
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
