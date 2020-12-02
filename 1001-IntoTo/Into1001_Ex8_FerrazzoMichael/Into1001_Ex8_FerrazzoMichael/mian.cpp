
#include <string>
#include <iostream>
#include <algorithm>
#include <time.h>
#include "Card.h"
#include "Deck.h"

int compare(Card c1, Card c2)
{
	if (c1.getRank() > c2.getRank()){
		return 1;
	}
	else if (c1.getRank() < c2.getRank()) {
		return -1;
	}
	else {
		return 0;
	}
}

int main()
{
	srand(time(NULL));
	Deck deck;
	int playerScore = 0;

	std::cout << "Press enter to draw a card\n";

	for (int i = 0; i < 3; i++)
	{
		std::cin.get();

		Card c1 = deck.getNextCard();
		std::cout << "player card: " + c1.toString() << std::endl;

		Card c2 = deck.getNextCard();
		std::cout << "CPU card: " + c2.toString() << std::endl;

		playerScore += compare(c1, c2);
	}

	if (playerScore > 0)
	{
		std::cout << "\n";
		std::cout << "player wins the game!\n";
	}
	else if (playerScore == 0)
	{
		std::cout << "\n";
		std::cout << "Tie\n";
	}
	else
	{
		std::cout << "\n";
		std::cout << "you lose \n";
	}

	/*Card c1 = deck.getCard(1);
	
	for (int i = 0; i < 52; i++)
	{
		Card c = deck.getCard(i);
		std::cout << c.toString() << std::endl;
	}
	
	Card c2 = deck.getNextCard();

	if (compare(c1, c2) > 0)
	{
		std::cout << c1.toString() + " is greater than " + c2.toString() << std::endl;
	}

	else if (compare(c1, c2) < 0)
	{
		std::cout << c2.toString() + " is greater than " + c1.toString() << std::endl;
	}

	else
	{
		std::cout << c1.toString() + " and " + c2.toString() + " are equal" << std::endl;
	}*/

	return 0;
}