#include "fireelemental.h"

using namespace std;

FireElemental::FireElemental()
	: TriggerMinion{2, 2, 0, false, "Fire Elemental", 2,
	"Whenever an opponent's minion enters play, deal 1 damage to it."}{}

FireElemental::~FireElemental(){};

void FireElemental::notify(Game *g){}

Trigger FireElemental::getTrigger(){
	return Trigger::Enter;
}



