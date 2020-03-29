#include <iostream>
#include <string>
#include "CustomerList.cpp"
using namespace std;

class BankingSystem {
public: 
	BankingSystem();
	~BankingSystem();
	void addCustomer(const int customerId, const string firstName, const string lastName);
	void deleteCustomer(const int customerId);
	int addAccount(const int customerId, const double amount); 
	void deleteAccount(const int accountId);
	void showAllAccounts(); 
	void showAllCustomers();
	void showCustomer(const int customerId);

	//Additional
	bool contains(int id);
	bool contains(string fir, string las);
	int findIndexOf(int id);
	int findAccountIndex(int id, int & cust);
	bool isIdExist(int id);
	CustomerList *c;
	int lastAccountIndex;
};
