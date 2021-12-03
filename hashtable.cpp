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
    HashTable();
}

//---------------------------------------------------------------------------
// add
// adds a patron to the hashtable
bool HashTable::add(Patron* patron) {
    if (size == MAX_SIZE || patron->getPatronId() < 1000 
        || patron->getPatronId() > 9999) {
        return false;
    }
    if (table[hash(patron->getPatronId())] != nullptr) {
        cout << "Patron already exists" << endl;
        delete patron;
        return false;
    }
    table[hash(patron->getPatronId())] = patron;
    size++;
    return true;
}

//---------------------------------------------------------------------------
// hash
// returns the hash value of the patron id
int HashTable::hash(int patronId) const{
    return patronId - 1000;
}

Patron* HashTable::get(int patronId) const {
    if (patronId < 1000 || patronId > 9999) {
        return nullptr;
    }
    return table[hash(patronId)];
}



