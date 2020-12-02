/*
				Lab Test 1
		Michael Ferrazzo - 101321516
			Sat, Oct 3rd, 2020
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string salesName;
	double sale, Total = 0.00, tax = 0.00;
	bool finnished = 0;
	int num = 0;
	/*
	cout << "	Lab Test 1\n";
	cout << " Michael Ferrazzo\n";
	cout << " 101321516\n";
	cout << "========================\n";
	*/
	cout << "=============Commission Calculator============\n";
	cout << " Determin your total paycheck with commission\n";
	cout << "\n";
	cout << "Enter sales person name: ";
	getline(cin, salesName);
	do
	{
		num++;
		cout << "Value of sale " << num << ": $";
		cin >> sale;
		Total = (Total + sale);
		cout << "Enter another sale?\n";
		cout << "0. Yes\n";
		cout << "1. No\n";
		cin >> finnished;
	} while (finnished != 1);
	cout << "\n";
	cout << "===============================================\n";
	cout << salesName <<"'s total sales: $" << fixed << setprecision(2) << Total << endl;
	tax = (0.09 * Total);
	cout << salesName << "'s commission: $" << fixed << setprecision(2) << tax << endl;
	cout << "===============================================\n";
	cout << "\n";
	cout << "	Lab Test 1\n";
	cout << "\n";
	cout << "Michael Ferrazzo\n";
	cout << "\n";
	cout << "Student #: 101321516\n";
	cout << "\n";
	cout << "===============================================\n";
	return 0;
}