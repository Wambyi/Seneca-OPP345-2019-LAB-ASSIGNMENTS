//============================================================================
// Name        : Cpp_Assignment5_FriendClass.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Lab exercise for friend class
//============================================================================

#include <iostream>
using namespace std;


class HUSBAND {
	friend class WIFE;
private:
	string Husband_fname;
	string Husband_lname;
	int Husband_income;
public:
	HUSBAND(string f1, string l1, int inc){
		Husband_fname = f1;
		Husband_lname = l1;
		Husband_income = inc;
	}
	HUSBAND(){
		//	Default initializations of data members
		Husband_fname = "unknown";
		Husband_lname = "unknown";
		Husband_income = 0;
	}
	int getIncome();
};

int HUSBAND::getIncome(){
	return Husband_income;
}

class WIFE{
private:
	string Wife_fname;
	string Wife_lname;
	int Wife_income;
	int tax_rate;
public:
	WIFE(string f2, string l2, int inc, int tr) {
		Wife_fname = f2;
		Wife_lname = l2;
		Wife_income = inc;
		tax_rate = tr;
	}
	WIFE(){
		//Default initializations of private data members;
		Wife_fname = "unknown";
		Wife_lname = "unknown";
		Wife_income = 0;
		tax_rate = 0;
	}
	float calcTax(HUSBAND &f);
	float getTaxRate();
	int getIncome();

};

float WIFE::calcTax(HUSBAND &f){
	return (f.Husband_income+Wife_income)*tax_rate;
}

float WIFE::getTaxRate(){
	return tax_rate;
}

int WIFE::getIncome(){
	return Wife_income;
}


int main()
{
	HUSBAND obj1("Albert","John",55026);
	WIFE obj2("Mary","Chin",120000,5);

//Task1: Display the tax rate;
	cout<<"Tax rate: "<<obj2.getTaxRate()<<endl;

// Task2: Display income of HUSBAND;
	cout<<"Husband income: "<<obj1.getIncome()<<endl;

// Task3: Display income of WIFE;
	cout<<"Wife income: "<<obj2.getIncome()<<endl;

// Task4: Display total family income;
	cout<<"Total income: "<<(obj1.getIncome() + obj2.getIncome())<<endl;

// Task5: Display total Tax Amount;
	cout<<"Total tax amount: "<<obj2.calcTax(obj1)<<endl;

	system("pause");
	return 0;
}





