#include "auraofpower.h"

using namespace std;

AuraOfPower::AuraOfPower():
	AbstractRitual{"Aura Of Power", 1, 
			"Whenever a minion enters play under your control,it gains +1/+1", 4,1, Trigger::Enter}{}

void AuraOfPower::notify(Game *game){
	if (this->getCharge() >= this->getActCost()){
	//check for enough charge on ritual

		//find out the index of the newest minion on your board
		int minionCount = game->getAP()->getBoard()->getMinionCount();

		//get the card pointer of the newest minion on your board
		Card *new_minion = game->getAP()->getBoard()->getMinion(minionCount);

		//Add +1/+1 to the newest minion
		new_minion->setAtt(new_minion->getAtt() + 1);
		new_minion->setDef(new_minion->getDef() + 1);

		//deduct charge
		this->changeCharge(this->getActCost() * -1);
	}
	else{
	//not enough charge
		cout << "you do not have enough charge on ritual.";
	}
}


