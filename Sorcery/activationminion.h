#ifndef _ACTIVATIONMINION_H_
#define _ACTIVATIONMINION_H_

#include "game.h"
#include "abstractminion.h"
#include "trigger.h"

class ActivationMinion: public AbstractMinion{
        int actCost;
        public:
                ActivationMinion(int defpoint, int attpoint, int actpoint, bool isAbility, std::string name, int cost, std::string description, int actCost);
                virtual ~ActivationMinion() = 0;
                int getActCost();
                void notify(Game *);
                Trigger getTrigger() override;
                std::vector<card_template_t> display(int att, int def, int actCost) override;
                void play(Game *g, int i, std::stringstream &ss) override;
};

#endif

