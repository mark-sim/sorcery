#include "activationminion.h"

using namespace std;

ActivationMinion::ActivationMinion(int defpoint, int attpoint,
                        int actpoint, bool isAbility, string name, int cost, string description, int actCost)
        : AbstractMinion{defpoint, attpoint, actpoint, isAbility, name, cost, description}{
	this->actCost = actCost;
}

ActivationMinion::~ActivationMinion(){}

int ActivationMinion::getActCost(){
        return this->actCost;
}

void ActivationMinion::notify(Game *g){
}

Trigger ActivationMinion::getTrigger(){
        return Trigger::None;
}

void ActivationMinion::play(Game *g, int i, stringstream &ss){
	//first check MP cost requirements
        if( this->getCost() > g->getAP()->getMP()){
                throw "You do not have enough MP to summon this minion!";
        }
        Card *toPlay = g->getAP()->getHand()->playHand(i);
        g->getAP()->getBoard()->playMinion(toPlay, g);
        g->getAP()->changeMP(toPlay->getCost() * -1, g->getTesting());

}
vector<card_template_t>  ActivationMinion::display(int att, int def, int actCost){
	vector<card_template_t> toReturn;
	card_template_t temp = display_minion_activated_ability(this->getName(), this->getCost(), att, def, actCost, this->getDesc());
	toReturn.emplace_back(temp);
	return toReturn;

}

