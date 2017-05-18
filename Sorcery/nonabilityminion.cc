#include "nonabilityminion.h"
#include <iostream>
using namespace std;


NonAbilityMinion::NonAbilityMinion(int defpoint, int attpoint, int actpoint, bool isAbility,
			std::string name, int cost, std::string description) : AbstractMinion{defpoint,attpoint,actpoint,isAbility,name,cost,description} {}

NonAbilityMinion::~NonAbilityMinion() {}

int NonAbilityMinion::getActCost() { return -10;}

void NonAbilityMinion::notify(Game *) {}

Trigger NonAbilityMinion::getTrigger() {
	return Trigger::None;
}

void NonAbilityMinion::play(Game *g, int i, stringstream &ss) {
	//first check MP cost requirements
	if( this->getCost() > g->getAP()->getMP()){
		throw "You do not have enough MP to summon this minion!";
	}
	Card *toPlay = g->getAP()->getHand()->playHand(i);
        g->getAP()->getBoard()->playMinion(toPlay, g);
	g->getAP()->changeMP(toPlay->getCost() * -1, g->getTesting());
}

vector<card_template_t> NonAbilityMinion::display(int att, int def, int actCost) {
	vector<card_template_t> toReturn;
	card_template_t temp = display_minion_no_ability(this->getName(), this->getCost(), att, def);
	toReturn.emplace_back(temp);
	return toReturn;

}
