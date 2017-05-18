#ifndef _NOVICEPYROMANCER_H_
#define _NOVICEPYROMANCER_H_

#include "activationminion.h"

class NovicePyromancer : public ActivationMinion {
	public:
		NovicePyromancer();
		~NovicePyromancer() override;
		void activate(Game *g, std::stringstream &ss) override;
};

#endif

