#include "potionseller.h"

using namespace std;

PotionSeller::PotionSeller()
	: TriggerMinion{3, 1, 0, false, "Potion Seller", 2,
	"At the end of your turn, all your minions gain +0/+1."}{}

PotionSeller::~PotionSeller(){};

void PotionSeller::notify(Game *g){
	int count = g->getAP()->getBoard()->getMinionCount();
	for(int i=0; i<count; i++) {
		Card *temp = g->getAP()->getBoard()->getMinion(i+1);
		temp->setDef(temp->getDef() + 1);
	}
}

Trigger PotionSeller::getTrigger(){
	return Trigger::End;
}


