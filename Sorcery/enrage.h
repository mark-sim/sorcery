#ifndef ENRAGE_H
#define ENRAGE_H

#include "enchantmentdecorator.h"

class Enrage : public EnchantmentDecorator {
	public:
	Enrage(Card *card);
	Enrage();
	void setDef(int defpoint) override;	
	std::string getName() override;
	bool getIsAbility() override;
        int getAtt() override;
        int getDef() override;
        int getAct() override;
        int getActCost() override;
	void play(Game *g, int i, std::stringstream &ss) override;
	std::vector<card_template_t> display(int att, int def, int actCost) override;
};	


#endif
