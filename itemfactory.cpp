
#include "itemFactory.h"

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Constructor
ItemFactory::ItemFactory() {
    for (int i = 0; i < MAXITEMTYPES; i++)
    {
        itemTemplates[i] = nullptr;    
    }

    itemTemplates[0] = new ChildrensBook();
    itemTemplates[1] = new Fiction();
    itemTemplates[2] = new Periodical();

}

//---------------------------------------------------------------------------
// Destructor
ItemFactory::~ItemFactory() {
    for (int i = 0; i < MAXITEMTYPES; i++)
    {
        if (itemTemplates[i] != nullptr)
        {
            delete itemTemplates[i];
            itemTemplates[i] = nullptr;
        }
    }
}

//---------------------------------------------------------------------------
// Creates an item based on the item type
Item* ItemFactory::createIt(char ch, ifstream& infile) const{
    int index = hash(ch);
    if (itemTemplates[index] == nullptr) {
        return nullptr;
    }
    else {
        return itemTemplates[index]->create();
    }
}

//---------------------------------------------------------------------------
// hash
int ItemFactory::hash(char ch) const {
    return ch - 'A';
}