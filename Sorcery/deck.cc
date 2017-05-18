#include "deck.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Deck::Deck(vector<Card *> cards, bool testingOn){
	if(!testingOn) {
		vector<Card *> randomized;
		int length = cards.size();
		while(length > 0) {
			int randomNumber = rand() % length;
			randomized.emplace_back(cards[randomNumber]);
			cards.erase(cards.begin() + randomNumber);
			length = cards.size();
		}	
		this->cards = randomized;
	} else {
		this->cards = cards;
	}

}

Deck::Deck() {
}

Deck::~Deck(){}

Deck& Deck::operator=(const Deck &other) {
	this->cards = other.cards;
	return *this;
}

Card *Deck::Top() {
	if(this->cards.size() == 0) {
		throw "error";
	}
	Card *temp = this->cards[0];
	this->cards.erase(cards.begin());
	return temp;
}


