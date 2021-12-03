#include "childrensBook.h"

//------------------------------------------------------------------------------
// Constructor
ChildrensBook::ChildrensBook() {

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
// setData
// Sets the data of the ChildrensBook object
bool ChildrensBook::setData(ifstream& is) {
    
}