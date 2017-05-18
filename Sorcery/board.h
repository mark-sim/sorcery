#ifndef BOARD_H
#define BOARD_H
#include "graveyard.h"
#include <vector>

class Subject;
class Player;
class Card;
class Game;

class Board {
	const int MAX_MINION = 5;
	int minionCount = 0;
	Card *ritual = nullptr;
	std::vector<Card *> listOfMinion;
	Subject *subject;
	Graveyard graveyard;
	public:
	Board();
	~Board();
	Card *getRitual();
	Card *getMinion(int i);
	void playMinion(Card *card, Game *g);	
	void playRitual(Card *ritual);
	int getMinionCount();
	void checkDead(Game *game);
	void setMinion(Card *card, int i);
	void removeFromBoard(int i);
	Graveyard *getGraveyard();
	void sendToGraveyard(int index);
	Subject *getSubject();
	void displayA(Player *player);
	void displayB(Player *player);
	

};


#endif
