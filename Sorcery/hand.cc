#include "hand.h"
#include <iostream>
using namespace std;

Hand::Hand(Deck deck) : deck{deck} {
	for(int i=0; i<5; i++) {
		this->Draw();
	}
}

Hand::Hand() {}

void Hand::Draw() {
	if(this->handSize < this->maxSize) {
		try {
			this->cards.emplace_back(deck.Top());
			this->handSize++;
		} catch(...) {
			cout << "no more cards" << endl;
			//no more cards
		}
	}
}
 
void Hand::display() {
	vector<card_template_t> toPrint;
	for(int i=0; i<handSize; i++) {
		Card *print = this->cards[i];
		vector<card_template_t> temp = print->display(print->getAtt(), print->getDef(), print->getActCost());
		toPrint.emplace_back(temp[0]);
	}

	for(int i=0; i<11; i++) {
                        for(int j=0; j<toPrint.size(); j++) {
                                cout << toPrint[j][i];
                        }
                        cout << endl;
        }
	
		
}


Card *Hand::playHand(int i) {
	if(i<=this->handSize && i>=1) {
	 	return this->cards[i-1];
	} else {
		throw "indexOutOfBound";
	}
}

void Hand::addToHand(Card *card) {
	this->cards.emplace_back(card);
	this->handSize++;
}

void Hand::sort(int i) {
	vector<Card *> sortedCards;
	int j = 0;
	while(j<this->handSize) {
		if(j != i) {
			sortedCards.emplace_back(this->cards[j]);
		}
		j++;
	}
	this->cards = sortedCards;
	this->handSize--;	
}

int Hand::getHandSize() {
	return this->handSize;
}

void Hand::discard(int i){
	Card *temp = this->cards[i];
	this->sort(i);
	delete temp;
} 	
