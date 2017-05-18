#include "card.h"
#include "graveyard.h"
#include <iostream>
using namespace std;

Card *Graveyard::top() {
	return this->graveyard[this->graveyardSize-1];
}


Card *Graveyard::pop() {
	this->graveyardSize--;
	Card *toReturn = this->graveyard[this->graveyardSize];
	toReturn->setDef(1);
	this->graveyard[this->graveyardSize] = nullptr;
	sort(this->graveyardSize);
	return toReturn;
}

void Graveyard::sort(int i) {
        vector<Card *> sortedGraveyard;
        int j = 0;
        while(j<this->graveyardSize) {
                if(j != i) {
                        sortedGraveyard.emplace_back(this->graveyard[j]);
                }
                j++;
        }
        this->graveyard = sortedGraveyard;
 	
}

void Graveyard::push(Card *card) {
	this->graveyard.emplace_back(card);
	this->graveyardSize++;
}

int Graveyard::getGraveyardSize() {
	return this->graveyardSize;
}
