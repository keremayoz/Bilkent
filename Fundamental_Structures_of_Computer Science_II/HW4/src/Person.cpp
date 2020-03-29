/**
 * Title: Balanced Search Trees and Hashing
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 4
 * Description: Implemented functions of the Person.h
 * It stores the name and the linked-list of friends
 */

#include <stdio.h>
#include "Person.h"
using namespace std;

//Constructor that initializes the name and friends as NULL
Person::Person() {
    name = "";
    friends = NULL;
}

//Constuctor that initalizes the name with given string
Person::Person(string newName) {
    name = newName;
    friends = NULL;
}

//Destructor that deletes the Person object
Person::~Person() {
    if (friends != NULL) {
        //Deleting all the nodes in friends list
        ListNode *cur = friends;
        while (cur != NULL) {
            ListNode *temp = cur;
            cur = cur->next;
            temp->next = NULL;
            temp->pf = NULL;
            delete temp;
        }
        friends = NULL;
    }
}

//Copy Constructor for copying the person(deep-copying except the Person objects in the friends list-because it's not needed-)
Person::Person(const Person &copied) {
    //Copy the name and initialize the friends as NULL
    name = copied.name;
    friends = NULL;
    
    //Deep-copying
    ListNode *lastly = NULL, *cur = copied.friends;
    while(cur != NULL) {
        ListNode *temp = new ListNode;
        
        //Point the person, not copying
        temp -> pf = cur -> pf;
        
        //Connecting the head of the new list
        if (friends == NULL)
            friends = temp;
        //Connecting the nodes
        else
            lastly -> next = temp;
        lastly = temp;
        //Traverse
        cur = cur -> next;
    }
    //Assigning the last element's next as NULL
    if (friends != NULL)
        lastly -> next = NULL;
}

//Inserts the friend to the person's friends list(at the beginning)
void Person::insertFriend(Person *inserted) {
    if (inserted->name != name) {
        ListNode *temp = friends;
        friends = new ListNode;
        friends->pf = inserted;
        friends->next = temp;
    }
}

//Deletes the given friend from the friends list of person
void Person::deleteFriend(Person *deleted) {
    ListNode *cur = friends;
    ListNode *prev = NULL;
    
    //If it is the first element in the list
    if (friends->pf->name == deleted->name) {
        friends = friends->next;
        cur->next = NULL;
        cur->pf = NULL;
        delete cur;
        return;
    }
    
    //Else
    while (cur != NULL) {
        if (cur->pf->name == deleted->name) {
            prev->next = cur->next;
            cur->next = NULL;
            cur->pf = NULL;
            delete cur;
            return;
        }
        //Traverse
        prev = cur;
        cur = cur->next;
    }
}

//Displays all the friends of person
void Person::displayFriends() {
    ListNode *cur = friends;
    while (cur != NULL) {
        cout << cur->pf->name << ", ";
        cur = cur->next;
    }
    cout << endl;
}
