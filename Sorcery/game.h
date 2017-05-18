#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "player.h"

class Game{
	Player *AP;
	Player *NAP;
	bool testing_on;

	public:
	Player *getAP();
	Player *getNAP();
	Game(Player *AP, Player *NAP);	

	//Game Commands
	void help();
	void changeTurn();//end turn
	void attack(int AP_board_index, int NAP_board_index);//minionV.minion
	void attack(int AP_hand_index);//minionV.player
	void play(int AP_hand_index, std::stringstream &ss);//play from hand to board
	void use(int AP_board_index, std::stringstream &ss);//use card on board
	void inspect(int AP_board_index);
	void displayHand();
	void displayBoard();
	void setTesting(bool testing_on);
	bool getTesting();
};//end of class GAme

#endif

