//
//  CustomerList.cpp
//  CustomerList
//
//  Created by Kerem Ayöz on 2.05.2017.
//  Copyright © 2017 Kerem Ayöz. All rights reserved.
//

#include <iostream>
#include "Customer.h"
using namespace std;
typedef Customer ListItemType2;

class CustomerList {
public:
	struct Node {
		ListItemType2 item;
		Node *next;
	};

	Node *head;
	int size;

	CustomerList() : size(0), head(NULL) {
	}

	~CustomerList() {
		while (size > 0) {
			remove(1);
		}

	}

	CustomerList(CustomerList &copied) : size(copied.size) {
		if (copied.head == NULL)
			head = NULL;
		else {
			head = new Node;
			head->item = copied.head->item;
			Node* newPtr = head;
			for (Node* cur = copied.head; cur != NULL; cur = cur->next) {
				newPtr->next = new Node;
				newPtr = newPtr->next;
				newPtr->item = cur->item;
			}
			newPtr->next = NULL;
		}
	}

	bool isEmpty() const {
		return size <= 0;
	}

	int getLength() const {
		return size;
	}

	bool retrieve(int index, ListItemType2& dataItem) const {
		if ((index < 1) || (index > getLength()))
			return false;
		Node *cur = find(index);
		dataItem = cur->item;
		return true;
	}

	ListItemType2 get(int index) {
		Node* cur = find(index);
		return cur->item;
	}

	void addAccountTo(int index, ListItemType newData) {
		Node *cur = head;
		for (int i = 1; i < index; i++) 
			cur = cur->next;
		cur->item.al->sortedInsert(newData);
	}

	void deleteAccountFrom(int index, int accountIndex) {
		Node *cur = head;
		for (int i = 1; i < index; i++)
			cur = cur->next;
		cur->item.al->remove(accountIndex);
	}

	bool remove(int index) {
		if (head == NULL)
			return false;
		if ((index < 1) || (index > size))
			return false;
		size--;
		if (index == 1) {
			Node* temp = head->next;
			delete head;
			head = temp;
		}
		else {
			Node *cur = head, *prev = NULL;
			for (int i = 1; i < index; i++) {
				prev = cur;
				cur = cur->next;
			}
			prev->next = cur->next;
			delete cur;
		}
		return true;
	}

	void sortedInsert(Customer g) {
		Node* new_node = new Node;
		new_node->item = g;
		Node* current;
		/* Special case for the head end */
		if (head == NULL || (head)->item.nameCompare(new_node->item) == 1) {
			new_node->next = head;
			head = new_node;
		}
		else {
			/* Locate the node before the point of insertion */
			current = head;
			while (current->next != NULL && current->next->item.nameCompare(new_node->item) == -1) {
				current = current->next;
			}
			new_node->next = current->next;
			current->next = new_node;
		}
		size++;
	}

private:

	Node *find(int index) const {
		if (head == NULL)
			return NULL;
		if ((index < 1) || (index > getLength()))
			return NULL;
		else {
			Node* cur = head;
			for (int i = 1; i < index; i++)
				cur = cur->next;
			return cur;
		}
	}

};
