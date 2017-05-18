#ifndef _DISENCHANT_H_
#define _DISENCHANT_H_
#include "abstractspell.h"

class Disenchant:public AbstractSpell{

	public:
		Disenchant();
		~Disenchant();
		void play(Game *g, int i, std::stringstream &ss);
	
};

#endif
