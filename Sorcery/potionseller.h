#ifndef _POTIONSELLER_H_
#define _POTIONSELLER_H_

#include "triggerminion.h"

class PotionSeller : public TriggerMinion{
	public:
		PotionSeller();
		~PotionSeller();
		void notify(Game *g);
		Trigger getTrigger();
};

#endif


