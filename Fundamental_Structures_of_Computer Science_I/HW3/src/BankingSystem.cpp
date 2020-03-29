#include <iostream>
#include <string>
#include "BankingSystem.h"
using namespace std;

BankingSystem::BankingSystem()
{
	c = new CustomerList;
	lastAccountIndex = 0;
}

BankingSystem::~BankingSystem()
{
	delete c;
}

void BankingSystem::addCustomer(const int customerId, const string firstName, const string lastName)
{
	if (contains(customerId)) {
		cout << "Customer " << customerId << " already exists" << endl;
		return;
	}
	if (contains(firstName, lastName)) {
		cout << "Customer " << firstName << " " << lastName << " already exists" << endl;
		return;
	}
	Customer t(customerId,firstName,lastName);
	c->sortedInsert(t);
	cout << "Customer " << customerId << " has been added" << endl;
}

void BankingSystem::deleteCustomer(const int customerId)
{
	if (!contains(customerId)) {
		cout << "Customer " << customerId << " does not exist" << endl;
		return;
	}
	c->remove(findIndexOf(customerId));
	cout << "Customer " << customerId << " has been deleted" << endl;
}

int BankingSystem::addAccount(const int customerId, const double amount)
{
	if (!contains(customerId)) {
		cout << "Customer " << customerId << " does not exist" << endl;
		return -1;
	}
	int uniqueId;
	uniqueId = ++lastAccountIndex;
	Account tt;
	tt.id = uniqueId;
	tt.balance = amount; 
	c->addAccountTo(findIndexOf(customerId), tt);
	cout << "Account " << uniqueId << " added for customer " << customerId << endl;
	return uniqueId;
}

void BankingSystem::deleteAccount(const int accountId)
{
	if (!isIdExist(accountId)) {
		cout << "Customer " << accountId << " does not exist" << endl;
		return;
	}
	int customerDeleted;
	int accountIndex = findAccountIndex(accountId,customerDeleted);
	c->deleteAccountFrom(customerDeleted, accountIndex);
	cout << "Account " << accountId << " deleted" << endl;
}

void BankingSystem::showAllAccounts()
{
	cout << "Account id   Customer id    Customer name   Balance" << endl;
	for (int i = 1; i <= c->getLength(); i++) {
		Customer custs = c->get(i);
		for (int j = 1; j <= custs.al->getLength(); j++) {
			Account accs = custs.al->get(j);
			cout << accs.id << "            " << custs.custId << "           " << custs.firstName << " " << custs.lastName << "  " << accs.balance << endl;
 		}
	}
}

void BankingSystem::showAllCustomers()
{
	cout << "Customer id   Customer name" << endl;
	for (int i = 1; i <= c->getLength(); i++) {
		ListItemType2 temp;
		c->retrieve(i,temp);
		cout << temp.custId << "     " << temp.firstName << " " << temp.lastName << endl;
	}
}

void BankingSystem::showCustomer(const int customerId)
{
	if (!contains(customerId)) {
		cout << "Customer " << customerId << " does not exist" << endl;
		return;
	}
	Customer ss = c->get(findIndexOf(customerId));
	cout << "Customer id: " << ss.custId << "   Customer name: " << ss.firstName << " " << ss.lastName << "    Number of accounts: " << ss.al->getLength() << endl;
	if (ss.al->getLength() != 0) {
		cout << "Accounts of this customer: " << endl;
		cout << "Account id  Balance" << endl;
		for (int i = 1; i <= ss.al->getLength(); i++) {
			Account k = ss.al->get(i);
			cout << k.id << "       " << k.balance << endl;
		}
	}
	cout << endl;
}

//Additional
bool BankingSystem::contains(int id)
{
	for (int i = 1; i <= c->getLength(); i++) {
		ListItemType2 temp;
		c->retrieve(i, temp);
		if (temp.custId == id)
			return true;
	}
	return false;
}

bool BankingSystem::contains(string fir, string las)
{
	for (int i = 1; i <= c->getLength(); i++) {
		ListItemType2 temp;
		c->retrieve(i, temp);
		if (temp.firstName == fir && temp.lastName == las)
			return true;
	}
	return false;
}

int BankingSystem::findIndexOf(int id)
{
	int ind = -1;
	for (int i = 1; i <= c->getLength(); i++) {
		ListItemType2 temp;
		c->retrieve(i, temp);
		if (temp.custId == id)
			ind = i;
	}
	return ind;
}

int BankingSystem::findAccountIndex(int id, int& cust)
{
	int ind = -1; bool loops = true;
	for (int i = 1; i <= c->getLength() && loops; i++) {
		Customer aa = c->get(i);
		for (int j = 1; j <= aa.al->getLength() && loops; j++) {
			Account aaa = aa.al->get(j);
			if (aaa.id == id) {
				ind = j;
				cust = i;
				loops = false;
			}
		}
	}
	return ind;
}

bool BankingSystem::isIdExist(int id) {
	if (id <= lastAccountIndex)
		return true;
	else
		return false;
}
