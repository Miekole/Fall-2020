#pragma once
#include <iostream>
using namespace std;

class Item
{
private:
	string name;
	int durability;

public:
	Item()
	{
		name = "No Item";
		durability = 0;
	}
	Item(string weaponName, int durability)
	{
		this->name = weaponName;
		this->durability = durability;
	}
	int GetDurrability()
	{
		return durability;
	}
	void SetDurrability(int d)
	{
		durability = d;
	}
	void ReduceDurrability()
	{
		durability -= 1;
	}
	string GetName()
	{
		return name;
	}
	void SetName(string wName)
	{
		name = wName;
	}
};

class Ballence
{
private:
	int playerMoney = 75;
public:
	int GetBallence()
	{
		return playerMoney;
	}
	void ChangeBallence(int amount)
	{
		playerMoney += amount;
	}
};

class Engine
{
private:
	Ballence money;
	string items[5];
public:
	int Run();
};
