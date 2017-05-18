#include "game.h"
#include <iostream>
using namespace std;	

Game::Game(Player *AP, Player *NAP):AP{AP},NAP{NAP}{
	testing_on = false;
}//end of constructor

        
Player *Game::getAP(){
	return AP;
}//end of getAP

Player *Game::getNAP(){
	return NAP;
}//end of getNAP

//Game Commands
void Game::help(){
        cout << "help -- Display this message." << endl;
        cout << "end -- End the current player's turn." << endl;
        cout << "quit -- End the game." << endl;
        cout << "attack minion other-minion --";
	cout << " Orders minion to attack other-minion." << endl;
	cout << "attack minion -- ";
	cout << "Orders minion to attack the opponent." << endl;
	cout << "play card [target-player target-card] -- ";
	cout << "Play card, optionally";
	cout << " targeting target-card owned by target-player." << endl;
	cout << "use minion [target-player target-card] -- Use minion's";
	cout << " special ability, optionally targeting ";
	cout << "target-card owned by target-player." << endl;
	cout << "inspect minion -- View a minion's";
	cout << " card and all enchantments on that minion." << endl;
	cout << "hand -- Describe all cards in your hand." << endl;
	cout << "board -- Describe all cards on the board." << endl;
}//end of help

void Game::changeTurn(){
	Player *temp = AP;
	AP = NAP;
	NAP = temp;
}//end of changeTurn

void Game::attack(int AP_board_index, int NAP_board_index) {
	Card *enemyMinion = this->getNAP()->getBoard()->getMinion(NAP_board_index);
        this->getAP()->getBoard()->getMinion(AP_board_index)->attack(enemyMinion,this);
}//minionV.minion

void Game::attack(int AP_hand_index){
			this->getAP()->getBoard()->getMinion(AP_hand_index)->attack(this);
	
}//minionV.player

void Game::play(int AP_hand_index, stringstream &ss){
	try {
		this->getAP()->getHand()->playHand(AP_hand_index)->play(this, AP_hand_index, ss);
		this->getAP()->getHand()->sort(AP_hand_index-1);
	} catch(char const* errorMessage) {
		cout << errorMessage << endl;
	}
}//play from hand to board
void Game::use(int AP_board_index, stringstream &ss) {
	Card *minion = this->AP->getBoard()->getMinion(AP_board_index);
	if(minion->getIsAbility()) {
		minion->activate(this, ss);
	}

}//use card on board

void Game::inspect(int AP_board_index) {
	Player *ap = this->AP;
	Board *b = ap->getBoard();
	Card *minion = b->getMinion(AP_board_index);
	try {
		vector<card_template_t> print = minion->display(minion->getAtt(), minion->getDef(), minion->getActCost());
		for(auto i : print[0]) {
			cout << i << endl;
		}
		
		int remainder = (print.size()-1) % 5;
		int div = (print.size()-1) / 5;
		int loop = 0;
	
		if(print.size() > 1) {
		while(loop < div) {
			for(int i=0; i<11; i++) {
				for(int j=1; j<6; j++) {
					cout << print[j+(loop*5)][i];
				}
				cout << endl;
			}
		loop++;
		}
		if(remainder != 0) {
		for(int i=0; i<11; i++) {
			for(int j=1; j<(remainder+1); j++) {
				cout << print[j+(loop*5)][i];
			}
			cout << endl;
		}
		}
		}


		
	} catch(...) {
	}
}
void Game::displayHand() {
	this->AP->getHand()->display();

}

void Game::displayBoard() {
	if(this->AP->getPlayerNumber() == 1) {
		this->AP->getBoard()->displayA(this->AP);
		this->NAP->getBoard()->displayB(this->NAP);
	} else {
		this->NAP->getBoard()->displayA(this->NAP);
		this->AP->getBoard()->displayB(this->AP);
	}
		

}

void Game::setTesting(bool testing_on){
	this->testing_on = testing_on;
}//end of method setTesting

bool Game::getTesting(){
	return this->testing_on;
}//end of method getTesting

