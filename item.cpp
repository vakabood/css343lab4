#include "item.h"

//------------------------------------------------------------------------------
// Constructor
Item::Item() { };

//------------------------------------------------------------------------------
// Destructor
Item::~Item() { };

//------------------------------------------------------------------------------
// operator<<
// Displays item information
ostream& operator<<(ostream& os, const Item& item) {
    item.displayHelper(os);
}