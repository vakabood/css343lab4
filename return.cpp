//---------------------------------------------------------------------------

#include "return.h"
#include "library.h"

//---------------------------------------------------------------------------
// Constructor
Return::Return() {
    action = "Return";
    tempItem = nullptr;
}

//---------------------------------------------------------------------------
// Destructor
Return::~Return() { 
    delete tempItem;
}

//---------------------------------------------------------------------------
// create
PatronAction* Return::create() const {
    return new Return();
}

//---------------------------------------------------------------------------
// setData
void Return::setData(Library *library, ifstream& infile) {
    this->lib = library;
    int patronID;
    infile >> patronID;

    associatedPatron = lib->getPatron(patronID);

    infile >> itemType;
    ItemFactory itemfactory = ItemFactory();
    tempItem = itemfactory.createIt(itemType, infile);
    
    tempItem->setCommandData(infile);
}

//---------------------------------------------------------------------------
// perform
void Return::perform() {
    associatedItem = lib->inLibrary(itemType, tempItem);

    if (associatedItem != nullptr) {
        if (associatedItem->getNumOfCopiesIn() < 5) {
            associatedItem->incrementCopies();
            associatedPatron->addCommandToHistory(this);
        }
    }
}