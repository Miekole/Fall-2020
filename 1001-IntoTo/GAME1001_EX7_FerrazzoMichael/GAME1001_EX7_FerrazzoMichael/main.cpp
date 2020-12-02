#include <iostream>
using namespace std;

class Cards
{
private:
	enum Suit { diamonds = 1, hearts, spades, clubs };
	enum Face { ace = 1, two, tree, four, five, six, seven, eight, nine, ten, jack, queen, king };

public:
	Suit card1s, card2s;
	Face card1f, card2f;

		int getCard1()
	{
			return card1s;
			return card1f;
	}
		int getCard2()
		{
			return card2s;
			return card2f;
		}

};

void Cards::storeInfo(int c1f, int c1s, int c2f, int c2s)
{
	card1f = c1f;
	card1s = c1s; 
	card2f = c2f;
	card2s = c2s;
}