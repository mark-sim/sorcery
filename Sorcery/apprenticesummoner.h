#ifndef _APPRENTICESUMMONER_H_
#define _APPRENTICESUMMONER_H_

#include "activationminion.h"
#include "airelemental.h"
class ApprenticeSummoner : public ActivationMinion {
	public:
		ApprenticeSummoner();
		~ApprenticeSummoner() override;
		void activate(Game *g, std::stringstream &ss) override;
};

#endif

