
#ifndef CARD_H
#define CARD_H

#include <string>



enum Rank {A, two, three, four, five, six, seven, eight, nine, ten, J, Q, K};
enum Suit {clubs, diamonds, hearts, spades };

class Card
{
private:
	Rank rank;
	Suit suit;
	
	void setRank(Rank r)
	{
		rank = r;
	}

	void setSuit(Suit s)
	{
		suit = s;
	}

public:
	Card();
	Card(Rank r, Suit s);

	Rank getRank();
	Suit getSuite();

	bool isEqual(Card other);

	std::string toString();
};


#endif // !CARD_H

