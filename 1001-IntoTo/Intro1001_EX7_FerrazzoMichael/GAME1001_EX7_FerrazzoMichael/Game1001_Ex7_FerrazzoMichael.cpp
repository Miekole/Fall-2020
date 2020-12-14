#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;
const int size = 52;


class card
{
private:
	// properties -- variables in private
	enum suit { diamonds = 1, hearts, spades, clubs };
	enum face { ace = 1, two, tree, four, five, six, seven, eight, nine, ten, jack, queen, king };
	suit suit;
	face face;

public:
	// actions -- methods/function
	void setcard()
	{
		face face = face(rand() % 13 + 1);
		suit suit = suit(rand() % 4 + 1);
	}

	int getcard()
	{
		return face;
		return suit;
	}
};

void storevalues(card);

int main()
{
	// define 2 card objects
	card card1, card2;
	card1.setcard();
	card1.getcard();
	return 0;
}

void storevalues(card card1)
{
	card1.getcard();
}
