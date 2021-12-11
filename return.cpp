//---------------------------------------------------------------------------

#include "return.h"
#include "library.h"

//---------------------------------------------------------------------------
// Constructor
Return::Return() {
    action = "Return  ";
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

void Return::display() const {
    cout << action << "  ";
    if (associatedItem != nullptr) {
        associatedItem->display();
    }
}

//---------------------------------------------------------------------------
// setData
bool Return::setData(Library *library, ifstream& infile) {
    this->lib = library;
    int patronID;
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
                    " tried to return " << '\'' << 
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
bool Return::perform() {
    if (associatedItem != nullptr) {
        if (associatedItem->getNumOfCopiesIn() < 5) {
            associatedItem->incrementCopies();
            associatedPatron->addCommandToHistory(this);
            return true;
        } else {
            cout << "ERROR: The library has reached the maximum"  << 
                    " inventory of " <<
                    associatedItem->getBookTitle() << endl;
            return false;
        }
    } else {
        return false;
    } 
    
}
