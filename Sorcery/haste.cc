#include "haste.h"
#include "game.h"
using namespace std;

Haste::Haste(Card *card) : EnchantmentDecorator{card,"Haste", 1, "Enchanted minion gains +1 action each turn"}{
	this->attpoint = this->component->getAtt();
	this->defpoint = this->component->getDef();
	this->actpoint = this->component->getAct() + 1;
	this->actCost = this->component->getCost();
	this->isAbility = this->component->getIsAbility();
	this->haste = true;
}

Haste::Haste() : EnchantmentDecorator{"Haste", 1, "Enchanted minion gains +1 action each turn"} {
	this->cardName = "Haste";
}

void Haste::setDef(int defpoint) {
	this->defpoint = defpoint;
}

string Haste::getName() {
	return this->cardName;
}

bool Haste::getIsAbility() {
	return this->isAbility;
}

int Haste::getAtt() {
	return this->attpoint;
}

int Haste::getDef() {
	return this->defpoint;
}

int Haste::getAct() {
	return this->actpoint;
}

int Haste::getActCost() {
	return this->actCost;
}

void Haste::play(Game *g, int i, stringstream &ss) {
	int player;
        int target_minion;

        //checking validity
        if (g->getAP()->getMP() < this->getCost()){
                throw "You do not have enough MP to use Haste.";
        }//end 

        //take in the second parameter to indicate player
	ss >> player;
	if(ss.fail()) {
		ss.clear();
        	cin >> player;
	}

        if (player == g->getAP()->getPlayerNumber()) {
                ss >> target_minion;
		if(ss.fail()) {
			ss.clear();
			cin >> target_minion;
		}

                Card *toBeEnchanted = g->getAP()->getBoard()->getMinion(target_minion);
                delete g->getAP()->getHand()->playHand(i);
                g->getAP()->getBoard()->setMinion(new Haste{toBeEnchanted},target_minion-1);
        } else {
		ss >> target_minion;
		if(ss.fail()) {
			ss.clear();
                	cin >> target_minion;
		}

                Card *toBeEnchanted = g->getNAP()->getBoard()->getMinion(target_minion);
                delete g->getAP()->getHand()->playHand(i);
                g->getNAP()->getBoard()->setMinion(new Haste{toBeEnchanted},target_minion-1);
        }

        //after function application apply mp deduction
        g->getAP()->changeMP(this->getCost() * -1, g->getTesting());
}

vector<card_template_t> Haste::display(int att, int def, int actCost) {
	vector<card_template_t> toBeReturned;
	if(component) {
		try {
			toBeReturned = component->display(att,def,actCost);
		} catch(...) {
		}
	}
	card_template_t temp = display_enchantment("Haste", 1, "Enchanted minion gains +1 action each turn");
	toBeReturned.emplace_back(temp);
	return toBeReturned;
}
