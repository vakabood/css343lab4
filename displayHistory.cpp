//---------------------------------------------------------------------------

#include "displayHistory.h"
#include "library.h"

//---------------------------------------------------------------------------
// Constructor
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
// Purpose: Creates the display history object
PatronAction* DisplayHistory::create() const{
    return new DisplayHistory();
}

void DisplayHistory::display() const {
    cout << action << endl;
}

//---------------------------------------------------------------------------
// setData
bool DisplayHistory::setData(Library *library, ifstream& infile) {
    this->lib = library;
    int patronID;
    infile >> patronID;

    associatedPatron = lib->getPatron(patronID);
    if (associatedPatron == nullptr) {
        //string temp;
        //getline(infile, temp, '\n');
        cout << "ERROR: Patron with ID " << patronID << 
                    " doesn't exist." << endl;
        return false;
    }
    return true;
}

//---------------------------------------------------------------------------
// perform
// Purpose: Displays the history of a patron
bool DisplayHistory::perform() {
    associatedPatron->displayHistory();
    associatedPatron->addCommandToHistory(this);
    return true;
}
