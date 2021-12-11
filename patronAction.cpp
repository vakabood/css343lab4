//---------------------------------------------------------------------------

#include "patronAction.h"
#include "library.h"

//---------------------------------------------------------------------------
// Constructor
PatronAction::PatronAction() {
    associatedItem = nullptr;
    associatedPatron = nullptr;
    action = "";
}

//---------------------------------------------------------------------------
// Destructor
PatronAction::~PatronAction() { }

//---------------------------------------------------------------------------
// getAssociatedPatron
// Returns the patron associated with this action
Patron* PatronAction::getAssociatedPatron() const{
    return associatedPatron;
}

//---------------------------------------------------------------------------
// getAssociatedItem
// Returns the item associated with this action
Item* PatronAction::getAssociatedItem() const{
    return associatedItem;
}

string PatronAction::getAction() const {
    return action;
}
