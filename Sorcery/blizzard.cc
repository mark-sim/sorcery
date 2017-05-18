#include "blizzard.h"
#include <iostream>
#include "abstractminion.h"
using namespace std;

Blizzard::Blizzard()
	: AbstractSpell("Blizzard", 3, "Deal 2 damage to all minions"){}

Blizzard::~Blizzard(){}

// deal_damage(Player *p, int damage)
// decreases all minions', on the board, defense by some integer, damage.
void deal_damage(Player *p, int damage){
	Board *b = p->getBoard();
	int count = b->getMinionCount();
	Card *minion = nullptr;
	int minion_def;
	for (int i = 0; i < count; ++i){
		minion = b->getMinion(i+1);
		minion_def = minion->getDef();		
		minion->setDef(minion_def - damage);
	} // for
} // deal_damage

void Blizzard::play(Game *g, int i, stringstream &ss){
	Player *ap = g->getAP();
	Player *nap = g->getNAP();

	if(ap->getMP() >= this->getCost() || g->getTesting()){
		deal_damage(ap, 2);
		deal_damage(nap, 2);
		ap->changeMP(-3,g->getTesting());
		ap->getBoard()->checkDead(g);
		nap->getBoard()->checkDead(g);
	}
	else{
		throw "not enough Magic points!";
	}
	
} // play


