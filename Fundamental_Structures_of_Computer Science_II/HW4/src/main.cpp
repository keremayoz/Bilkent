/**
 * Title: Balanced Search Trees and Hashing
 * Author: Kerem Ayöz
 * ID: 21501569
 * Section: 1
 * Assignment: 4
 * Description: main.cpp 
 */

#include <iostream>
#include <fstream>
#include "Person.h"
#include "PersonHashing.h"
#include "Friendship.h"
#include "FriendshipHashing.h"
using namespace std;

PersonHashing hashPerson;
FriendshipHashing hashFriendship;

void commandP(string name) {
    Person *newPerson = new Person(name);
    hashPerson.insert(newPerson);
}

void commandF(string name1, string name2) {
    Person *p1 = hashPerson.retrieve(name1);
    Person *p2 = hashPerson.retrieve(name2);
    p1->insertFriend(p2);
    p2->insertFriend(p1);

    Friendship *newFriendship = (p1->name < p2->name) ?  (new Friendship(p1,p2)) : (new Friendship(p2,p1));
    hashFriendship.insert(newFriendship);
}

void commandU(string name1, string name2) {
    Person *p1 = hashPerson.retrieve(name1);
    Person *p2 = hashPerson.retrieve(name2);

    p1->deleteFriend(p2);
    p2->deleteFriend(p1);
    string deletedName = "";
    
    deletedName = (p1->name < p2->name) ? (p1->name + p2->name) : (p2->name + p1->name);
   
    for (int i = 0; i < 71; i++)
        if (hashFriendship.hashTable[i] != NULL && hashFriendship.hashTable[i]->nameOfFriendship == deletedName) {
            delete hashFriendship.hashTable[i];
            hashFriendship.hashTable[i] = NULL;
            break;
        }
    
}

void commandL(string name) {
    Person *p = hashPerson.retrieve(name);
    Person::ListNode *cur = p->friends;
    while (cur != NULL) {
        cout << cur->pf->name << " ";
        cur = cur->next;
    }
    cout << endl;
}

void commandQ(string name1, string name2) {
    Person *p1 = hashPerson.retrieve(name1);
    Person *p2 = hashPerson.retrieve(name2);
    string searchedName = "" + p1->name + p2->name + "";

    for (int i = 0; i < 71; i++)
        if (hashFriendship.hashTable[i] != NULL && hashFriendship.hashTable[i]->nameOfFriendship == searchedName) {
            cout << "Yes" << endl;
            return;
        }
    cout << "No" << endl;
}

void commandX() {
    hashPerson.clearAll();
}

int main() {
    string total = "";
    ifstream in("input.txt");
    if(!in) {
        cout << "Cannot open input file.\n";
        return 1;
    }
    char str[255];
    while(in) {
        in.getline(str, 255);
        if(in) {
            if (str[0] == 'P') {
                string name = "";
                int i = 2;
                while (str[i])
                    name += str[i++];
                commandP(name);
            }
            else if (str[0] == 'F') {
                string name1 = "";
                string name2 = "";
                int i = 2;
                while (str[i] && str[i] != ' ')
                    name1 += str[i++];
                i++;
                while (str[i])
                    name2 += str[i++];
                commandF(name1,name2);
            }
            else if (str[0] == 'L') {
                string name = "";
                int i = 2;
                while (str[i])
                    name += str[i++];
                commandL(name);
            }
            else if (str[0] == 'U') {
                string name1 = "";
                string name2 = "";
                int i = 2;
                while (str[i] && str[i] != ' ')
                    name1 += str[i++];
                i++;
                while (str[i])
                    name2 += str[i++];
                commandU(name1,name2);
            }
            else if( str[0] == 'Q') {
                string name1 = "";
                string name2 = "";
                int i = 2;
                while (str[i] && str[i] != ' ')
                    name1 += str[i++];
                i++;
                while (str[i])
                    name2 += str[i++];
                commandQ(name1,name2);
            }
            else  //X case
                commandX();
        }
    }
    in.close();
    return 0;
}
