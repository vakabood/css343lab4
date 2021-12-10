//---------------------------------------------------------------------------

#include "checkout.h"
#include "library.h"

//---------------------------------------------------------------------------
// Consructor
Checkout::Checkout() {
    action = "checkout";
    associatedItem = nullptr;
}

//---------------------------------------------------------------------------
// Destructor
Checkout::~Checkout() { 
    delete associatedItem;
}

//---------------------------------------------------------------------------
// create
// Creates and returns a checkout object
PatronAction* Checkout::create() const {
    return new Checkout();
}

//---------------------------------------------------------------------------
// setData
// Sets the data for the checkout object
void Checkout::setData(Library *library, ifstream& infile) {
    this->lib = library;
    int patronID;
    infile >> patronID;
    //cout << "here" << endl;
    associatedPatron = lib->getPatron(patronID);
    //associatedPatron = patrons.get(patronID);

    infile >> itemType;
    ItemFactory itemfactory = ItemFactory();
    associatedItem = itemfactory.createIt(itemType, infile);

    associatedItem->setCommandData(infile);
}

//---------------------------------------------------------------------------
// perform
// Performs the checkout action
void Checkout::perform() {
    Item* item = lib->inLibrary(itemType, associatedItem);
    
    if (item != nullptr) {
        if (item->getNumOfCopiesIn() > 0) {
            item->decrementCopies();
            associatedPatron->addCommandToHistory(this);
            associatedPatron->displayHistory();
        }
    }
}