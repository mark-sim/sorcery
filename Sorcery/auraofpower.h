#ifndef AURAOFPOWER_H
#define AURAOFPOWER_H

#include "abstractritual.h"

class AuraOfPower : public AbstractRitual{
	Trigger trig;
		
	public:
	AuraOfPower();
	void notify(Game *game) override;

};//end of class AuraOfPower


#endif


