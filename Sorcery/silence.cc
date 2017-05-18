#include "game.h"
#include "silence.h"
using namespace std;

Silence::Silence(Card *card) : EnchantmentDecorator{card,"Silence", 1, "Enchanted minion cannot use abilities"}{
        this->attpoint = this->component->getAtt();
        this->defpoint = this->component->getDef();
        this->actpoint = this->component->getAct();
        this->actCost = this->component->getCost();
        this->isAbility = false;

}

Silence::Silence() : EnchantmentDecorator{"Silence", 1, "Enchanted minion cannot use abilities"} {
        this->cardName = "Silence";
}

void Silence::setDef(int defpoint) {
        this->defpoint = defpoint;
}

string Silence::getName() {
        return this->cardName;
}

bool Silence::getIsAbility() {
        return this->isAbility;
}

int Silence::getAtt() {
        return this->attpoint;
}

int Silence::getDef() {
        return this->defpoint;
}

int Silence::getAct() {
        return this->actpoint;
}

int Silence::getActCost() {
        return this->actCost;
}

void Silence::play(Game *g, int i, stringstream &ss) {
        int player;
        int target_minion;

        //checking validity
        if (g->getAP()->getMP() < this->getCost()){
                throw "You do not have enough MP to use Silence.";
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
                g->getAP()->getBoard()->setMinion(new Silence{toBeEnchanted},target_minion-1);
        } else {
		ss >> target_minion;
		if(ss.fail()) {
			ss.clear();
                	cin >> target_minion;
		}

                Card *toBeEnchanted = g->getNAP()->getBoard()->getMinion(target_minion);
                delete g->getAP()->getHand()->playHand(i);
                g->getNAP()->getBoard()->setMinion(new Silence{toBeEnchanted},target_minion-1);
        }

        //after function application apply mp deduction
        g->getAP()->changeMP(this->getCost() * -1, g->getTesting());
}

vector<card_template_t> Silence::display(int att, int def, int actCost) {
        vector<card_template_t> toBeReturned;
        if(component) {
                try {
                        toBeReturned = component->display(att,def,actCost);
                } catch(...) {
                }
        }
        card_template_t temp = display_enchantment("Silence", 1, "Enchanted minion cannot use abilities");
        toBeReturned.emplace_back(temp);
        return toBeReturned;
}
