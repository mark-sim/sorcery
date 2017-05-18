#ifndef ABSTRACTRITUAL_H
#define ABSTRACTRITUAL_H

#include <vector>
#include "card.h"
#include "game.h"
#include "trigger.h"

class AbstractRitual : public Card{
	int charge;
	int actCost;
	Trigger trig;

	public:
	AbstractRitual(std::string name, int cost, std::string description,
			 int charge,int actCost, Trigger trig);
	~AbstractRitual();
	void play(Game *game, int i, std::stringstream &ss) override;
	Trigger getTrigger() override;
	std::vector<card_template_t> display(int att, int def, int actCost) override;
	int getActCost() override;
	int getCharge() override;
	void changeCharge(int i);


};//end of class AbstractRitual



#endif

