#ifndef DECK_H_
#define DECK_H_
#include "card.h"
#include <cstdlib>
#include <vector>
class Deck{
	std::vector<Card *> cards;
	int deckSize;
	public:
		Deck();
		Deck(std::vector<Card *> cards, bool testingOn);
		Deck& operator=(const Deck &other);
		~Deck();
		Card *Top();
};
#endif
