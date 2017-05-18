#include "mastersummoner.h"

using namespace std;

MasterSummoner::MasterSummoner()
	: ActivationMinion{3, 2, 0, true, "Master Summoner", 3,
"Summon up to three 1/1 air elementals", 2}{}

MasterSummoner::~MasterSummoner(){}

void MasterSummoner::activate(Game *g, stringstream &ss){
	if(g->getAP()->getMP() >= this->getActCost()){
		Board *b = g->getAP()->getBoard();
		for(int i = 0; i < 3; i++){
			b->playMinion(new AirElemental(), g);
		}
		g->getAP()->changeMP(this->getActCost() * -1, g->getTesting());

	}

}

