#include "board.h"
#include "subject.h"
#include "card.h"
#include "player.h"
#include <iostream>
#define SIMPLE_GRAPHICS = 0;
using namespace std;

Board::Board() {
	this->subject = new Subject();
}

Board::~Board() {
	delete this->subject;
}

Card *Board::getRitual() {
	return this->ritual;
}

void Board::displayA(Player *player) {
	vector<card_template_t> toPrint;
	cout << "═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════" << endl;
	
	
	if(this->ritual) {
		card_template_t print = display_ritual(this->ritual->getName(), 
					this->ritual->getCost(), this->ritual->getActCost(),
					this->ritual->getDesc(), this->ritual->getCharge());					
		toPrint.emplace_back(print);
	} else { 
		toPrint.emplace_back(CARD_TEMPLATE_BORDER);
	}
	card_template_t empty = display_empty_box();
	toPrint.emplace_back(empty);

	card_template_t print = display_player_card(1,player->getName(),player->getHP(),player->getMP());
	toPrint.emplace_back(print);
	
	toPrint.emplace_back(empty);		
	if(graveyard.getGraveyardSize() > 0) {
		Card *graveyardCard = graveyard.top();
		vector<card_template_t> toprint = graveyardCard->display(graveyardCard->getAtt(), graveyardCard->getDef(), graveyardCard->getActCost());	
		toPrint.emplace_back(toprint[0]);
	} else {
		toPrint.emplace_back(CARD_TEMPLATE_BORDER);
	}
	for(int i=0; i<11; i++) {
                        for(int j=0; j<toPrint.size(); j++) {
                                cout << toPrint[j][i];
                        }
                        cout << endl;
        }	

	toPrint.clear();

	for(int i=0; i<this->minionCount; i++) {
		Card *minion = this->listOfMinion[i];
		vector<card_template_t> toprint = minion->display(minion->getAtt(), minion->getDef(), minion->getActCost());
		toPrint.emplace_back(toprint[0]);
	}

	for(int i=0; i< 5 - this->minionCount; i++) {
		toPrint.emplace_back(CARD_TEMPLATE_BORDER);
	}

	for(int i=0; i<11; i++) {
		for(int j=0; j<toPrint.size(); j++) {
			cout << toPrint[j][i];
		}
		cout << endl;
	}

	for (auto i : CENTRE_GRAPHIC) {
		cout << i << endl;
	}

	

	
}

void Board::displayB(Player *player) {
	vector<card_template_t> toPrint;

        for(int i=0; i<this->minionCount; i++) {
                Card *minion = this->listOfMinion[i];
                vector<card_template_t> toprint = minion->display(minion->getAtt(), minion->getDef(), minion->getActCost());
                toPrint.emplace_back(toprint[0]);
        }

        for(int i=0; i< 5 - this->minionCount; i++) {
                toPrint.emplace_back(CARD_TEMPLATE_BORDER);
        }

        for(int i=0; i<11; i++) {
                for(int j=0; j<toPrint.size(); j++) {
                        cout << toPrint[j][i];
                }
                cout << endl;
        }

	toPrint.clear();

	
        if(this->ritual) {
                card_template_t print = display_ritual(this->ritual->getName(), 
                                        this->ritual->getCost(), this->ritual->getActCost(),
                                        this->ritual->getDesc(), this->ritual->getCharge());                                    
                toPrint.emplace_back(print);
        } else { 
                toPrint.emplace_back(CARD_TEMPLATE_BORDER);
  	}
        card_template_t empty = display_empty_box();
        toPrint.emplace_back(empty);

        card_template_t print = display_player_card(2,player->getName(),player->getHP(),player->getMP());
        toPrint.emplace_back(print);

        toPrint.emplace_back(empty);
        if(graveyard.getGraveyardSize() > 0) {
                Card *graveyardCard = graveyard.top();
                vector<card_template_t> toprint = graveyardCard->display(graveyardCard->getAtt(), graveyardCard->getDef(), graveyardCard->getActCost());
                toPrint.emplace_back(toprint[0]);
        } else {
                toPrint.emplace_back(CARD_TEMPLATE_BORDER);
        }
        for(int i=0; i<11; i++) {
                        for(int j=0; j<toPrint.size(); j++) {
                                cout << toPrint[j][i];
                        }
                        cout << endl;
        }

	cout << "═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════" << endl;
}

void Board::removeFromBoard(int i) {
	this->listOfMinion[i] = nullptr;
}

void Board::setMinion(Card *card, int i) {
	this->listOfMinion[i] = card;
}

Card *Board::getMinion(int i) {
	return this->listOfMinion[i-1];
}

void Board::playMinion(Card *card, Game *g) {
	if(this->minionCount < this->MAX_MINION) {
		this->listOfMinion.emplace_back(card);
		this->minionCount++;
		this->subject->notifyObservers(Trigger::Enter, g);
		this->subject->attach(card);
	}
}

void Board::playRitual(Card *ritual) {
	this->subject->attach(ritual);
	if(!this->ritual) {
		this->ritual = ritual;
	} else {
		delete this->ritual;
		this->ritual = ritual;
	}
}

int Board::getMinionCount() {
	return this->minionCount;
}


void Board::checkDead(Game *game) {
	for(int i=0; i<this->minionCount; i++) {
		if(this->listOfMinion[i]) {
			int def = this->listOfMinion[i]->getDef();
			if(def <= 0) {
				Card *originalMinion = this->listOfMinion[i]->getOriginalCard();
				if(originalMinion) {
					originalMinion->setDef(def);
					Card *toBeDeleted = this->listOfMinion[i];
					this->listOfMinion[i] = originalMinion;
					delete toBeDeleted;
				}
				this->graveyard.push(this->listOfMinion[i]);
				this->subject->detach(this->listOfMinion[i]);
				this->subject->notifyObservers(Trigger::Leave, game);
				this->listOfMinion[i] = nullptr;
			}
		}
	}
		
	for(int i=0; i<this->minionCount; i++) {
		if(!this->listOfMinion[i]) {
			this->listOfMinion.erase(this->listOfMinion.begin() + i);
		}
	}

	this->minionCount = this->listOfMinion.size();
		
}

Graveyard *Board::getGraveyard() {
	return &this->graveyard;
}

void Board::sendToGraveyard(int index) {
	
	this->graveyard.push(this->listOfMinion[index-1]);
	this->listOfMinion[index-1] = nullptr;
	for(int i=0; i<this->minionCount; i++) {
                if(this->listOfMinion[i]) {
                        int def = this->listOfMinion[i]->getDef();
                        if(def <= 0) {
                                Card *originalMinion = this->listOfMinion[i]->getOriginalCard();
                                if(originalMinion) {
                                        originalMinion->setDef(def);
                                        Card *toBeDeleted = this->listOfMinion[i];
                                        this->listOfMinion[i] = originalMinion;
                                        delete toBeDeleted;
                                }
                                this->graveyard.push(this->listOfMinion[i]);
                                this->listOfMinion[i] = nullptr;
                        }
                }
        }

        for(int i=0; i<this->minionCount; i++) {
                if(!this->listOfMinion[i]) {
                        this->listOfMinion.erase(this->listOfMinion.begin() + i);
                }
        }

        this->minionCount = this->listOfMinion.size();
}

Subject *Board::getSubject() {
	return this->subject;
}
