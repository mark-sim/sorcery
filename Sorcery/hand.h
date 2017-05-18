#ifndef HAND_H
#define HAND_H

#include "deck.h"
#include "card.h"
#include <vector>

class Hand {
	const int maxSize = 5;
	int handSize = 0;
	std::vector<Card *> cards;
	Deck deck;
	public:
	Hand(Deck deck);
	Hand();
	void display();
	void Draw();
	int getHandSize();
	Card *playHand(int i);
	void sort(int i);
	void discard(int i);
	void addToHand(Card *card);
};

#endif
