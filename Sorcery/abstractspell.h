#ifndef _ABSTRACTSPELL_H_
#define _ABSTRACTSPELL_H_

#include "card.h"
#include "game.h"
#include "trigger.h"


class AbstractSpell: public Card{

	public:
		AbstractSpell(std::string name, int cost,
					 std::string description);
		~AbstractSpell();
		Trigger getTrigger() override;
		std::vector<card_template_t> display(int att, int def, int actCost) override;
};


#endif

