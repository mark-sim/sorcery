#ifndef _TRIGGERMINION_H_
#define _TRIGGERMINION_H_

#include "subject.h"
#include "game.h"
#include "abstractminion.h"
#include "trigger.h"

class TriggerMinion :  public AbstractMinion {
        public:
                TriggerMinion(int defpoint, int attpoint, int actpoint, bool isAbility,
                 std::string name, int cost, std::string description);
                virtual ~TriggerMinion() = 0;
                int getActCost();
                void notify(Game *);
                Trigger getTrigger() override;
                std::vector<card_template_t> display(int att, int def, int actCost) override;
                void play(Game *g, int i, std::stringstream &ss);
};

#endif


