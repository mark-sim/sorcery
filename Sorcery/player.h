#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "deck.h"
#include "board.h"
#include "hand.h"

class Player{
	std::string name;
	int hp = 20;
	int mp = 3;
	Hand hand;
	Board board;
	int playerNumber;
	public:
	Player(std::string name, Hand hand, int playerNumber);
	int getPlayerNumber();
	std::string getName();
	void Draw();
	Board *getBoard();
	Hand *getHand();
	int getMP();
	int getHP();
	void changeHP(int change);
	void changeMP(int change, bool testing_on);
};

#endif
