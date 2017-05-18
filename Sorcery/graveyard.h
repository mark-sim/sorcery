#ifndef GRAVEYARD_H
#define GRAVEYARD_H

#include <vector>
class Card;

class Graveyard {
	int graveyardSize = 0;
	std::vector<Card *> graveyard;
	public:
	void sort(int i);
	int getGraveyardSize();
	Card *pop();
	Card *top();
	void push(Card *card);
};
#endif
