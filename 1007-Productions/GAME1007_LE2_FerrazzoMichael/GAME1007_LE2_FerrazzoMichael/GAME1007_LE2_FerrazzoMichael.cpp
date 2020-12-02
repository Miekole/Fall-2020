#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int number = rand() % 100 + 1;
int order = rand() % 2;
int guess1, guess2, turn;

string nameOne, nameTwo;

void ending()
{
	cout << "this is the end of the game, would you like to play agian?\n";
	cout << "1. Yes\n";
	cout << "2. No, Exit\n";
	cin >> turn;
	if (turn == 1)
	{
		return;
	}
	else
	{
		return;
	}
}

void oneplayer()
{
	cout << nameOne << "'s guess: ";
	cin >> guess1;
	if (guess1 >= 1 && guess1 <= 100)
	{
		if (guess1 == number)
		{
			cout << endl;
			cout << "========================\n";
			cout << nameOne << ", you guessed it first!\n";
			return;
		}
		else if (guess1 > number)
		{
			cout << "Your guess was too high, " << nameOne << endl;
		}
		else if (guess1 < number)
		{
			cout << "Your guess was too low, " << nameOne << endl;
		}


		int guess2 = rand() % 100 + 1;
		cout << "COM guess: " << guess2 << endl;
		if (guess2 == number)
		{
			cout << endl;
			cout << "========================\n";
			cout << "COM guessed it first!\n";
			guess1 = guess2;
			return;
		}
		else if (guess2 != number)
		{
			oneplayer();
		}
	}
	else
	{
		cout << "not a valid number\n";
		oneplayer();
	}
}

void twoplayer()
{
	cout << nameOne << "'s guess: ";
	cin >> guess1;
	if (guess1 >= 1 && guess1 <= 100)
	{
		if (guess1 == number)
		{
			cout << endl;
			cout << "========================\n";
			cout << nameOne << ", you guessed it first!\n";
			return;
		}
		else if (guess1 > number)
		{
			cout << "Your guess was too high, " << nameOne << endl;
		}
		else if (guess1 < number)
		{
			cout << "Your guess was too low, " << nameOne << endl;
		}
	}
	else
	{
		cout << "not a valid number";
		twoplayer();
	}
	cout << nameTwo << "'s guess: ";
	cin >> guess2;
	if (guess2 >= 1 && guess2 <= 100)
	{
		if (guess2 == number)
		{
			cout << endl;
			cout << "========================\n";
			cout << nameTwo << ", you guessed it first!\n";
			guess1 = guess2;
			return;
		}
		else if (guess2 > number)
		{
			cout << "Your guess was too high, " << nameTwo << endl;
		}
		else if (guess2 < number)
		{
			cout << "Your guess was too low, " << nameTwo << endl;
		}
		twoplayer();
	}
	else
	{
		cout << "not a valid number\n";
		twoplayer();
	}
}

void noPlayers()
{
	int guess1 = rand() % 100 + 1;
	cout << "COM 1 guess: " << guess1 << endl;
	if (guess1 == number)
	{
		cout << endl;
		cout << "========================\n";
		cout << "COM 1 guessed it first!\n";
		return;
	}
	int guess2 = rand() % 100 + 1;
	cout << "COM 2 guess: " << guess2 << endl;
	if (guess2 == number)
	{
		cout << endl;
		cout << "========================\n";
		cout << "COM 2 guessed it first!\n";
		guess1 = guess2;
		return;
	}
	else if (guess2 != number)
	{
		noPlayers();
	}
}


int main()
{
	int choice;

	cout << "\n";
	cout << "\n";
	cout << "-----=========@@@@@@@@@@@=========-----\n";	//TITLE
	cout << "            THE NUMBER GAME               \n";
	cout << "-----=========@@@@@@@@@@@=========-----\n";
	cout << "\n";

	cout << "How would you like to play?\n";				// GAME SELECTION
	cout << "\n";
	cout << "1. Player VS COM\n";
	cout << "2. Player VS Player\n";
	cout << "3. COM VS COM\n";
	cout << "4. Exit\n";
	cout << " \n";
	cout << "Enter a Number: ";
	cin >> choice;
	cin.ignore();

	if (choice >= 1 && choice <= 3)
	{
		srand((unsigned int)time(NULL));

		switch (choice)
		{
		case 1:								// 1 player
			cout << "Enter your name: ";
			getline(cin, nameOne);

			cout << "===============================================================\n";		//1 player title
			cout << nameOne << ", you have chosen to play THE NUMBER GAME!\n";
			cout << "===============================================================\n";
			oneplayer();

			cout << "this is the end of the game, would you like to play agian?\n";		// ending
			cout << "1. Yes\n";
			cout << "2. No, Exit\n";
			cout << "========================\n";
			cout << nameOne << ": ";
			cin >> turn;
			if (turn >= 1 && turn <= 2)
			{
				if (turn == 1)
				{
					main();
				}
				else if (turn == 2)
				{
					return 0;
				}
			}
			else
			{
				cout << "Not a valid number";
			}

	
			break;

		case 2:						// 2 players
			cout << "Player 1, enter your name: ";
			getline(cin, nameOne);
			cout << "Player 2, enter your name: ";
			getline(cin, nameTwo);
			cout << " \n";
			cout << "===============================================================\n";				// titlescreen 2 players
			cout << nameOne << " & " << nameTwo << " you have chosen to play\n";
			cout << "===============================================================\n";
			twoplayer();

			cout << "this is the end of the game, would you like to play agian?\n";		// ending
			cout << "1. Yes\n";
			cout << "2. No, Exit\n";
			cout << "========================\n";
			cout << nameOne << ": ";
			cin >> turn;
			if (turn >= 1 && turn <= 2)
			{
				if (turn == 1)
				{
					main();
				}
				else if (turn == 2)
				{
					return 0;
				}
			}
			else
			{
				cout << "Not a valid number";
			}

			break;
		case 3:							// no players
			cout << "No players selected";
			cout << "\n";
			noPlayers();

			cout << "this is the end of the game, would you like to play agian?\n";		// ending
			cout << "1. Yes\n";
			cout << "2. No, Exit\n";
			cout << "========================\n";
			cout << nameOne << ": ";
			cin >> turn;
			if (turn >= 1 && turn <= 2)
			{
				if (turn == 1)
				{
					main();
				}
				else if (turn == 2)
				{
					return 0;
				}
			}
			else
			{
				cout << "Not a valid number";
			}
			break;
		}
	}
	return 0;
}


