#include "triggerminion.h"

using namespace std;

TriggerMinion :: TriggerMinion(int defpoint, int attpoint, int actpoint, bool isAbility,
                 std::string name, int cost, std::string description)
	:	AbstractMinion{defpoint,attpoint,actpoint,isAbility,name,cost,description}{}

TriggerMinion :: ~TriggerMinion(){}

int TriggerMinion::getActCost(){ return -1; }

void TriggerMinion::notify(Game *) {}

Trigger TriggerMinion::getTrigger(){
	return Trigger::None;
}

void TriggerMinion::play(Game *g, int i, stringstream &ss){
	if(this->getCost() > g->getAP()->getMP()){
		throw "You do not have enough MP to summon this minion!";
	}
	Card *toPlay = g->getAP()->getHand()->playHand(i);
	g->getAP()->getBoard()->playMinion(toPlay,g);
	g->getAP()->changeMP(toPlay->getCost() * -1, g->getTesting());
}

vector<card_template_t> TriggerMinion::display(int att, int def, int actCost) {
	

	vector<card_template_t> toReturn;
        card_template_t temp = display_minion_triggered_ability(this->getName(), this->getCost(), att, def, this->getDesc());
	toReturn.emplace_back(temp);
        return toReturn;
}

