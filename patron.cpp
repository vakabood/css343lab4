//---------------------------------------------------------------------------
#include "patron.h"

//---------------------------------------------------------------------------
// Constructor
Patron::Patron() {
    firstName = "";
    lastName = "";
    patronId = 0;
}

//---------------------------------------------------------------------------
// Destructor
Patron::~Patron() { }

//---------------------------------------------------------------------------
// setData
// Description: Sets the data for the patron
void Patron::setData(istream& infile) {
    infile >> patronId;
    if (infile.eof()) {
        return;
    }

    infile.get();
    infile >> lastName;

    infile.get();
    infile >> firstName;
}

//---------------------------------------------------------------------------
// addCommandToHistory
// Description: Adds a command to the patron's history
void Patron::addCommandToHistory(PatronAction& action) {
    history.push_back(action);
}

//---------------------------------------------------------------------------
// displayHistory
// Description: Displays the patron's history
