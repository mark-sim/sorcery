#ifndef GIANTSTRENGTH_H
#define GIANTSTRENGTH_H

#include "enchantmentdecorator.h"

class GiantStrength : public EnchantmentDecorator {
	public:
	GiantStrength(Card *card);
	GiantStrength();
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
