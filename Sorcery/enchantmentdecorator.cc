#include "game.h"
#include "enchantmentdecorator.h"
using namespace std;

EnchantmentDecorator::EnchantmentDecorator(Card *card, std::string name, int cost, std::string description) : Card{name,cost,description,"Enchantment"}, component{card} {
	if(!this->component->isEnchantment()) {
                this->originalCard = component;
	} else {
		this->originalCard = component->getOriginalCard();
	}
	this->cardName = this->originalCard->getName();
}

EnchantmentDecorator::EnchantmentDecorator(std::string name, int cost, std::string description) : Card{name, cost, description, "Enchantment"} {}

EnchantmentDecorator::~EnchantmentDecorator() {
	if(this->component != this->originalCard) {
		delete this->component;
	}
}

Trigger EnchantmentDecorator::getTrigger() {
	return component->getTrigger();
}

void EnchantmentDecorator::attack(Card *card, Game *game) {
	if(this->actpoint > 0) {
       	     card->getAttacked(this->attpoint);
       	     this->getAttacked(card->getAtt());
   	     game->getNAP()->getBoard()->checkDead(game);
       	     game->getAP()->getBoard()->checkDead(game);
	     this->actpoint--;
	}
}

void EnchantmentDecorator::attack(Game *game) {
	if(this->actpoint > 0) {
		cout << this->getAct() << endl;
        	game->getNAP()->changeHP(this->attpoint * -1);
		this->actpoint--;
	}
}	

void EnchantmentDecorator::getAttacked(int damage) {
        this->setDef(this->defpoint - damage);
}

bool EnchantmentDecorator::isEnchantment() {
	return true;
}

Card *EnchantmentDecorator::getOriginalCard(){
	return this->originalCard;
}

void EnchantmentDecorator::setAct(int actpoint)  {
	this->actpoint = actpoint;
	if(this->haste) {
		this->actpoint++;
	}
}

int EnchantmentDecorator::getAct() {
	return this->actpoint;
}	
