//---------------------------------------------------------------------------

#include "displayHistory.h"
#include "library.h"

//---------------------------------------------------------------------------
// Constructor
DisplayHistory::DisplayHistory() {
    action = "DisplayHistory";
    associatedItem = nullptr;
}

//---------------------------------------------------------------------------
// Destructor
DisplayHistory::~DisplayHistory() { }

//---------------------------------------------------------------------------
// create
// Purpose: Creates the display history object
PatronAction* DisplayHistory::create() const{
    return new DisplayHistory();
}

//---------------------------------------------------------------------------
// setData
void DisplayHistory::setData(Library *library, ifstream& infile) {
    this->lib = library;
    int patronID;
    infile >> patronID;

    associatedPatron = lib->getPatron(patronID);
}

//---------------------------------------------------------------------------
// perform
// Purpose: Displays the history of a patron
void DisplayHistory::perform() {
    associatedPatron->displayHistory();
    associatedPatron->addCommandToHistory(this);
}