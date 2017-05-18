#ifndef _BONEGOLEM_H_
#define _BONEGOLEM_H_

#include "triggerminion.h"

class BoneGolem : public TriggerMinion{
	public:
		BoneGolem();
		~BoneGolem();
		void notify(Game *g);
		Trigger getTrigger();
};

#endif

