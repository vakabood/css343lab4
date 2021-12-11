//---------------------------------------------------------------------------

#include "displayLibrary.h"
#include "library.h"

//---------------------------------------------------------------------------
// Constructor
DisplayLibrary::DisplayLibrary() {
    action = "DisplayLibrary";
    associatedItem = nullptr;
    associatedPatron = nullptr;
}

//---------------------------------------------------------------------------
// Destructor
DisplayLibrary::~DisplayLibrary() { }

//---------------------------------------------------------------------------
// create
// Purpose: Creates the display history object
PatronAction* DisplayLibrary::create() const{
    return new DisplayLibrary();
}

void DisplayLibrary::display() const {
    return;
}

//---------------------------------------------------------------------------
// setData
bool DisplayLibrary::setData(Library *library, ifstream& infile) {
    this->lib = library;
    return true;
}

//---------------------------------------------------------------------------
// perform
// Purpose: Displays the history of a patron
bool DisplayLibrary::perform() {
    lib->display();
    return false;
}