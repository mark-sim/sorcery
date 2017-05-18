#include "banish.h"
using namespace std;

Banish::Banish() : AbstractSpell{"Banish", 2,
			"Destroy target minion or ritual"}{};

Banish::~Banish(){};

void Banish::play(Game *g, int i, stringstream &ss){
	int player;
	char target_ritual;
	int target_minion;
	if(!g->getTesting()){
	//checking validity
		if (g->getAP()->getMP() < this->getCost()){
			throw "You do not have enough MP to use Banish.";
		}//end 
	}

	//take in the second parameter to inidacte player
	ss >> player;
	if(ss.fail()) {
		ss.clear();
		cin >> player;
	}
	
	if (player == g->getAP()->getPlayerNumber()){
	//call on player one		
		//take in the target card
		ss >> target_ritual;
		if(ss.fail()) {
			ss.clear();
			cin >> target_ritual;
		}
		
		if (target_ritual == 'r'){
		// if the target card is a ritual
			g->getAP()->getBoard()->playRitual(nullptr);
		}
		else{
		// if the target card is a minion
		//implicit cast char to int
			target_minion = target_ritual - '0';
			cout << "your number is:" << target_minion << "asdfa" << endl;
			g->getAP()->getBoard()->sendToGraveyard(target_minion);
		}	
	}
	else{
	//call on player two
		//almost identical implementation as the above
		cin >> target_ritual;

		if (target_ritual == 'r'){
			g->getNAP()->getBoard()->playRitual(nullptr);
		}
		else{
			target_minion = target_ritual - '0';
			g->getNAP()->getBoard()->sendToGraveyard(target_minion);
		}
	}
	
	//after function application apply mp deduction
	g->getAP()->changeMP(this->getCost() * -1, g->getTesting());
};



