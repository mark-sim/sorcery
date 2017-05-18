#ifndef NONABILITYMINION_H
#define NONABILITYMINION_H

#include "game.h"
#include "abstractminion.h"
#include "trigger.h"
#include <string>

class NonAbilityMinion : public AbstractMinion {
	public:
	NonAbilityMinion(int defpoint, int attpoint, int actpoint, bool isAbility,
			std::string name, int cost, std::string description);
	virtual ~NonAbilityMinion() = 0;
	int getActCost();
	void notify(Game *);
	Trigger getTrigger() override;
	std::vector<card_template_t> display(int att, int def, int actCost) override;
	void play(Game *g, int i, std::stringstream &ss);
};


#endif
