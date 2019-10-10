//============================================================================
// Name        : Cpp_Assignment4_Banking_Services.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 4: Banking Services
//============================================================================

#include <iostream>
#include "Account.h"
using namespace std;

//SavingsAccount S(0);
//CheckingAccount C(0);
Account *S = new SavingsAccount(0);
Account *C = new CheckingAccount(0);

void displayMainMenu();
void AccountMenu(Account *account);

int main() {
	int choice;

	do {
		displayMainMenu();
		cout<<"Please enter the operation you would like to perform: ";
		cin>>choice;

		switch (choice){
		case 1:
			cout<<"Savings Account";
			AccountMenu(S);
			break;
		case 2:
			cout<<"Checking Account";
			AccountMenu(C);
			//AccountMenu -> (C);
			//AccountMenu(C-> &C);
			break;
		case 3:
			cout<<"Thanks for banking today";
			break;
		default:
			cout<<"Invalid choice";
			break;
		}

	} while (choice != 3);
}

//Function to allow user to enter savings or checking account
void displayMainMenu(){
	cout<<'\n';
	cout<<"********************************\n";
	cout<<"Bank Menu \n";
	cout<<"********************************\n";
	cout<<"1)\tSavings \n";
	cout<<"2)\tCheckings \n";
	cout<<"3)\tExit \n";
}

//Function to allow user to deposit or withdraw
void AccountMenu(Account *account){
	int choice;
	double money;
	do {
		cout<<'\n';
		cout<<"********************************\n";
		cout<<"Menu\n";
		cout<<"********************************\n";
		cout<<"1)\tDeposit \n";
		cout<<"2)\tWithdraw \n";
		cout<<"3)\tGet Balance (report)\n";
		cout<<"4)\tBack to Main \n";

		cout<<"Please enter transaction type: ";
		cin>>choice;

		switch (choice){
		case 1:
			cout<<"How much would you like to Deposit? ";
			//double amount;
			cin>>money;
			account->Deposit(money);
			break;
		case 2:
			cout<<"How much would you like to Withdraw? ";
			//double amount;
			cin>>money;
			account->Withdraw(money);
			break;
		case 3:
			account->getBalance();
		default:
			cout<<"Invalid choice";
			break;
		}
	}while (choice != 4);
}


