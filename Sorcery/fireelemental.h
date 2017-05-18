#ifndef _FIREELEMENTAL_H_
#define _FIREELEMENTAL_H_

#include "triggerminion.h"

class FireElemental : public TriggerMinion{
	public:
		FireElemental();
		~FireElemental();
		void notify(Game *g);
		Trigger getTrigger();
};

#endif


