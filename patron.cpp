//---------------------------------------------------------------------------
#include "patron.h"

//---------------------------------------------------------------------------
// Constructor
Patron::Patron() {
    patronName = "";
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
    infile >> patronName;
}
/*
//---------------------------------------------------------------------------
// addCommandToHistory
// Description: Adds a command to the patron's history
void Patron::addCommandToHistory(PatronAction& action) {
    history.push_back(action);
}
*/
//---------------------------------------------------------------------------
// displayHistory
// Description: Displays the patron's history
void Patron::displayHistory() const {
    return;
}

//---------------------------------------------------------------------------
// getPatronId
// Description: Returns the patron's id
int Patron::getPatronId() const {
    return patronId;
}

//---------------------------------------------------------------------------
// getFirstName
// Description: Returns the patron's first name
string Patron::getName() const {
    return patronName;
}
