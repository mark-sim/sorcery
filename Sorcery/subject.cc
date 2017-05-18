#include "subject.h"
using namespace std;

Subject::Subject() {
}

Subject::~Subject() {}

void Subject::attach(Card *obs) {
	this->observers.emplace_back(obs);
	this->observerSize++;
}

void Subject::detach(Card *obs) {
	for(int i =0; i<this->observerSize; i++) {
		if(obs == this->observers[i]) {
			this->observers.erase(this->observers.begin() + i);
			this->observerSize--;
			break;
		}
	}
}

void Subject::notifyObservers(Trigger trigg, Game *game) {
	for(int i =0; i<this->observerSize; i++) {
		if(this->observers[i]->getTrigger() == trigg) {
			
			this->observers[i]->notify(game);
		}
	}
	for(int i=0; i<this->observerSize; i++) {
		if(this->observers[i]->getName() == "Bone Golem") {
			cout << "bone golem worked" << endl;
			notifyObserversNAP(trigg,game);
		} else if (this->observers[i]->getName() == "Fire Elemental") {
			notifyObserversNAP(trigg,game);
		} else if (this->observers[i]->getName() == "Aura of Power") {
			notifyObserversNAP(trigg,game);
		} else if (this->observers[i]->getName() == "Standstill") {
			notifyObserversNAP(trigg,game);
		}
	}

}

void Subject::notifyObserversNAP(Trigger trigg, Game *game) {
	for(int i =0; i<this->observerSize; i++) {
                if(this->observers[i]->getTrigger() == trigg) {
                        this->observers[i]->notify(game);
                }
        }
}	


