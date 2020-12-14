#include "Card.h"
#include <string>

Card::Card()
{
	rank = A;
	suit = spades;
}

Card::Card(Rank r, Suit s)
{
	rank = r;
	suit = s;
}

Rank Card::getRank()
{
	return rank;
}

Suit Card::getSuite()
{
	return suit;
}

bool Card::isEqual(Card other)
{
	return suit == other.suit && rank == other.rank;
}

std::string Card::toString()
{
	std::string out = "";
	switch (rank)
	{
	case A:
		out += "A of ";
		break;
	 case two:
		 out += "2 of ";
		 break;
	 case three:
		 out += "3 of ";
		 break;
	 case four:
		 out += "4 of ";
		 break;
	 case five:
		 out += "5 of ";
		 break;
	 case six:
		 out += "6 of ";
		 break;
	 case seven:
		 out += "7 of ";
		 break;
	 case eight:
		 out += "8 of ";
		 break;
	 case nine:
		 out += "9 of ";
		 break;
	 case ten:
		 out += "10 of ";
		 break;
	 case J:
		 out += "J of ";
		 break;
	 case Q:
		 out += "Q of ";
		 break;
	 case K:
		 out += "K of ";
		 break;
	}

	switch (suit)
	{
	case clubs:
		out += "clubs";
		break;
	case diamonds:
		out += "diamonds";
		break;
	case hearts:
		out += "hearts";
		break;
	case spades:
		out += "spades";
		break;
	}

	return out;
}