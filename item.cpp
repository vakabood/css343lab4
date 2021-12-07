#include "item.h"

//------------------------------------------------------------------------------
// Constructor
Item::Item() { 
    totalCopies = 0;
    numOfCopiesIn = -1;
};

//------------------------------------------------------------------------------
// Destructor
Item::~Item() { };

//------------------------------------------------------------------------------
// incrementCopies
// Increments the number of copies of the item
void Item::incrementCopies() {
    numOfCopiesIn++;
};

//------------------------------------------------------------------------------
// decrementCopies
// Decrements the number of copies of the item
void Item::decrementCopies() {
    numOfCopiesIn--;
};

//------------------------------------------------------------------------------
// getNumOfCopies
// Returns the number of copies of the item in the library
int Item::getNumOfCopiesIn() {
    return numOfCopiesIn;
};

//------------------------------------------------------------------------------
// getNumOfCopiesOut
// Returns the number of copies of the item checked out of the library
int Item::getNumOfCopiesOut() {
    return totalCopies - numOfCopiesIn;
};

/*
//------------------------------------------------------------------------------
// operator<<
// Displays item information
ostream& operator<<(ostream& os, const Item& item) {
    item.displayHelper(os);
}
*/