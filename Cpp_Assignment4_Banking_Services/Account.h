/*
 * Account.h
 *
 *  Created on: Oct. 7, 2019
 *      Author: gladysdaniel
 */

#include <iostream>
using namespace std;

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

const double withdrawFee = 1.50;
const double interestRate = 0.05;

/********************************ACCOUNT CLASS (BASE)********************************/
class Account{
protected:
	double InitialBalance;
	double currentBalance;

	double totalDepositAmount;
	double totalWithdrawAmount;

public:

	Account(double startBalance){
		InitialBalance = startBalance;
	}

	virtual void Deposit(double);
	virtual void Withdraw(double);
	virtual void getBalance();
};

//deposit
void Account::Deposit(double amount){
	currentBalance  += amount;
	totalDepositAmount +=amount;
}

//withdraw
void Account::Withdraw(double amount){
	if (amount < currentBalance){
		currentBalance  -= amount;
		totalWithdrawAmount -= amount;
	}
	else {
		cout<<"Debit amount exceeded Account balance"<<endl;
	}
}

void Account::getBalance(){
	cout<<"Account Report\n";
	cout<<"-------------------------------\n";
	cout<<"Total deposit value: "<<totalDepositAmount<<"\n";
	cout<<"Total withdraw value: "<<totalWithdrawAmount<<"\n";
	cout<<"Initial Balance: "<<InitialBalance<<"\n";
	cout<<"Current Balance: "<<currentBalance<<"\n";
}

/***********************CHECKING ACCOUNT(DERIVED CLASSS)*************************/
class CheckingAccount: public Account{
public:
	CheckingAccount(double startMoney):Account(startMoney){
		InitialBalance = startMoney;
	}
	void Deposit(double);
	void Withdraw(double);
	void getBalance();
};

void CheckingAccount::Deposit(double amount){
	Account::Deposit(amount);
}

void CheckingAccount::Withdraw(double amount){  //redefined with service charge included
	Account::Withdraw(amount);
}

void CheckingAccount::getBalance(){
	currentBalance -= withdrawFee;
	Account::getBalance();
}


/***********************SAVINGS ACCOUNT(DERIVED CLASSS)*************************/
class SavingsAccount: public Account{
public:
	SavingsAccount(double startMoney):Account(startMoney){
		InitialBalance = startMoney;
	}
	void Deposit(double);
	void Withdraw(double);
	void getBalance();
};

void SavingsAccount::Deposit(double amount){   //redefined
	Account::Deposit(amount);
}

void SavingsAccount::Withdraw(double amount){
	Account::Withdraw(amount);
}

void SavingsAccount::getBalance(){
	currentBalance += interestRate;
	Account::getBalance();
}


#endif /* ACCOUNT_H_ */



