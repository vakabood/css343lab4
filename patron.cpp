//---------------------------------------------------------------------------
#include "patron.h"
#include "patronAction.h"

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
void Patron::setData(ifstream& infile) {
    infile >> patronId;
    if (infile.eof()) {
        return;
    }
    getline(infile, patronName, '\n');
}

//---------------------------------------------------------------------------
// addCommandToHistory
// Description: Adds a command to the patron's history
void Patron::addCommandToHistory(PatronAction* action) {
    history.push_back(action);
}

//---------------------------------------------------------------------------
// displayHistory
// Description: Displays the patron's history
void Patron::displayHistory() const {
    cout << patronId << " " << patronName << ":" << endl;

    if (!history.empty()) {
        for (int i = 0; i < (int)history.size(); i++) {
            cout << history[i]->getAction() << " ";
            if (history[i]->getAssociatedItem() != nullptr) {
                history[i]->getAssociatedItem()->display();
            }
        }
        cout << endl;
    }
    else {
        cout << patronName << " does not have a history" << endl;
    }
}
//---------------------------------------------------------------------------
// operator==
// Description: Compares two patrons by their id
// Returns true if the two patrons have the same id
bool Patron::operator==(const Patron& other) const {
    return patronId == other.patronId;
}

//---------------------------------------------------------------------------
// operator!=
// Description: Compares two patrons by their id
// Returns true if the two patrons do not have the same id
bool Patron::operator!=(const Patron& other) const {
    return patronId != other.patronId;
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

//---------------------------------------------------------------------------
// getHistory
// Description: Returns the patron's history
vector<PatronAction*> Patron::getHistory() const {
    return history;
}
