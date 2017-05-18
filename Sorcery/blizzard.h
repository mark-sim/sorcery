#ifndef _BLIZZARD_H_
#define _BLIZZARD_H_

#include "abstractspell.h"

class Blizzard: public AbstractSpell{
	public:
		Blizzard();
		~Blizzard();
		void play(Game *g, int i, std::stringstream &ss);	
};

#endif

