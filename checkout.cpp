//---------------------------------------------------------------------------

#include "checkout.h"
#include "library.h"

//---------------------------------------------------------------------------
// Consructor
Checkout::Checkout() {
    action = "CheckOut";
    tempItem = nullptr;
    itemType = (char)0;
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

void Checkout::display() const {
    cout << action << "  ";
    if (associatedItem != nullptr) {
    	associatedItem->display();
    }
}

//---------------------------------------------------------------------------
// setData
// Sets the data for the checkout object
bool Checkout::setData(Library *library, ifstream& infile) {
    this->lib = library;
    infile >> patronID;
    associatedPatron = lib->getPatron(patronID);

    if (associatedPatron == nullptr) {
        string temp;
        getline(infile, temp, '\n');
        cout << "ERROR: Patron with ID " << patronID << 
                    " doesn't exist." << endl;
        return false;
    } else {
        infile >> itemType;
        ItemFactory itemfactory = ItemFactory();
        tempItem = itemfactory.createIt(itemType, infile);
        if (tempItem == nullptr) {
            cout << "ERROR: " << '\'' << itemType << '\'' << 
                        " is not a valid LibItem type." << endl;
            string temp;
            getline(infile, temp, '\n');
            return false;
        } else {
            tempItem->setCommandData(infile);
            associatedItem = lib->inLibrary(itemType, tempItem);
            if (associatedItem == nullptr) {
                cout << "ERROR: " << associatedPatron->getName() << 
                    " tried to check out " << '\'' << 
                    tempItem->getBookTitle() << '\'' <<
                    " - not found in catalog." << endl;
                return false;
            }
        }
    }
    return true;
}

//---------------------------------------------------------------------------
// perform
// Performs the checkout action
bool Checkout::perform() {
    if (associatedItem != nullptr) {
        if (associatedItem->getNumOfCopiesIn() > 0) {
            associatedItem->decrementCopies();
            associatedPatron->addCommandToHistory(this);
            return true;
        } else {
            cout << "ERROR: There are no more copies of "  << 
                    associatedItem->getBookTitle() << " in the library" <<
                    endl;
            return false;
        }
    } 
    return false;
}
