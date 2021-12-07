//---------------------------------------------------------------------------
// ITEM_FACTORY.H
// Class ItemFactory 
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
//---------------------------------------------------------------------------
// ItemFactory class: 
//      -- Follows the factory design pattern
//      -- Factory design pattern is used for creating families of related 
//            or dependent objects without specifying their concrete classes
//      -- Creates the desired item
//---------------------------------------------------------------------------
#ifndef _ITEM_FACTORY_H
#define _ITEM_FACTORY_H

#include "item.h"
#include "childrensBook.h"
#include "fiction.h"
#include "periodical.h"


const int MAXITEMTYPES = 26; 

// Item Factory class is a factory for creating different types of items 
class ItemFactory {
public:
  // Constructor - creates a new ItemFactory object
  ItemFactory();

  // Destructor
  virtual ~ItemFactory();

  // Creates and returns a new instance of an Item. Takes in a char
  // representing an item type (C for childrens book)
  Item* createIt(char) const;
  
private:
  Item* itemTemplates[MAXITEMTYPES]; // array with a size of 26 to contain 
                           // different types of item templates

  // hashing function to identify the key of the action that needs to be 
  //    created
  int hash(char) const; 
};
#endif