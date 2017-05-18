#include "abstractspell.h"

using namespace std;

AbstractSpell::AbstractSpell(string name, int cost, string description) :
                Card{name, cost, description, "Spell"}{}

AbstractSpell::~AbstractSpell(){}


vector<card_template_t> AbstractSpell::display(int att, int def, int actCost){
	vector<card_template_t> toReturn;
        card_template_t temp = display_spell(this->getName(), this->getCost(), this->getDesc());
        toReturn.emplace_back(temp);
        return toReturn;
}

Trigger AbstractSpell::getTrigger() {
	return Trigger::None;
}

