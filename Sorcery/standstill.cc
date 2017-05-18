#include "standstill.h"

using namespace std;

StandStill::StandStill():
	AbstractRitual{"Standstill", 3,
			"Whenever a minion enters play, destroy it",
			4, 2, Trigger::Enter}{}

void StandStill::notify(Game *game){
	
}



