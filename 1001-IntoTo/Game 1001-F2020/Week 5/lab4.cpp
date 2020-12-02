/*
		Michael Ferrazzo
			101321516
*/
#include <iostream>
using namespace std;

int main()
{
	int choice, months;

	cout << "@++++======-------------======++++@\n";
	cout << "	   Gym Membership\n";
	cout << "@++++======-------------======++++@\n";
	cout << endl;

	cout << "1. Adult(17-65): $14.00/m\n";
	cout << "2. Child(8-16): $9.00/m\n";
	cout << "3. Seinor(65+): $7.00/m\n";
	cout << "Children(8-under): BANNED\n";
	cout << "4. Exit\n";
	cout << endl;

	cout << "Choice: ";
	cin >> choice;

	if (choice >= 1 && choice <= 4)
	{
		cout << "How many months?: ";
		cin >> months;
		cout << endl;
		switch (choice)
		{
		case 1:
			cout << "========================================================\n";
			cout << "Your total for " << months << " months is: $" << months * 14 << endl;
			cout << "Membership: Adult\n";
			cout << "========================================================\n";
			cout << endl;

			break;
		case 2:
			cout << "========================================================\n";
			cout << "Your total for " << months << " months is: $" << months * 9 << endl;
			cout << "Membership: Child\n";
			cout << "========================================================\n";
			cout << endl;

			break;
		case 3:
			cout << "========================================================\n";
			cout << "Your total for " << months << " months is: $" << months * 7 << endl;
			cout << "Membership: Seinor\n";
			cout << "========================================================\n";
			cout << endl;

			break;
		}
	}
	else
	{
		cout << "Invalid Choice";
	}

	return 0;
}