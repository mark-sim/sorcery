#include "darkritual.h"

using namespace std;

DarkRitual::DarkRitual():AbstractRitual{"Dark Ritual", 0,
			"At the start of your turn, gain 1 magic",
			5,1,Trigger::Start}{}

void DarkRitual::notify(Game *game){
	if (this->getCharge() >= this->getActCost()){
	//check for enough charge
		//increase AP MP
		game->getAP()->changeMP(1,game->getTesting());

		//deduct charge
		this->changeCharge(this->getActCost() * -1);
	}
	else{
	//not enough charge
		cout << "you do not have enough charge on ritual.";
	}
}


