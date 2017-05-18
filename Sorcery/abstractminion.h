#ifndef ABSTRACTMINION_H
#define ABSTRACTMINION_H

#include "card.h"
#include <string>
#include "trigger.h"

class AbstractMinion : public Card {
	int defpoint;
	int attpoint;
	int actpoint;
	bool isAbility;
	public:
	AbstractMinion(int defpoint, int attpoint, int actpoint, bool isAbility,
			std::string name, int cost, std::string description);
	bool getIsAbility() override;
	int getAtt() override;
	int getDef() override;
	int getAct() override;
	void setAtt(int attpoint) override;
	void setDef(int defpoint) override;
	void setAct(int actpoint) override;
	virtual Trigger getTrigger() = 0;
	void attack(Card *card, Game *game) override;
        void attack(Game *game) override;
        void getAttacked(int damage) override;
};

#endif
