#include "disenchant.h"

using namespace std;

Disenchant::Disenchant()
	: AbstractSpell("Disenchant", 1, 
		"Destroy the top enchantment on target minion"){}; 

Disenchant::~Disenchant(){}

void Disenchant::play(Game *g, int i, stringstream &ss){
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
			ss >> target_minion;
			if(ss.fail()) {
				ss.clear();
				cin >> target_minion;
			}
			Card *originalMinion = b1->getMinion(target_minion)->getOriginalCard();
			int defOriginal = -10;
			if(originalMinion) {
				defOriginal = originalMinion->getDef();
			} else {
				throw "this isn't a enchanted minion";
			}
			minion = b1->getMinion(target_minion);
			int defEnchanted = minion->getDef();
			if(defOriginal != -10) {
				if(defOriginal <= defEnchanted) {
					originalMinion->setDef(defOriginal);
				} else {
					originalMinion->setDef(defEnchanted);
				}
				b1->setMinion(originalMinion, target_minion-1);
				delete minion;
			}
			ap->changeMP(-1,g->getTesting());

		} // if
		else if (target_player == g->getNAP()->getPlayerNumber()){
			Board *b2 = nap->getBoard();
			ss >> target_minion;
                        if(ss.fail()) {
                                ss.clear();
                                cin >> target_minion;
                        }
                        Card *originalMinion = b2->getMinion(target_minion)->getOriginalCard();
                        int defOriginal = -10;
                        if(originalMinion) {
                                defOriginal = originalMinion->getDef();
                        } else {
                                throw "this isn't a enchanted minion";
                        }
                        minion = b2->getMinion(target_minion);
                        int defEnchanted = minion->getDef();
                        if(defOriginal != -10) {
                                if(defOriginal <= defEnchanted) {
                                        originalMinion->setDef(defOriginal);
                                } else {
                                        originalMinion->setDef(defEnchanted);
                                }
                                b2->setMinion(originalMinion, target_minion-1);
                                delete minion;
                        }
                        ap->changeMP(-1,g->getTesting());
		} // else if
		else{
			throw "invaild target player. choose either 1 or 2 for choosing a player.";
		} // else
	}
	else{
		throw "not enough Magic points!";
	} // else
}
