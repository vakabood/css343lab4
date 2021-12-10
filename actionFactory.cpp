//---------------------------------------------------------------------------

#include "actionFactory.h"
#include "patronAction.h"

//---------------------------------------------------------------------------
// Constructor
ActionFactory::ActionFactory() {
    for (int i = 0; i < MAX_COMMAND_TYPES; i++) {
        actionTemplates[i] = nullptr;
    }

    actionTemplates[2] = new Checkout();
    actionTemplates[3] = new DisplayLibrary();
    actionTemplates[7] = new DisplayHistory();
    actionTemplates[17] = new Return();
}

//---------------------------------------------------------------------------
// Destructor
ActionFactory::~ActionFactory() {
    for (int i = 0; i < MAX_COMMAND_TYPES; i++) {
        if (actionTemplates[i] != nullptr) {
            delete actionTemplates[i];
            actionTemplates[i] = nullptr;
        }
    }
}

//---------------------------------------------------------------------------
// Creates an action object based on the command type
PatronAction* ActionFactory::createIt(char ch, istream& infile) const{
    int index = hash(ch);
    if (actionTemplates[index] == nullptr) {
        string valid;
        getline(infile, valid, '\n');
        return nullptr;
    }
    return actionTemplates[index]->create();
}

//---------------------------------------------------------------------------
// hash
int ActionFactory::hash(char ch) const {
    return ch - 'A';
}