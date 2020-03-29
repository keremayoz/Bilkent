/**
 * Title: Balanced Search Trees and Hashing
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 4
 * Description: Person header file to implement person class.
 */


#ifndef Person_h
#define Person_h
#include <iostream>

using namespace std;

class Person {
public:

    //Constructors and destructors
    Person();
    Person(string newName);
    ~Person();
    Person(const Person &copied);
    
    void insertFriend(Person *inserted);
    void deleteFriend(Person *deleted);
    void displayFriends();
    
    //Friend-List Node
    struct ListNode {
        Person *pf;
        ListNode *next;
    };

    //Variables
    string name;
    ListNode *friends;
};



#endif /* Person_h */
