/**
 * Title: Balanced Search Trees and Hashing
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 4
 * Description: Implemented the functions of the Friendship.h
 */

#include <stdio.h>
#include "Friendship.h"

//Constructor: initializes the pointers as NULL and name as ""
Friendship::Friendship() {
    nameOfFriendship = "";
    first = NULL;
    second = NULL;
}

//Destructor: changes the pointers, no need to delete the Person objects that are pointed
Friendship::~Friendship() {
    first = NULL;
    second = NULL;
}

//Constructor: Initializes the friendship object by using the pointers that are pointing to both friends
Friendship::Friendship(Person *p1, Person *p2) {
    nameOfFriendship = "" + p1->name + p2->name + "";
    
    //Search for the nodes
    Person::ListNode *cur = p2->friends;
    while (cur != NULL && cur->pf->name != p1->name)
        cur = cur->next;
    first = cur;
    
    cur = p1->friends;
    while (cur != NULL && cur->pf->name != p2->name)
        cur = cur->next;
    second = cur;
}

//Copy-constructor for the friendship object
Friendship::Friendship(const Friendship &copied) {
    nameOfFriendship = copied.nameOfFriendship;
    first = copied.first;
    second = copied.second;
}
