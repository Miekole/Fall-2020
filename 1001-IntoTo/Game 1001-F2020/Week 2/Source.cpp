/*
		Michael Ferrazzo - 101321516
				week 2 lab 2
*/
#include <iostream>
#include <cstdlib>
using namespace std;
//main method is the entry point of ALL applications
int main()
{
	double var1, var2;
	
	cout << "Please input the first number:" << endl;
	cin >> var1;

	cout << "you enterd: " << var1 << endl;
	cout << "please input the second number:" << endl;
	cin >> var2;

	cout << "Sum: " << var1 + var2 << endl;
	cout << "Product: " << var1 * var2 << endl;
	cout << "average: " << (var1 + var2) / 2 << endl;
	cout << "First #: " << var1 << endl;
	cout << "second #: " << var2 << endl;

	return 0;
}