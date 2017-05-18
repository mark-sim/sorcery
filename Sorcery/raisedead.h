#ifndef _RAISEDEAD_H_
#define _RAISEDEAD_H_

#include "abstractspell.h"
class Game;

class RaiseDead: public AbstractSpell{
	public:
		RaiseDead();
		~RaiseDead();
		void play(Game *g, int i, std::stringstream &ss);	
};

#endif
