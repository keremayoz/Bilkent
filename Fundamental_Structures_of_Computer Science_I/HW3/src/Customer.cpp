#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

Customer::Customer(int id, string fn, string ls)
{
	custId = id;
	firstName = fn;
	lastName = ls;
	al = new AccountList;
}

Customer::Customer()
{
	custId = 0;
	firstName = "";
	lastName = "";
	al = new AccountList;
}

Customer::~Customer()
{
	delete al;
}

Customer::Customer(const Customer & copied)
{
	if (&copied != this) {
		custId = copied.custId;
		firstName  = copied.firstName;
		lastName = copied.lastName;
		al = new AccountList;
		if (!((copied.al)->isEmpty())) {
			for (int i = 1; i <= copied.al->getLength(); i++) {
				Account ka;
				copied.al->retrieve(i, ka);
				al->sortedInsert(ka);
			}
		}
	}
}

void Customer::operator=(const Customer & rhs)
{
	custId = rhs.custId;
	firstName = rhs.firstName;
	lastName = rhs.lastName;
	delete al;
	al = new AccountList;
	for (int i = 0; i < rhs.al->getLength(); i++) {
		ListItemType temp;
		rhs.al->retrieve(i, temp);
		al->sortedInsert(temp);
	}
}

int Customer::nameCompare(Customer c2)
{
	if (this->lastName > c2.lastName)
		return 1;
	else if (this->lastName == c2.lastName) {
		if (this->firstName > c2.firstName)
			return 1;
		else if (this->firstName == c2.firstName)
			return 0;
		else
			return -1;
	}
	else
		return -1;
}


