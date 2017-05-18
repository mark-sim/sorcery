#include "player.h"
#include <iostream>
using namespace std;

Player::Player(string name,Hand hand,int playerNumber):name{name}, hand{hand}, playerNumber{playerNumber} {
}//end on constructor

void Player::Draw() {
	hand.Draw();
}

int Player::getPlayerNumber() {
	return this->playerNumber;
}

string Player::getName(){
	return this->name;
}//end of getName

Board *Player::getBoard() {
	return &this->board;
}

Hand *Player::getHand() {
	return &this->hand;
}

int Player::getMP() {
	return this->mp;
}

void Player::changeMP(int change, bool testing_on){
	if (!testing_on){
	//if testing is off, then deduct MP as per usual
		this->mp += change;
	}
	else{
	//if testing is on, then set MP to zero each time
		this->mp += change;
		if(this->mp < 0) {
			this->mp = 0;
		}
	}
}

void Player::changeHP(int change){
	this->hp += change;
}//end of method changeHP

int Player::getHP(){
	return this->hp;
}//end of method getHP

