#include <iostream>
using namespace std;
int Num = -1;

void check()
{
	if ((Num % 2) == 0)					//even or odd
		cout << Num << " is even\n";

	else if ((Num % 2) > 0)
		cout << Num << " is odd\n";

	if ((Num % 3) == 0)					//divisible
		cout << Num << " is divisible by 3\n";

	if ((Num % 5) == 0)
		cout << Num << " is divisible by 5\n";

	return;
}

int main()
{
	cin >> Num;
	
	if (cin.fail() == true)
	{
		cout << "Must be a number\n";
		Num = 0;
	}
	//else if ((Num * 1) == 0)		//check if number
	else if (Num >= 0)
	{
		check();
	}
	else
	{
		return 0;
	}
	main();
}