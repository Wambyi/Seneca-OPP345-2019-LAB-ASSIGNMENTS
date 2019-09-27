//============================================================================
// Name        : Cpp_Assignment1_FunctionTemplates.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 1: Function template
//============================================================================

/****************************************************
 *
 *  FileName:    /net/data/ftp/pub/class/170/ftp/cpp/maxTemplate.cpp
 *  Purpose:     Demonstrate the use of function templates
 *
 ********************************************************/
#include <iostream>
#include <string>
using namespace std;

//Make a template out of the prototype
template <typename T>					//added template format here
T myMax (T one, T two);

int main() {
	//variables to be tested
	int i_one = 3, i_two = 5;
	float f_one = 5.6, f_two = 7.3;
	string s_one = "donkey", s_two = "apple";

	//perform "myMax" on int, float and string in template format
	int i =  myMax<int>(i_one, i_two);
	float f =  myMax<float>(f_one, f_two);
	string s = myMax<string> (s_one, s_two);

	//perform 'myMax' operation and display output
	cout << "The max of " << i_one << " and " << i_two << " is "<< i << endl;
	cout << "The max of " << f_one << " and " << f_two << " is "<< f << endl;
	cout << "The max of " << s_one << " and " << s_two << " is "<< s << endl;

	return 0;
}


//Make a template out of this function. Don't forget the return type.
template <typename T>
T myMax (T one, T two){
	T bigger;

	if (one < two)
		bigger = two;
	else
		bigger = one;

	return bigger;
}
