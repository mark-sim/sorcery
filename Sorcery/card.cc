#include "card.h"
#include <iostream>
#include <string>
using namespace std;

int Card::getCharge() {
	return -10;
}
void Card::changeCharge(int change) {}

void Card::setAtt(int attpoint) {}
bool Card::getIsAbility() {return -1;}

Card::Card() {}

Card::~Card() {}

int Card::getAtt() {return -10;}

void Card::activate(Game *game, stringstream &ss) {}

int Card::getDef() {return -10;}

int Card::getAct() {return -10;}

int Card::getActCost() { return -10;}

void Card::attack(Card *card, Game *game) {}

void Card::attack(Game *game) {

}

void Card::setAct(int actpoint) {
	this->actpoint = actpoint;
}

void Card::getAttacked(int damage) {}

Card::Card(string name, int cost, string description, string type)
	: name{name}, cost{cost}, description{description}, type{type}{}

string Card::getName() {
	return this->name;
}

int Card::getCost() {
	return this->cost;
}

void Card::setDef(int defPoint) {
}

string Card::getDesc() {
	return this->description;
}

bool Card::isEnchantment() {
	return false;
}

Card *Card::getOriginalCard() {
	return nullptr;
}

void Card::notify(Game *game) {
}
