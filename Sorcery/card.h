#ifndef CARD_H_
#define CARD_H_
#include <string>
#include <sstream>
#include "trigger.h"
#include "ascii_graphics.h"
class Game;

class Card{
	std::string name;
	int cost;
	int actpoint;
	std::string description;
	std::string type;
	public:
		virtual void changeCharge(int change);
		virtual void setAtt(int attpoint);
		virtual int getCharge();
		virtual void activate(Game *game, std::stringstream &ss);
		virtual void play(Game *g, int i, std::stringstream &ss) = 0;
		virtual bool getIsAbility();
		virtual int getAtt();
		virtual int getDef();
		virtual int getAct();
		std::string getDesc();
		virtual void setDef(int defpoint);
		virtual void setAct(int actpoint);
		virtual int getActCost();
		virtual void attack(Card *card, Game *game);
		virtual void attack(Game *game);
		virtual void getAttacked(int damage);
		virtual void notify(Game *game);
		virtual Trigger getTrigger() = 0;
		virtual std::vector<card_template_t> display(int att, int def, int actCost) = 0;
		Card();
		Card(std::string name, int cost, std::string description, 
							std::string type);
		virtual std::string getName();
		int getCost();
		virtual ~Card();
		virtual bool isEnchantment();
		virtual Card *getOriginalCard();
};
#endif
