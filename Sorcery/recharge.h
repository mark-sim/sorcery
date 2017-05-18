#ifndef _RECHARGE_H_
#define _RECHARGE_H_

#include "abstractspell.h"

class Recharge : public AbstractSpell{
	public:
		Recharge();
		~Recharge();
		void play(Game *g, int i, std::stringstream &ss);
	
};


#endif
