/**
 * Title: Balanced Search Trees and Hashing
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 4
 * Description: Header file for Friendship class.
 */

#ifndef Friendship_h
#define Friendship_h
#include "Person.h"

class Friendship {
public:
    
    //Constructors and destructor
    Friendship();
    ~Friendship();
    Friendship(Person *first, Person *second);
    Friendship(const Friendship &copied);
    
    //Variables
    string nameOfFriendship;
    Person::ListNode *first;
    Person::ListNode *second;
};

#endif /* Friendship_h */
