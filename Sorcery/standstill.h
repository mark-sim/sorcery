#ifndef STANDSTILL_H
#define STANDSTILL_H

#include "abstractritual.h"

class StandStill : public AbstractRitual{
	Trigger trig;
		
	public:
	StandStill();
	void notify(Game *game) override;
	
};//end of class StandStill


#endif


