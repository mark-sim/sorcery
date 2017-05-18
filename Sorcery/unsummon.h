#ifndef _UNSUMMON_H_
#define _UNSUMMON_H_
#include "abstractspell.h"
#include "subject.h"

class Unsummon : public AbstractSpell{

	public:
		Unsummon();
		~Unsummon();
		void play(Game *g, int i, std::stringstream &s);
};

#endif
