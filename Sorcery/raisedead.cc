#include "raisedead.h"

using namespace std;

RaiseDead::RaiseDead(): AbstractSpell("Raise Dead", 1,
	"Resurrect the top minion in your graveyard and set its defence to 1"){};

RaiseDead::~RaiseDead(){}

void RaiseDead::play(Game *g, int i, stringstream &ss){
	//check validity of use
	if (!g->getTesting()){
		if (g->getAP()->getMP() < this->getCost()){
			throw "You do not have enough MP to use Raise Dead.";
		}//end of if
	}//end of if

	if (g->getAP()->getBoard()->getMinionCount() >= 5){
		throw "There are too many minions on the field already.";
	}

	g->getAP()->getBoard()
		->playMinion(g->getAP()->getBoard()->getGraveyard()->pop(), g);
	g->getAP()->changeMP(this->getCost() * -1, g->getTesting());
};
