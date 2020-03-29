#include <iostream>
#include <string>
#include "AccountList.cpp"
using namespace std;


class Customer {
public:
	Customer(int id, string fn, string ls);
	Customer();
	~Customer();
	Customer(const Customer &copied);
	void operator=(const Customer &rhs);
	int nameCompare(Customer c2);
	int custId;
	string firstName;
	string lastName;
	AccountList* al;
};