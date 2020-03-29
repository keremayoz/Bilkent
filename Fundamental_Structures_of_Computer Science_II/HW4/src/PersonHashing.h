/**
 * Title: Balanced Search Trees and Hashing
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 4
 * Description: Header file of the PersonHashing class.
 * It hashes the person objects by using seperate chaining. It uses 11 sized table.
 * h(x) = (sum of all ASCI codes of each letter in the name) mod 11
 */

#ifndef PersonHashing_h
#define PersonHashing_h
#include "Person.h"

class PersonHashing {
public:
    
    //Constructor and destructor
    PersonHashing();
    ~PersonHashing();
    
    //Member functions
    int calculateHash(string name);
    void insert(Person *inserted);
    Person* retrieve(string name);
    void clearAll();
    void displayHashTable();
    
    //HashNode for seperate chaning system
    struct HashNode {
        Person *p;
        HashNode *next;
    };
    
    //Hash Table
    HashNode **hashTable;
    
};

#endif /* PersonHashing_h */
