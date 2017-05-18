#ifndef DARKRITUAL_H
#define DARKRITUAL_H

#include "abstractritual.h"

class DarkRitual : public AbstractRitual{
	Trigger trig;
		
	public:
	DarkRitual();
	void notify(Game *game) override;
};//end of class DarkRitual


#endif

