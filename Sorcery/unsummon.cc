#include "unsummon.h"
#include <vector>
using namespace std;

Unsummon::Unsummon()
	: AbstractSpell("Unsummon", 1,
		"Return target minion to its owner's hand"){}

Unsummon::~Unsummon(){}


void Unsummon::play(Game *g, int i, stringstream &ss ){
	Player *ap = g->getAP();
	Player *nap = g->getNAP();
	int target_player;
	int target_minion;
	Card *minion;
	if(ap->getMP() >= this->getCost()|| g->getTesting()){
		ss >> target_player;
		if(ss.fail()) {
			ss.clear();
			cin >> target_player;
		}
		if(target_player == g->getAP()->getPlayerNumber()){
			Board *b1 = ap->getBoard();
			Hand *h1 = ap->getHand();
			ss >> target_minion;
			if(ss.fail()) {
				ss.clear();
				cin >> target_minion;
			}
			Card *originalMinion = b1->getMinion(target_minion)->getOriginalCard();
			int defOriginal = -10;
			if(originalMinion) {
				defOriginal = originalMinion->getDef();
			}
			minion = b1->getMinion(target_minion);
			int defEnchanted = minion->getDef();
			if (h1->getHandSize() >= 5){
				throw "players hand is full!";
			} // if
			else{
				if(defOriginal != -10) {
					if(defOriginal <= defEnchanted) {
						originalMinion->setDef(defOriginal);
					} else {
						originalMinion->setDef(defEnchanted);
					}
					h1->addToHand(originalMinion);
					delete minion;
					b1->getSubject()->detach(originalMinion);
                                	b1->getSubject()->notifyObservers(Trigger::Leave, g);
				} else {		
					h1->addToHand(minion);
					b1->getSubject()->detach(minion);
                                        b1->getSubject()->notifyObservers(Trigger::Leave, g);
				}
				b1->removeFromBoard(target_minion-1);
				ap->changeMP(-1,g->getTesting());
				b1->checkDead(g);
			} // else

		} // if
		else if (target_player == g->getNAP()->getPlayerNumber()){
			Board *b2 = nap->getBoard();
			Hand *h2 = nap->getHand();
			ss >> target_minion;
			if(ss.fail()) {
				ss.clear();
				cin >> target_minion;
			}
			Card *originalMinion = b2->getMinion(target_minion)->getOriginalCard();
                        int defOriginal = -10;
                        if(originalMinion) {
                                defOriginal = originalMinion->getDef();
                        }
			minion = b2->getMinion(target_minion);
			int defEnchanted = minion->getDef();
			if (h2->getHandSize() >= 5){
				throw "players hand is full!";
			} // if
			else{
				if(defOriginal != -10) {
                                        if(defOriginal <= defEnchanted) {
                                                originalMinion->setDef(defOriginal);
                                        } else {
                                                originalMinion->setDef(defEnchanted);
                                        }
                                        h2->addToHand(originalMinion);
                                        delete minion;
					b2->getSubject()->detach(originalMinion);
                                        b2->getSubject()->notifyObservers(Trigger::Leave, g);
                                } else {
					h2->addToHand(minion);
					b2->getSubject()->detach(originalMinion);
                                        b2->getSubject()->notifyObservers(Trigger::Leave, g);
				}
				b2->removeFromBoard(target_minion-1);
                                ap->changeMP(-1,g->getTesting());
                                b2->checkDead(g);
			} // else
		} // else if
		else{
			throw "invaild target player. choose either 1 or 2 for choosing a player.";
		} // else
	}
	else{
		throw "not enough Magic points!";
	} // else
}


