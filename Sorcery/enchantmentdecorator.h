#ifndef ENCHANTMENTDECORATOR_H
#define ENCHANTMENTDECORATOR_H

#include "card.h"
#include "trigger.h"
#include <string>
#include "ascii_graphics.h"

class EnchantmentDecorator : public Card {
	protected:
	Card *component = nullptr;
	std::string cardName;
	bool isAbility;
	bool haste = false;
	int actpoint;
	int attpoint;
	int defpoint;
	int actCost;
	Card *originalCard = nullptr;
	public:
	EnchantmentDecorator(std::string name, int cost, std::string description);
	EnchantmentDecorator(Card *card, std::string name, int cost, std::string description);
	Trigger getTrigger() override;
	void attack(Card *card, Game *game) override;
        void attack(Game *game) override;
        void getAttacked(int damage) override;
	~EnchantmentDecorator() = 0;
	bool isEnchantment() override;
	Card *getOriginalCard() override;
	void setAct(int actpoint) override;
	int getAct() override;
};
	


#endif
