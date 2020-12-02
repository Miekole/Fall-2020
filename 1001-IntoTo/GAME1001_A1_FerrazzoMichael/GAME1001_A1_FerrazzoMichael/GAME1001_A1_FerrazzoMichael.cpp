#include <iostream>
#include <ctime>
using namespace std;
const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
const int LIZARD = 4;
const int SPOCK = 5;
int userChoice = 0;

int getCpuChoice()		// COMPUTER CHOICE
{
	srand(time(NULL));
	int cpuChoice = rand() % 5 + 1;
	return cpuChoice;
}

void Winner(int userChoice, int cpuChoice)
{
	if (userChoice == ROCK && cpuChoice == PAPER)	//cpu wins
	{
		cout << "Cpu wins, paper beats rock.\n";
	}
	else if (userChoice == SPOCK && cpuChoice == PAPER)
	{
		cout << "Cpu wins, paper disproves spock.\n";
	}
	else if (userChoice == PAPER && cpuChoice == SCISSORS)
	{
		cout << "Cpu wins, scissors cuts paper.\n";
	}
	else if (userChoice == LIZARD && cpuChoice == SCISSORS)
	{
		cout << "Cpu wins, scissors decapitates lizard.\n";
	}
	else if (userChoice == SCISSORS && cpuChoice == ROCK)
	{
		cout << "Cpu wins, rock smashes scissors.\n";
	}
	else if (userChoice == LIZARD && cpuChoice == ROCK)
	{
		cout << "Cpu wins, rock crushes lizard.\n";
	}
	else if (userChoice == PAPER && cpuChoice == LIZARD)
	{
		cout << "cpu wins, lizard eats paper,\n";
	}
	else if (userChoice == SPOCK && cpuChoice == LIZARD)
	{
		cout << "Cpu wins, lizard poisons spock.\n";
	}
	else if (userChoice == SCISSORS && cpuChoice == SPOCK)
	{
		cout << "Cpu wins, spock smashes scissors.\n";
	}
	else if (userChoice == ROCK && cpuChoice == SPOCK)
	{
		cout << "Cpu wins, spock vaporizes rock.\n";
	}
	if (cpuChoice == ROCK && userChoice == PAPER)	// user wins
	{
		cout << "User wins, paper beats rock.\n";
	}
	else if (cpuChoice == SPOCK && userChoice == PAPER)
	{
		cout << "User wins, paper disproves spock.\n";
	}
	else if (cpuChoice == PAPER && userChoice == SCISSORS)
	{
		cout << "User wins, scissors cuts paper.\n";
	}
	else if (cpuChoice == LIZARD && userChoice == SCISSORS)
	{
		cout << "User wins, scissors decapitates lizard.\n";
	}
	else if (cpuChoice == SCISSORS && userChoice == ROCK)
	{
		cout << "User wins, rock smashes scissors.\n";
	}
	else if (cpuChoice == LIZARD && userChoice == ROCK)
	{
		cout << "User wins, rock crushes lizard.\n";
	}
	else if (cpuChoice == PAPER && userChoice == LIZARD)
	{
		cout << "User wins, lizard eats paper,\n";
	}
	else if (cpuChoice == SPOCK && userChoice == LIZARD)
	{
		cout << "User wins, lizard poisons spock.\n";
	}
	else if (cpuChoice == SCISSORS && userChoice == SPOCK)
	{
		cout << "User wins, spock smashes scissors.\n";
	}
	else if (cpuChoice == ROCK && userChoice == SPOCK)
	{
		cout << "User wins, spock vaporizes rock.\n";
	}
}

void displayChoice(int choice)
{
	string result;
		if (choice == ROCK)
		{
			result = "Rock";
		}
		else if (choice == PAPER)
		{
			result = "Paper";
		}
		else if (choice == SCISSORS)
		{
			result = "Scissors";
		}
		else if (choice == LIZARD)
		{
			result = "Lizard";
		}
		else
		{
			result = "spock";
		}
		cout << result << endl;
}

int main()
{
	cout << "	ROCK, PAPER, SCISSORS, LIZARD, SPOCK\n";
	cout << "--------------------------------------------\n";
	cout << "1. Rock\n";
	cout << "2. Paper\n";
	cout << "3. Scissors\n";
	cout << "4. Lizard\n";
	cout << "5. Spock\n";
	cout << "Enter your choice: ";
	cin >> userChoice;

	while (userChoice < 1 || userChoice > 5) // input val
	{
		cout << "number must be from 1 - 5\n";
		cout << "Enter your choice: ";
		cin >> userChoice;
	}

	cout << "You selected: ";		// display user choice
	displayChoice(userChoice);

	int cpuChoice = getCpuChoice();	//display cpu choice
	cout << "Cpu selected: ";
	displayChoice(cpuChoice);

	Winner(userChoice, cpuChoice);
}