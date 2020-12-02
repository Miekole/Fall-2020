/*
			Michael Ferrazzo - 101321516
						lab 2
					Sep 27, 2020
*/
#include <iostream>
using namespace std;

int main()
{
	int Worked, rate;
	float pay(2);

	cout << "===================================\n";	// Title
	cout << "       Work Pay Calculator\n";
	cout << "===================================\n";
	cout << "\n";

	cout << ("Enter hours worked: ");					// gather info
	cin >> Worked;
	cout << ("Enter hourly rate: ");
	cin >> rate;
	cout << "\n";

	if (Worked <= 40)									// no overtime
	{
		float pay = (Worked * rate);
		cout << "Regular Pay: " << pay << endl;
		cout << "Overtime Pay: " << "0" << endl;
		cout << "Total Pay: " << pay << endl;
		cout << "Tax: " << (pay * 0.18) << endl;
	}
	else                                                // overtime
	{
		float pay = ((Worked - 40) * rate * 1.5 + 40 * rate);

		cout << "Regular Pay: " << (40 * rate) << endl;
		cout << "Overtime Pay: " << (pay - (40 * rate)) << endl;
		cout << "Total Pay: " << pay << endl;
		cout << "Tax: " << (pay * 0.18) << endl;
	}
	/*
	cout << "Regular Pay: " << ()
	cout << "Overtime Pay: " <<
	cout << "Total Pay: " <<
	cout << "Tax: " <<
	*/
	return 0;
}