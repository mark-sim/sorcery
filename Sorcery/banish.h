#ifndef _BANISH_H_
#define _BANISH_H_
#include "abstractspell.h"

class Banish: public AbstractSpell{

	public:
		Banish();
		~Banish();
		void play(Game *g,int i, std::stringstream &ss);

};

#endif

