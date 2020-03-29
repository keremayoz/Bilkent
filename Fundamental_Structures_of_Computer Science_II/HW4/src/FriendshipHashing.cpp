/**
 * Title: Balanced Search Trees and Hashing
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 4
 * Description: Implemented the functions of the FriendshipHashing.h
 */

#include <stdio.h>
#include "FriendshipHashing.h"

//Constructor: initializes the hash table for Friendship objects
FriendshipHashing::FriendshipHashing() {
    hashTable = new Friendship*[71];
    for (int i = 0; i < 71; i++)
        hashTable[i] = NULL;
}

//Destructor: deletes the hash table
FriendshipHashing::~FriendshipHashing() {
    for (int i = 0; i < 71; i++)
        delete hashTable[i];
    delete [] hashTable;
}

//Calculates the hash value by summing up all character's ASCI codes in the name of the friendship
int FriendshipHashing::calculateHash(string nameOfFriendship) {
    int h = 0;
    for (int i =0; nameOfFriendship[i] != '\0'; i++) // the loop condition didn't seem good
    {
        // the cast to unsigned char may be needed for system in which the type char is signed
        h = (h + (unsigned char)nameOfFriendship[i]) % 71;
    }
    return h;
}

//Inserts new element to the hash table.
void FriendshipHashing::insert(Friendship *inserted) {
    int hash = calculateHash(inserted->nameOfFriendship);
    if (hashTable[hash] == NULL)
        hashTable[hash] = inserted;
    else {
        int i = 1;
        while (hashTable[(hash+i*i)%71] != NULL)
            i++;
        hashTable[(hash+i*i)%71] = inserted;
    }
}

//Displays the hash table
void FriendshipHashing::displayHashTable() {
    for (int i = 0; i < 71; i++) {
        cout << i << "th row : ";
        if (hashTable[i] != NULL)
            cout << hashTable[i]->nameOfFriendship << ", ";
        cout << endl;
    }
}
