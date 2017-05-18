#include "novicepyromancer.h"

using namespace std;

NovicePyromancer::NovicePyromancer()
	: ActivationMinion{1, 0, 0, true, "Novice Pyromancer", 1,
"Deal 1 damage to target minion", 1}{}

NovicePyromancer::~NovicePyromancer(){}

void fire(Game *g, int p, int m){
	Player *player;
	if(p == g->getAP()->getPlayerNumber()){
		player = g->getAP();
	}
	else {
		player = g->getNAP();
	}
	Board *b = player->getBoard();
	Card* minion = b->getMinion(m);
	minion->getAttacked(1);
	b->checkDead(g);
}


void NovicePyromancer::activate(Game *g, stringstream &ss){
	int target_player;
	int target_minion;
	ss >> target_player;
	if (ss.fail()) {
		ss.clear();
		cin >> target_player;
	}

	ss >> target_minion;
	if (ss.fail()) {
		ss.clear();
		cin >> target_minion;
	}

	if(g->getAP()->getMP() >= this->getActCost()){
		fire(g, target_player, target_minion);
		g->getAP()->changeMP(this->getActCost() * -1, g->getTesting());
	}
	
}

