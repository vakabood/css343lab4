//---------------------------------------------------------------------------
// ACTION_FACTORY.H
// Class ActionFactory creates different types of patron actions
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
//---------------------------------------------------------------------------
// ActionFactory class: 
//      -- Follows the Factory design pattern
//      -- Factory design pattern is used for creating families of related 
//            or dependent objects without specifying their concrete classes
//      -- Creates the desired patron action 
//---------------------------------------------------------------------------

#ifndef _ACTION_FACTORY_H
#define _ACTION_FACTORY_H

#include "patronAction.h"

using namespace std;
// Action Factory class is factory for creating different types of patron 
//    actions
class ActionFactory {
public:
  // Constructor - creates an action factory
  ActionFactory();

  // Destructor - deallocates the action factory
  virtual ~ActionFactory();

  // Creates a specific type of action based on the given char
  PatronAction* createIt(char) const;
  
private:
  PatronAction* actionTemplates[26];  // array of template actions that can 
                                      //    be performed
  
  // hashing function to identify the key of the action that needs to be 
  //    created
  int hash(char) const;
};


#endif
