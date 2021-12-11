//---------------------------------------------------------------------------
// DISPLAY_HISTORY.CPP
// Class DisplayHistory
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------

#include "displayHistory.h"
#include "library.h"

//---------------------------------------------------------------------------
// Constructor
// the string action from patronAction is set to DisplayHistory and the
// associatedItem is initialized
DisplayHistory::DisplayHistory() {
    action = "DisplayHistory";
    associatedItem = nullptr;
    associatedPatron = nullptr;
}

//---------------------------------------------------------------------------
// Destructor
DisplayHistory::~DisplayHistory() {
    
}

//---------------------------------------------------------------------------
// create
// Purpose: Creates the DisplayHistory object
PatronAction* DisplayHistory::create() const{
    return new DisplayHistory();
}

//---------------------------------------------------------------------------
// display
// Prints out action
void DisplayHistory::display() const {
    cout << action << endl;
}

//---------------------------------------------------------------------------
// setData
// reads the file and sets the variables accordingly
bool DisplayHistory::setData(Library *library, ifstream& infile) {
    this->lib = library;
    int patronID;
    infile >> patronID;
    //gets the patron id from library.cpp
    associatedPatron = lib->getPatron(patronID);
    // if patron doesn't exist in library, prints error
    if (associatedPatron == nullptr) {
        cout << "ERROR: Patron with ID " << patronID << 
                    " doesn't exist." << endl;
        return false;
    }
    return true;
}

//---------------------------------------------------------------------------
// perform
// Purpose: Displays the history of a patron. Adds action to patron 
// history.
bool DisplayHistory::perform() {
    associatedPatron->displayHistory();
    associatedPatron->addCommandToHistory(this);
    return true;
}
