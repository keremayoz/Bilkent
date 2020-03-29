/**
 * Title: Balanced Search Trees and Hashing
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 4
 * Description: Header file for FriendshipHashing class.
 * It hashes the person objects by using quadratic probing. It uses 71 sized table.
 * h(x) = (sum of all ASCI codes of each letter in the name) mod 71
 */

#ifndef FriendshipHashing_h
#define FriendshipHashing_h
#include "Friendship.h"

class FriendshipHashing {
public:
    
    //Constructor and Destructor
    FriendshipHashing();
    ~FriendshipHashing();
    
    //Member Functions
    int calculateHash(string nameOfFriendship);
    void insert(Friendship *inserted);
    void displayHashTable();
    
    //Variables
    Friendship **hashTable;
};

#endif /* FriendshipHashing_h */
