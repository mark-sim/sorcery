#ifndef _MASTERSUMMONER_H_
#define _MASTERSUMMONER_H_

#include "activationminion.h"
#include "airelemental.h"
class MasterSummoner : public ActivationMinion {
	public:
		MasterSummoner();
		~MasterSummoner() override;
		void activate(Game *g, std::stringstream &ss) override;
};

#endif

