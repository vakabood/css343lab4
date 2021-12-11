//---------------------------------------------------------------------------
// CHECKOUT.H
// Class Checkout checks out an item from the library
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------

#include "checkout.h"
#include "library.h"

//---------------------------------------------------------------------------
// Consructor
// Initializes action and sets tempItem to nullptr
Checkout::Checkout() {
    action = "CheckOut";
    tempItem = nullptr;
    itemType = (char)0;
}

//---------------------------------------------------------------------------
// Destructor
// deletes tempItem
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
// display
// Prints action and displays associatedItem which contains the data as long
// as it is not empty
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
    associatedPatron = lib->getPatron(patronID); //getPatron in library.cpp
    if (associatedPatron == nullptr) {  //checks if the patron exists
        string temp;
        getline(infile, temp, '\n');
        cout << "ERROR: Patron with ID " << patronID << 
                    " doesn't exist." << endl;
        return false;
    } else {
        //if associatedPatron exists, it reads the text file and calls the
        // createIt function to create a tempItem which is used to do the
        // action. If tempItem is a nullptr, an error message is thrown. If the
        // item is valid, true will be returned. Else, false will be returned
        infile >> itemType;
        ItemFactory itemfactory = ItemFactory();
        tempItem = itemfactory.createIt(itemType, infile);
        // If tempItem is a nullptr, an error message is thrown. If the
        // item is valid, true will be returned. Else, false will be returned
        if (tempItem == nullptr) {
            cout << "ERROR: " << '\'' << itemType << '\'' << 
                        " is not a valid LibItem type." << endl;
            string temp;
            getline(infile, temp, '\n');
            return false;
        } else {
            tempItem->setCommandData(infile); // sets the data for the item
            // checks if the item is in the library
            associatedItem = lib->inLibrary(itemType, tempItem);
            // if item is not in the library, prints error, returns false.
            if (associatedItem == nullptr) {
                cout << "ERROR: " << associatedPatron->getName() << 
                    " tried to check out " << '\'' << 
                    tempItem->getBookTitle() << '\'' <<
                    " - not found in catalog." << endl;
                return false;
            }
        }
    }
    // item is valid and ready to be checked out.
    return true;
}

//---------------------------------------------------------------------------
// perform
// Performs the checkout action. Returns true if the checkout action is
// completed and returns false if the checkout action could not be completed
bool Checkout::perform() {
    if (associatedItem != nullptr) {
        // checks if there are copies of the item in the library
        if (associatedItem->getNumOfCopiesIn() > 0) {
            associatedItem->decrementCopies();
            associatedPatron->addCommandToHistory(this);
            return true;
        } else {
            // prints error if no copies are available 
            cout << "ERROR: There are no more copies of "  << 
                    associatedItem->getBookTitle() << " in the library" <<
                    endl;
            return false;
        }
    } 
    return false;
}
