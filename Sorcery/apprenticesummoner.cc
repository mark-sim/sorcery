#include "apprenticesummoner.h"

using namespace std;

ApprenticeSummoner::ApprenticeSummoner()
	: ActivationMinion{1, 1, 0, true, "Apprentice Summoner", 1,
"Summon a 1/1 air elemental", 1}{}

ApprenticeSummoner::~ApprenticeSummoner(){}

void ApprenticeSummoner::activate(Game *g, stringstream &ss){
	if(g->getAP()->getMP() >= this->getActCost()){
		Player *p = g->getAP();
		Board *b = p->getBoard();
		b->playMinion(new AirElemental(), g);
		g->getAP()->changeMP(this->getActCost() * -1, g->getTesting());
	}

}

