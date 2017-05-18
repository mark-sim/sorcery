#ifndef SUBJECT_H
#define SUBJECT_H

#include "card.h"
#include "game.h"
#include "trigger.h"
#include <vector>

class Subject{
	std::vector<Card *> observers;
	int observerSize = 0;
	public:
	Subject();
	~Subject();
	void attach(Card *obs);
	void detach(Card *obs);
	
	void notifyObserversNAP(Trigger trigg, Game *game);
	void notifyObservers(Trigger trigg, Game *game);
};//end of class Subject

#endif

