//---------------------------------------------------------------------------

#include "checkout.h"
#include "library.h"

//---------------------------------------------------------------------------
// Consructor
Checkout::Checkout() {
    action = "CheckOut";
    tempItem = nullptr;
}

//---------------------------------------------------------------------------
// Destructor
Checkout::~Checkout() {
    delete tempItem;
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
    infile >> patronID;
    associatedPatron = lib->getPatron(patronID);

    if (associatedPatron == nullptr) {
        string temp;
        getline(infile, temp);
        cout << "ERROR: Patron with ID " << patronID << 
                    " doesn't exist." << endl;
    } else {
        infile >> itemType;
        ItemFactory itemfactory = ItemFactory();
        tempItem = itemfactory.createIt(itemType, infile);
        if (tempItem == nullptr) {
            cout << "ERROR: " << '\'' << itemType << '\'' << 
                        " is not a valid LibItem type." << endl;
            string temp;
            getline(infile, temp);
        } else {
            tempItem->setCommandData(infile);
        }
    }
}

//---------------------------------------------------------------------------
// perform
// Performs the checkout action
void Checkout::perform() {
    associatedItem = lib->inLibrary(itemType, tempItem);
    if (associatedItem != nullptr) {
        if (associatedItem->getNumOfCopiesIn() > 0) {
            associatedItem->decrementCopies();
            associatedPatron->addCommandToHistory(this);
        }
    } else {
        cout << "ERROR: " << associatedPatron->getName() << 
                    " tried to check out " << '\'' << 
                    associatedItem->getBookTitle() << '\'' <<
                    " - not found in catalog.";
    }
}