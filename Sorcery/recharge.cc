#include "recharge.h"

using namespace std;

Recharge::Recharge()
	: AbstractSpell("Recharge", 1, "Your ritual gains 3 charges") {}

Recharge::~Recharge() {}

void Recharge::play(Game *g, int i, stringstream &ss){
	Player *ap = g->getAP();
	if(ap->getMP() >= this->getCost() || g->getTesting()){
			Card *r = g->getAP()->getBoard()->getRitual();
		if(r){
			r->changeCharge(3);
		}
		else{
			throw "no ritual!!";
		}

	}
	else{
		throw "not enough Magic points";
	}
}
