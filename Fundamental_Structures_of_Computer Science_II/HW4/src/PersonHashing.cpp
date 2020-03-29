/**
 * Title: Balanced Search Trees and Hashing
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 4
 * Description: Implemented the methods of PersonHashing.h
 */

#include <stdio.h>
#include "PersonHashing.h"

//Constructor: initializes the hash table for person objects
PersonHashing::PersonHashing() {
    hashTable = new HashNode*[11];
    for (int i = 0; i < 11; i++)
        hashTable[i] = NULL;
}

//Destructor for the person object
PersonHashing::~PersonHashing() {
    for (int i = 0; i < 11; i++) {
        //Delete every chain
        HashNode *cur = hashTable[i];
        while (cur != NULL) {
            HashNode *temp = cur;
            cur = cur->next;
            temp->next = NULL;
            temp->p = NULL;
            delete temp;
        }
        hashTable[i] = NULL;
    }
    //Delete table
    delete [] hashTable;
}

//Calculate the hash value for person by summing up the ASCI codes in the string name
int PersonHashing::calculateHash(string name) {
    int h = 0;
    for (int i =0; name[i] != '\0'; i++) // the loop condition didn't seem good
    {
        // the cast to unsigned char may be needed for system in which the type char is signed
        h = (h + (unsigned char)name[i]) % 11;
    }
    return h;
}

//Inserts the element into the hash table
void PersonHashing::insert(Person *inserted) {
    int hash = calculateHash(inserted->name);
    if (hashTable[hash] == NULL) {
        hashTable[hash] = new HashNode;
        hashTable[hash]->p = inserted;
        hashTable[hash]->next = NULL;
    }
    else {
        HashNode *temp = hashTable[hash];
        hashTable[hash] = new HashNode;
        hashTable[hash]->p = inserted;
        hashTable[hash]->next = temp;
    }
}

//Retrieve the person by his name with returning a pointer to it
Person* PersonHashing::retrieve(string name) {
    int hash = calculateHash(name);
    if (hashTable[hash] != NULL) {
        //Search for the person
        HashNode *cur = hashTable[hash];
        while (cur != NULL && cur->p->name != name)
            cur = cur->next;
        //If not in the hash table
        if (cur == NULL)
            return NULL;
        else
            return cur->p;
    }
    //If not in the hash table
    return NULL;
}

//Helper function that clears the hash table and resets it to the initial state.
void PersonHashing::clearAll() {
    for (int i = 0; i < 11; i++) {
        HashNode *cur = hashTable[i];
        while (cur != NULL) {
            HashNode *temp = cur;
            cur = cur->next;
            delete temp->p;
            temp->next = NULL;
            temp->p = NULL;
            delete temp;
        }
        hashTable[i] = NULL;
    }
}

//Displays the table content
void PersonHashing::displayHashTable() {
    for (int i = 0; i < 11; i++) {
        HashNode *cur = hashTable[i];
        cout << i << "th row : ";
        while (cur != NULL) {
            cout << cur->p->name << ", ";
            cur = cur->next;
        }
        cout << endl;
    }
}

