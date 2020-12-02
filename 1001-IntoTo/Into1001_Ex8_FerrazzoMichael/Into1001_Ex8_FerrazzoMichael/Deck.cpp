#include <string>
#include <algorithm>
#include "Card.h"
#include "Deck.h"

Deck::Deck()
{
	iterator = 0;
	int i = 0;
	for (int r = A; r <= K; r++)
	{
		for (int s = clubs; s <= spades; s++)
		{
			Card c(static_cast<Rank>(r),static_cast<Suit>(s));
			{
				Card c(static_cast<Rank>(r),static_cast<Suit>(s));
				cards[i++] = c;
			}
		}
	}

	std::random_shuffle(std::begin(cards), std::end(cards));

}