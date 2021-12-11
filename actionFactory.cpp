//---------------------------------------------------------------------------
// ACTION_FACTORY.CPP
// Class ActionFactory creates different types of patron actions
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------

#include "actionFactory.h"
#include "patronAction.h"

//---------------------------------------------------------------------------
// Constructor
// Creates an action factory. Initializes each PatronAction pointer to
// nullptr. Initializes the current action type to a new action object.
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
// Deallocates the action factory. Deletes each PatronAction pointer..
ActionFactory::~ActionFactory() {
    for (int i = 0; i < MAX_COMMAND_TYPES; i++) {
        if (actionTemplates[i] != nullptr) {
            delete actionTemplates[i];
            actionTemplates[i] = nullptr;
        }
    }
}

//---------------------------------------------------------------------------
// createIt
// Creates a PatronAction object based on the command type.
// Returns a pointer to the PatronAction object based on the char parameter
// by calling create on the PatronAction object at the hashed index.
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
// function returns an int that corresponds to the char from the parameter's
// index
int ActionFactory::hash(char ch) const {
    return ch - 'A';
}