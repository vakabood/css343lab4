#include "library.h"

Library::Library()
{
    //ctor
}

Library::~Library()
{
    //dtor
} 

void Library::buildLibrary(ifstream& infile) {
    for (;;) {
        infile >> bookType;

        if (infile.eof()) {
            break;
        }
        Item* itemPtr = libraryItemFactory.createIt(bookType);

        if (itemPtr != nullptr) {
            itemPtr->setData(infile);

            bool success = itemTypes[bookType - 'A'].insert(itemPtr);
            if (!success) {
                delete itemPtr;
            }
        }
    }
}

void Library::display() const {
    for (int i = 0; i < 26; i++) {
        if (!itemTypes[i].isEmpty()) {
            cout << itemTypes[i];
        }
    }
}
