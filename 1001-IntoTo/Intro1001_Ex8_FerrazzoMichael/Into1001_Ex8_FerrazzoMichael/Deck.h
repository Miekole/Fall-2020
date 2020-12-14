#ifndef Deck_H
#define CARD_H

#include <string>
#include "Card.h"

class Deck
{
private:
	Card cards[52];
	int iterator;
public:
	Deck();
	Card getNextCard()
	{
		Card c = cards[iterator];
		if (iterator < 52)
		{
			iterator++;
		}

		else
		{
			iterator = 0;
		}

		return c;
	}
	Card getCard(int index)
	{
		Card c;
		if (index < 52 && index >= 0)
		{
			c = cards[index];
		}

		else
			// error, return to default [0]
		{
			c = cards[0];
		}
		return c;
	}
};


#endif // !Deck_H

