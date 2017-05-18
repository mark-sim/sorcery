#include "abstractminion.h"
#include "card.h"
#include "game.h"
using namespace std;

AbstractMinion::AbstractMinion(int defpoint, int attpoint,
			 int actpoint, bool isAbility, string name, int cost, string description) :
						Card{name, cost, description, "Minion"},
						defpoint{defpoint}, 
						attpoint{attpoint}, actpoint{actpoint}, 
						isAbility{isAbility} {}


bool AbstractMinion::getIsAbility() {
	return this->isAbility;
}

int AbstractMinion::getAtt() {
	return this->attpoint;
}

int AbstractMinion::getDef() {
	return this->defpoint;
}

int AbstractMinion::getAct() {
	return this->actpoint;
}

void AbstractMinion::setAct(int actpoint) {
	this->actpoint = actpoint;
}

void AbstractMinion::setAtt(int attpoint) {
	this->attpoint = attpoint;
}

void AbstractMinion::setDef(int defpoint) {
	this->defpoint = defpoint;
}

void AbstractMinion::attack(Card *card, Game *game) {
	if(this->actpoint > 0) {	
		card->getAttacked(this->attpoint);
		this->getAttacked(card->getAtt());
		game->getNAP()->getBoard()->checkDead(game);
		game->getAP()->getBoard()->checkDead(game);
		this->actpoint--;
	}
}
  
void AbstractMinion::attack(Game *game) {
	if(this->actpoint > 0) {
		game->getNAP()->changeHP(this->attpoint * -1);
		this->actpoint--;
	}
}

void AbstractMinion::getAttacked(int damage) {
	this->setDef(this->defpoint - damage);
}
