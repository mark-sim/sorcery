#include "game.h"
#include "magicfatigue.h"
using namespace std;

MagicFatigue::MagicFatigue(Card *card) : EnchantmentDecorator{card,"Magic Fatigue", 0, "Enchanted minion's activated ability costs 2 more"}{
	this->attpoint = this->component->getAtt();
	this->defpoint = this->component->getDef();
	this->actpoint = this->component->getAct();
	this->actCost = this->component->getCost() + 2;
	this->isAbility = this->component->getIsAbility();
}

MagicFatigue::MagicFatigue() : EnchantmentDecorator{"Magic Fatigue", 0, "Enchanted minion's activated ability costs 2 more"} {
	this->cardName = "Magic Fatigue";
}

void MagicFatigue::setDef(int defpoint) {
	this->defpoint = defpoint;
}

string MagicFatigue::getName() {
	return this->cardName;
}

bool MagicFatigue::getIsAbility() {
        return this->isAbility;
}

int MagicFatigue::getAtt() {
	return this->attpoint;
}

int MagicFatigue::getDef() {
	return this->defpoint;
}

int MagicFatigue::getAct() {
	return this->actpoint;
}

int MagicFatigue::getActCost() {
	return this->actCost;
}

void MagicFatigue::play(Game *g, int i, stringstream &ss) {
        int player;
        int target_minion;

        //checking validity
        if (g->getAP()->getMP() < this->getCost()){
                throw "You do not have enough MP to use Magic Fatigue.";
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
                g->getAP()->getBoard()->setMinion(new MagicFatigue{toBeEnchanted},target_minion-1);
        } else {
		ss >> target_minion;
		if(ss.fail()) {
			ss.clear();
                	cin >> target_minion;
		}

                Card *toBeEnchanted = g->getNAP()->getBoard()->getMinion(target_minion);
                delete g->getAP()->getHand()->playHand(i);
                g->getNAP()->getBoard()->setMinion(new MagicFatigue{toBeEnchanted},target_minion-1);
        }

        //after function application apply mp deduction
        g->getAP()->changeMP(this->getCost() * -1, g->getTesting());
}

vector<card_template_t> MagicFatigue::display(int att, int def, int actCost) {
        vector<card_template_t> toBeReturned;
        if(component) {
                try {
                        toBeReturned = component->display(att,def,actCost);
                } catch(...) {
                }
        }
        card_template_t temp = display_enchantment("Magic Fatigue", 0, "Enchanted minion's activated ability costs 2 more");
        toBeReturned.emplace_back(temp);
        return toBeReturned;
}

