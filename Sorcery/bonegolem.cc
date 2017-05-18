#include "bonegolem.h"

using namespace std;

BoneGolem::BoneGolem()
	: TriggerMinion{3, 1, 0, false, "Bone Golem", 2,
	"Gain +1/+1 whenever a minion leaves play."}{}

BoneGolem::~BoneGolem(){};

void BoneGolem::notify(Game *g){
}

Trigger BoneGolem::getTrigger(){
	return Trigger::Leave;
}


