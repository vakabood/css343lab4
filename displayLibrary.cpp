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

//---------------------------------------------------------------------------
// setData
void DisplayLibrary::setData(Library *library, ifstream& infile) {
    this->lib = library;
    return;
}

//---------------------------------------------------------------------------
// perform
// Purpose: Displays the history of a patron
void DisplayLibrary::perform() {
    lib->display();
}