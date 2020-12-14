#include <iostream>
#include "Engine.h"

using namespace std;
void BuyStage(),
	 ShowMoney(),
	 ItemStage(),
	 AddItem();

Ballence money;
Item items[5];
bool ext = 0;

void Menu()
{
	cout << endl;
	cout << "====|| Menu ||====\n";
	cout << endl;
	cout << "1. Buy Weapon\n";
	cout << "2. Check Ballance\n";
	cout << "3. Exit Store\n";
	cout << endl;
	int choice;

	cout << "Choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		BuyStage();
		break;
	case 2:
		ShowMoney();
		break;
	case 3:
		if (money.GetBallence() != 75)
		{
			ItemStage();
		}
		else if (money.GetBallence() == 75)
		{
			cout << "Please buy an Item first";
		}
		break;
	}
}

void AddItem(Item item)
{
	for (int i = 0; i < 5; i++)
	{
		if (items[i].GetName() == "No Item")
		{
			items[i] = item;
			return;
		}
	}
}

void ShowMoney()
{
	cout << endl;
	cout << "====|| Ballance: $" << money.GetBallence() << " ||====\n";
	cout << endl;
	return;
};

void BuyStage()
{

	cout << endl;
	cout << "====|| Store ||====\n";
	cout << endl;
	cout << "1.$30-Sword Dur-8\n";
	cout << "2.$25-Spear Dur-7\n";
	cout << "3.$10-Dagger x5\n";
	cout << "4.$15-Funny Hat Dur-10\n";
	cout << "5.$20-Health Potion x5\n";
	cout << "6.$20-Attack Potion x5\n";
	cout << "7.$23-Mace Dur-6\n";
	cout << "8.$27-Axe Dur-7\n";
	cout << "9.$30 Bow x10 arrows\n";
	cout << "0.Exit\n";
	cout << endl;
	bool done = 0;
	int slot = 0;

	do
	{
		char choice;

		cout << "Choice: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			if (money.GetBallence() >= 30)
			{
				slot += 1;
				money.ChangeBallence(-30);
				AddItem(Item("Sword", 8));
				cout << "Sword, Purchased in slot "<< slot << endl;
				cout << endl;
			}
			else
			{
				cout << "not enough money" << endl;
				cout << endl;
			}
			break;
		case '2':
			if (money.GetBallence() >= 25)
			{
				slot += 1;
				money.ChangeBallence(-25);
				AddItem(Item("Spear", 7));
				cout << "Spear, Purchased in slot " << slot << endl;
				cout << endl;
			}
			else
			{
				cout << "not enough money" << endl;
				cout << endl;
			}
			break;
		case '3':
			if (money.GetBallence() >= 10)
			{
				slot += 1;
				money.ChangeBallence(-10);
				AddItem(Item("Dagger", 5));
				cout << "Dagger, Purchased in slot "<< slot << endl;
				cout << endl;
			}
			else
			{
				cout << "not enough money" << endl;
				cout << endl;
			}
			break;
		case '4':
			if (money.GetBallence() >= 15)
			{
				slot += 1;
				money.ChangeBallence(-15);
				AddItem(Item("Funny Hat", 10));
				cout << "Funny Hat, Purchased in slot " << slot << endl;
				cout << endl;
			}
			else
			{
				cout << "not enough money" << endl;
				cout << endl;
			}
			break;
		case '5':
			if (money.GetBallence() >= 20)
			{
				slot += 1;
				money.ChangeBallence(-20);
				AddItem(Item("Health Potion", 5));
				cout << "Health Potion, Purchased in slot "<< slot << endl;
				cout << endl;
			}
			else
			{
				cout << "not enough money" << endl;
				cout << endl;
			}
			break;
		case '6':
			if (money.GetBallence() >= 20)
			{
				slot += 1;
				money.ChangeBallence(-20);
				AddItem(Item("Attack Potion", 5));
				cout << "Attack Potion, Purchased in slot " << slot << endl;
				cout << endl;
			}
			else
			{
				cout << "not enough money" << endl;
				cout << endl;
			}
			break;
		case '7':
			if (money.GetBallence() >= 23)
			{
				slot += 1;
				money.ChangeBallence(-23);
				AddItem(Item("Mace", 6));
				cout << "Mace, Purchased in slot " << slot << endl;
				cout << endl;
			}
			else
			{
				cout << "not enough money" << endl;
				cout << endl;
			}
			break;
		case '8':
			if (money.GetBallence() >= 27)
			{
				slot += 1;
				money.ChangeBallence(-27);
				AddItem(Item("Axe", 7));
				cout << "Axe, Purchased in slot " << slot << endl;
				cout << endl;
			}
			else
			{
				cout << "not enough money" << endl;
				cout << endl;
			}
			break;
		case '9':
			if (money.GetBallence() >= 30)
			{
				slot += 1;
				money.ChangeBallence(-30);
				AddItem(Item("Bow", 10));
				cout << "Bow, Purchased in slot " << slot << endl;
				cout << endl;
			}
			else
			{
				cout << "not enough money" << endl;
				cout << endl;
			}
			break;
		case '0':
			cout << "Exiting Shop\n";
			cout << endl;
			done = 1;
			break;
		}
	} while (done == false);
	return;
}

void ItemStage()
{
	cout << endl;
	cout << "====|| Test your items (# 1-5) ||====\n";
	cout << endl;
	cout << "====|| # 1-5 to eqip.\n";
	cout << "====|| E to use item.\n";
	cout << "====|| Q to quit\n";
	cout << endl;
	bool done = 0;
	int Equipped = 0;
	do
	{
		char choice;
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			cout << items[0].GetName() << " Equipped\n";
			cout << endl;
			Equipped = 0;
			break;
		}
		case '2':
		{
			cout << items[1].GetName() << " Equipped\n";
			cout << endl;
			Equipped = 1;
			break;
		}
		case '3':
		{
			cout << items[2].GetName() << " Equipped\n";
			cout << endl;
			Equipped = 2;
			break;
		}
		case '4':
		{
			cout << items[3].GetName() << " Equipped\n";
			cout << endl;
			Equipped = 3;
			break;
		}
		case '5':
		{
			cout << items[4].GetName() << " Equipped\n";
			cout << endl;
			Equipped = 4;
			break;
		}
		case 'e':
		{
			if (items[Equipped].GetDurrability() > 0)
			{
				items[Equipped].ReduceDurrability();
				if (items[Equipped].GetName() == "Sword")
				{
					cout << "you swing your sword" << endl;
				
				}
				else if (items[Equipped].GetName() == "Spear")
				{
					cout << "you thrust your spear" << endl;
				}
				else if (items[Equipped].GetName() == "Dagger")
				{
					cout << "you throw your dagger" << endl;
				}
				else if (items[Equipped].GetName() == "Funny Hat")
				{
					cout << "you look stylish" << endl;
				}
				else if (items[Equipped].GetName() == "Health Potion")
				{
					cout << "you drink your potion" << endl;
				}
				else if (items[Equipped].GetName() == "Attack Potion")
				{
					cout << "you drink your potion" << endl;
				}
				else if (items[Equipped].GetName() == "Mace")
				{
					cout << "you swing your mace" << endl;
				}
				else if (items[Equipped].GetName() == "Axe")
				{
					cout << "you swing with your axe" << endl;
				}
				else if (items[Equipped].GetName() == "Bow")
				{
					cout << "you fire an arrow" << endl;
				}
				cout << "(" << items[Equipped].GetDurrability() << ")" << endl;
			}
			else if (items[Equipped].GetDurrability() == 0)
			{
				if (items[Equipped].GetName() == "Sword")
				{
					cout << "your sword is broken" << endl;
					cout << endl;
				}
				else if (items[Equipped].GetName() == "Spear")
				{
					cout << "your spear is broken" << endl;
					cout << endl;
				}
				else if (items[Equipped].GetName() == "Dagger")
				{
					cout << "you are out of daggers" << endl;
					cout << endl;
				}
				else if (items[Equipped].GetName() == "Funny Hat")
				{
					cout << "your hat is no longer funny" << endl;
					cout << endl;
				}
				else if (items[Equipped].GetName() == "Health Potion")
				{
					cout << "you are out of health potions" << endl;
					cout << endl;
				}
				else if (items[Equipped].GetName() == "Attack Potion")
				{
					cout << "you are out of attack potions" << endl;
					cout << endl;
				}
				else if (items[Equipped].GetName() == "Mace")
				{
					cout << "your mace broke" << endl;
					cout << endl;
				}
				else if (items[Equipped].GetName() == "Axe")
				{
					cout << "your axe is brokken" << endl;
					cout << endl;
				}
				else if (items[Equipped].GetName() == "Bow")
				{
					cout << "you are out of arrows" << endl;
					cout << endl;
				}
			}
			break;
		}
		case 'q':
		{
			done = true;
			ext = true;
			break;
		}
		case 'Q':
		{
			done = true;
			ext = true;
			break;
		}
		}
	} while (done == false);
	return;
}

int main()
{
	do {
		Menu();
	} while (ext != true);
}