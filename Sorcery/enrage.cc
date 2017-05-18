#include "enrage.h"
#include "game.h"
using namespace std;

Enrage::Enrage(Card *card) : EnchantmentDecorator{card,"Enrage", 2, ""} {
	this->attpoint = this->component->getAtt() *2;
	this->defpoint = this->component->getDef() *2;
	this->actpoint = this->component->getAct();
	this->actCost = this->component->getCost();
	this->isAbility = this->component->getIsAbility();

}


Enrage::Enrage() : EnchantmentDecorator{"Enrage", 2, ""} {
        this->cardName = "Enrage";
}

void Enrage::setDef(int defpoint) {
	this->defpoint = defpoint;
}

string Enrage::getName() {
	return this->cardName;
}

bool Enrage::getIsAbility() {
	return this->isAbility;
}

int Enrage::getAtt() {
	return this->attpoint;
}

int Enrage::getDef() {
	return this->defpoint;
}

int Enrage::getAct() {
	return this->actpoint;
}

int Enrage::getActCost() {
	return this->actCost;
}

void Enrage::play(Game *g, int i, stringstream &ss) {
        int player;
        int target_minion;

        //checking validity
        if (g->getAP()->getMP() < this->getCost()){
                throw "You do not have enough MP to use Enrage.";
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
                g->getAP()->getBoard()->setMinion(new Enrage{toBeEnchanted},target_minion-1);
        } else {
		ss >> target_minion;
		if(ss.fail()) {
			ss.clear();
                	cin >> target_minion;
		}

                Card *toBeEnchanted = g->getNAP()->getBoard()->getMinion(target_minion);
                delete g->getAP()->getHand()->playHand(i);
                g->getNAP()->getBoard()->setMinion(new Enrage{toBeEnchanted},target_minion-1);
        }

        //after function application apply mp deduction
        g->getAP()->changeMP(this->getCost() * -1, g->getTesting());
}

vector<card_template_t> Enrage::display(int att, int def, int actCost) {
	vector<card_template_t> toBeReturned;
	if(component) {
		try {
			toBeReturned = component->display(att,def,actCost);
		} catch(...) {
		}
	}
	card_template_t temp = display_enchantment_attack_defence("Enrage", 2, "", "*2", "*2");
	toBeReturned.emplace_back(temp);
	return toBeReturned;
}
