#include <iostream>
#include <string>
#include "BankingSystem.h"
using namespace std;


int main() {

	BankingSystem B;
	B.addCustomer(1234, "Cigdem", "Gunduz Demir");
	B.addCustomer(4567, "Ercument", "Cicek");
	B.addCustomer(891234, "Serhan", "Yilmaz"); 
	B.addCustomer(891234, "Can Fahrettin", "Koyuncu");
	B.addCustomer(5678, "Necmi", "Acarsoy"); 
	B.addCustomer(8901, "Cigdem", "Gunduz");
	B.addCustomer(9876, "Cigdem", "Gunduz");
	B.deleteCustomer(5678);
	B.deleteCustomer(1267);

	cout << endl << endl;

	int X, Y, Z, Q;
	B.addAccount(4567, 100.00);
	X = B.addAccount(1234, 200.00); 
	Y = B.addAccount(4567, 300.00); 
	B.addAccount(4567, 1000.00);
	Z = B.addAccount(8901, 100.00); 
	B.addAccount(5678, 100.00); 
	B.addAccount(1234, 500.00);
	
	B.deleteAccount(X); 
	B.deleteAccount(Y);
	B.deleteAccount(Z);
	B.addAccount(891234, 500.00);
	B.addAccount(4567, 200.00);
	B.addAccount(1234, 1500.00);
	Q = B.addAccount(1234, 300.00);
	B.deleteAccount(Q);
	
	cout << endl << endl;

	B.showAllAccounts(); 
	cout << endl << endl;
	B.showAllCustomers();
	cout << endl << endl;
	B.showCustomer(8901);
	B.showCustomer(4567); 
	B.showCustomer(1212);

	//system("pause");

	return 0;
}