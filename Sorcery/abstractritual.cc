#include "abstractritual.h"
#include "trigger.h"
using namespace std;

AbstractRitual::AbstractRitual(string name, int cost, string description,
			    int charge, int actCost, Trigger trig):
		Card{name,cost,description,"Ritual"},charge{charge}, actCost{actCost},
		      trig{trig}{}

AbstractRitual::~AbstractRitual(){}


Trigger AbstractRitual::getTrigger(){
	return this->trig;
}


vector<card_template_t> AbstractRitual::display(int att, int def, int actCost) {
	vector<card_template_t> toReturn;
	card_template_t temp = display_ritual(this->getName(), this->getCost(), this->getActCost(), this->getDesc(), this->getCharge());
	toReturn.emplace_back(temp);
	return toReturn;
}

void AbstractRitual::play(Game *g, int i, stringstream &ss) {
	//first check MP cost requirements
	if( this->getCost() > g->getAP()->getMP()){
		throw "You do not have enough MP to summon this ritual!";
	}

	Card *toPlay = g->getAP()->getHand()->playHand(i);
        g->getAP()->getBoard()->playRitual(toPlay);
	g->getAP()->changeMP(toPlay->getCost() * -1, g->getTesting());
}


int AbstractRitual::getActCost(){
	return this->actCost;
}//end of method getActCost

int AbstractRitual::getCharge(){
	return this->charge;
}//end of method getCharge

void AbstractRitual::changeCharge(int i){
	this->charge += i;
}//end of changeCharge



