//---------------------------------------------------------------------------
// HASHTABLE.CPP
// Class HashTable represents the storage of Patrons
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
#include "patron.h"
#include "hashtable.h"

//---------------------------------------------------------------------------
// Constructor
// initializes size as 0. intializes the array of pointers to nullptr
HashTable::HashTable() {
    size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        table[i] = nullptr;
    }
}

//---------------------------------------------------------------------------
// Destructor
// deletes all the patrons in the hashtable
HashTable::~HashTable() {
    clear();
}

//---------------------------------------------------------------------------
// clear
// deletes all the patrons in the hashtable
void HashTable::clear() {
    for (int i = 0; i < MAX_SIZE; i++) {
        delete table[i];
    }
}

//---------------------------------------------------------------------------
// add
// adds a patron to the hashtable
bool HashTable::add(Patron* patron) {
    // checks if hashtable is already full. checks if patron id is valid
    if (size == MAX_SIZE || patron->getPatronId() < MIN_ID 
        || patron->getPatronId() > MAX_ID) {
        return false;
    }
    // If the patron ID is already in the library
    if (table[hash(patron->getPatronId())] != nullptr) {
        cout << "Patron already exists" << endl;
        delete patron;
        patron = nullptr;
        return false;
    }
    // Adds the patron to the hashtable
    // Calls hash with the Id to get appropriate index to insert at
    table[hash(patron->getPatronId())] = patron;
    size++;
    return true;
}

//---------------------------------------------------------------------------
// hash
// returns the hash value of the patron id
int HashTable::hash(int patronId) const{
    return patronId;
}

//---------------------------------------------------------------------------
// get
// returns the patron with the given id
Patron* HashTable::get(int patronId) const {
    // checks if id is valid
    if (patronId < MIN_ID || patronId > MAX_ID) {
        return nullptr;
    }
    return table[hash(patronId)];
}



