
/*
				Lab 3
		Michael Ferrazzo - 101321516
			Sat, Oct 3rd, 2020
*/
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	double milk, bread, eggs, cheese;
	double total, tax;
	cout << "Grocery Store Calculator";
	cout << "\n";
	cout << "Milk: $3.99, Bread: $2.49, Eggs: $6.29, Cheese: $7.80";
	cout << "\n";
	cout << "Enter # of Milk: ";
	cin >> milk;
	cout << "Enter # of Bread: ";
	cin >> bread;
	cout << "Enter # of Eggs: ";
	cin >> eggs;
	cout << "Enter # of Cheese";
	cin >> cheese;
	cout << "\n";
	cout << "=============================================\n";
	cout << "Your total before tax is: $" << ((3.99 * milk) + (2.49 * bread) + (6.29 * eggs) + (7.80 * cheese));
	cout << "\n";
	cout << "Your total with tax is: $" << fixed << setprecision(2) << (0.13 * ((3.99 * milk) + (2.49 * bread) + (6.29 * eggs) + (7.80 * cheese))) + (3.99 * milk) + (2.49 * bread) + (6.29 * eggs) + (7.80 * cheese) << endl;
	cout << "\n";
	cout << "Your tax is: $" << fixed << setprecision(2) << 0.13 * ((3.99 * milk) + (2.49 * bread) + (6.29 * eggs) + (7.80 * cheese)) << endl;
	cout << "=============================================\n";

}