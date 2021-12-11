//---------------------------------------------------------------------------
// RETURN.CPP
// Class return checks out an item and is the subclass of patronAction.
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------

#include "return.h"
#include "library.h"

//---------------------------------------------------------------------------
// Constructor
// Action is set to "Return  " and tempItem is initialized. We added spaces
// after return in action for formatting reasons.
Return::Return() {
    action = "Return  ";
    tempItem = nullptr;
}

//---------------------------------------------------------------------------
// Destructor
// Deletes tempItem
Return::~Return() { 
    delete tempItem;
}

//---------------------------------------------------------------------------
// create
// Returns a Return Object
PatronAction* Return::create() const {
    return new Return();
}

//---------------------------------------------------------------------------
// display
// Prints action and displays associatedItem which contains the data as long
// as it is not empty
void Return::display() const {
    cout << action << "  ";
    if (associatedItem != nullptr) {
        associatedItem->display();
    }
}

//---------------------------------------------------------------------------
// setData
// Sets the data for the return object
bool Return::setData(Library *library, ifstream& infile) {
    this->lib = library;
    int patronID;
    infile >> patronID;
    //if associatedPatron exists, it reads the text file and calls the
    // createIt function to create a tempItem which is used to do the
    // action. If tempItem is a nullptr, an error message is thrown. If the
    // item is valid, true will be returned. Else, false will be returned.
    associatedPatron = lib->getPatron(patronID);

    // if associatedPatron is invalid, prints error
    if (associatedPatron == nullptr) {
        string temp;
        getline(infile, temp, '\n');
        cout << "ERROR: Patron with ID " << patronID << 
                    " doesn't exist." << endl;
        return false;
    } else { // if associated patron is valid

        // assigns itemType to the itemType to be returned
        infile >> itemType;
        ItemFactory itemfactory = ItemFactory();

        // Creates the item using itemFactory
        tempItem = itemfactory.createIt(itemType, infile);

        // if the item is invalid, prints error
        if (tempItem == nullptr) {
            cout << "ERROR: " << '\'' << itemType << '\'' << 
                        " is not a valid LibItem type." << endl;
            string temp;
            getline(infile, temp, '\n');
            return false;
        } else {
            // sets the command file data for the item
            tempItem->setCommandData(infile);

            // checks if item is in library
            associatedItem = lib->inLibrary(itemType, tempItem);
            // if the item is invalid, prints error
            if (associatedItem == nullptr) {
                cout << "ERROR: " << associatedPatron->getName() << 
                    " tried to return " << '\'' << 
                    tempItem->getBookTitle() << '\'' <<
                    " - not found in catalog." << endl;
                // returns false if item is not in library
                return false;
            }
        }
    }
    return true;
}

//---------------------------------------------------------------------------
// perform
// Performs the return action. Returns true if the return action is 
// completed and returns false if the return action could not be completed
bool Return::perform() {
    if (associatedItem != nullptr) {
        // if the item is okay to be returned, it is returned and true
        // is returned
        if (associatedItem->getNumOfCopiesIn() < 5) {
            associatedItem->incrementCopies();
            // adds return action to history of associatedPatron
            associatedPatron->addCommandToHistory(this);
            return true;
        } else {
            //The number of books with the same title in the library is 5 or
            // more
            cout << "ERROR: The library has reached the maximum"  << 
                    " inventory of " <<
                    associatedItem->getBookTitle() << endl;
            return false;
        }
    } else {
        return false;
    } 
    
}
