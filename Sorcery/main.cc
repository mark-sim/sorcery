#include "includelist.h"

using namespace std;
Deck load_deck(string deckName, bool testing_on){
	ifstream deck_name(deckName);
	string card_name;
	vector<Card *> cards;
	while (getline(deck_name, card_name)){
		if(card_name == "Air Elemental"){
			AirElemental *airelemental = new AirElemental();
			cards.emplace_back(airelemental);            
		} else if(card_name == "Earth Elemental"){
			EarthElemental *earthelemental = new EarthElemental();
			cards.emplace_back(earthelemental);
		} else if (card_name == "Banish") {
			Banish *banish = new Banish();
			cards.emplace_back(banish);
		} else if (card_name == "Raise Dead") {
			RaiseDead *raisedead = new RaiseDead();
			cards.emplace_back(raisedead);	
		} else if (card_name == "Blizzard") {
			Blizzard *blizzard = new Blizzard();
			cards.emplace_back(blizzard);
		} else if (card_name == "Unsummon") {
			Unsummon *unsummon = new Unsummon();
			cards.emplace_back(unsummon);
		} else if (card_name == "Giant Strength") {
			GiantStrength *giantstrength = new GiantStrength();
			cards.emplace_back(giantstrength);
		} else if (card_name == "Enrage") {
			Enrage *enrage = new Enrage();
			cards.emplace_back(enrage);
	        } else if (card_name == "Haste") {
            		Haste *haste = new Haste();
            		cards.emplace_back(haste);
       		 } else if (card_name == "Magic Fatigue") {
            		MagicFatigue *magicfatigue = new MagicFatigue();
       		        cards.emplace_back(magicfatigue);
        	} else if (card_name == "Silence") {
       		        Silence *silence = new Silence();
            	   	cards.emplace_back(silence);
        	} else if (card_name == "Apprentice Summoner"){
                        ApprenticeSummoner *a_summoner = new ApprenticeSummoner();
                        cards.emplace_back(a_summoner);
                } else if (card_name == "Master Summoner"){
                        MasterSummoner *m_summoner = new MasterSummoner();
                        cards.emplace_back(m_summoner);
                } else if (card_name == "Novice Pyromancer"){
                        NovicePyromancer *n = new NovicePyromancer();
                        cards.emplace_back(n);
                } else if (card_name == "Recharge") {
			Recharge *recharge = new Recharge();
			cards.emplace_back(recharge);
		} else if (card_name == "Dark Ritual") {
			DarkRitual *darkritual = new DarkRitual();
			cards.emplace_back(darkritual);
		} else if (card_name == "Standstill") {
			StandStill *standstill = new StandStill();
			cards.emplace_back(standstill);
		} else if (card_name == "Aura of Power") {
			AuraOfPower *auraofpower = new AuraOfPower();
			cards.emplace_back(auraofpower);
		} else if (card_name == "Bone Golem") {
			BoneGolem *b = new BoneGolem();
			cards.emplace_back(b);
		} else if (card_name == "Fire Elemental") {
			FireElemental *f = new FireElemental();
			cards.emplace_back(f);
		} else if (card_name == "Potion Seller") {
			PotionSeller *p = new PotionSeller();
			cards.emplace_back(p);
		} else if (card_name == "Disenchant") {
			Disenchant *p = new Disenchant();
			cards.emplace_back(p);
		}

	//	cards.emplace_back(Card(card_name));
	}
	Deck deck(cards, testing_on);
	return deck;
}
int main(int argc, char* argv[]){
	srand(time(nullptr));
	bool testing_on = false;
	int inspect_num;
	stringstream ss;
	string cmd;
	string initialAPname = "";
	string initialNAPname = "";
	string deck1_filename = "default.deck";
	string deck2_filename = "default.deck";

	int winner = 0;
	for (int index = 1; index < argc; index++){
		string temp = argv[index];
		if (temp == "-deck1" ) {
			cout << argv[index];
			index++;
			deck1_filename = argv[index];
		} // if
		else if (temp == "-deck2") {
			cout << argv[index];
			index++;
			deck2_filename = argv[index];
		} // else if
		else if (temp == "-init") {
			cout << argv[index];
			index++; //increment to the filename index
			ifstream initFile{argv[index]};
			// initialize initFile with the filename from argv[index]
			string word;
			while (initFile >> cmd) {
				word += cmd + " ";
			} // while
			ss.str(word);
			while (initialNAPname == "") {
				ss >> cmd;
				if (ss.eof()) break; 
				if (initialAPname == "") {
					initialAPname = cmd;
				} // if
				else {
					initialNAPname = cmd;
				} // else
			} // while
		} // else if
		else if (temp == "-testing") {
			cout << argv[index];
			testing_on = true;
		} // else if
		else if (temp == "-graphics") {
			cout << argv[index];
		} // else if
			cout << endl;
	} //end of for

	//Load decks for players
	Deck deck1{load_deck(deck1_filename,testing_on)};
	Deck deck2{load_deck(deck2_filename,testing_on)};	

	if (initialAPname == "") {
		cout << "Please enter Initial AP Name :" << endl;
		cin >> initialAPname;
	} // if
	if (initialNAPname == "") {
		cout << "Please enter Initial NAP Name :" << endl;
		cin >> initialNAPname;
	} // if
	
	cout << "InitialAP Name:" << initialAPname << endl;
	cout << "InitialNAP Name:" << initialNAPname << endl;
	Player initialAP{initialAPname,Hand{deck1},1};
	Player initialNAP{initialNAPname,Hand{deck2},2};
	Game g{&initialAP,&initialNAP};
	g.setTesting(testing_on);
	
	while (true) {
		//check if any players have 0 health
		//if so declare winner and exit game loop
		if (g.getAP()->getHP() <= 0){
			winner = g.getNAP()->getPlayerNumber();
			break;
		}
		else if (g.getNAP()->getHP() <= 0){
			winner = g.getAP()->getPlayerNumber();
			break;
		}



		//Check if init has commands left in ss
		ss >> cmd;
		if (ss.fail()) {
	            ss.clear();
		    cin >> cmd;
		} // if

		//main game loopo
		if (cmd == "help") {
			g.help();
		} // if
		else if (cmd == "end") {
			g.getAP()->getBoard()->getSubject()->notifyObservers(Trigger::End, &g);
			g.changeTurn();
			g.getAP()->getBoard()->getSubject()->notifyObservers(Trigger::Start, &g);
			g.getAP()->Draw();
			g.getAP()->changeMP(1, g.getTesting());
			int count = g.getAP()->getBoard()->getMinionCount();
			for(int i=0; i<count; i++) {
				if(g.getAP()->getBoard()->getMinion(i+1)->getAct() == 0) {
					g.getAP()->getBoard()->getMinion(i+1)->setAct(1);
				}
			}	
		} // else if
		else if (cmd == "quit") {
			cout << "quit" << endl;
			break;
		} // else if
		else if (cmd == "attack") {
			int myMinionIndex = -1;
			int enemyMinionIndex = -1;
			string attackWho;
			ss >> myMinionIndex;
			if(ss.fail()) {
				ss.clear();
				getline(cin,attackWho);
				istringstream iss{attackWho};
				iss >> myMinionIndex;
				iss >> enemyMinionIndex;
			}
			ss >> enemyMinionIndex;
			if(ss.fail()) {
				ss.clear();
			}
			if(enemyMinionIndex == -1) {
				g.attack(myMinionIndex);
			} else {
				g.attack(myMinionIndex, enemyMinionIndex);
			}
	
		} // else if
		else if (cmd == "play") {
			int i;
			ss >> i;
			if(ss.fail()) {
				cin >> i;
			}
			g.play(i, ss);
		} // else if
		else if (cmd == "use") {
			int i;
			ss >> i;
                        if(ss.fail()) {
                                cin >> i;
                        }
			g.use(i, ss);
		} // else if
		else if (cmd == "inspect") {
			ss >> inspect_num;
                        if(ss.fail()) {
                                cin >> inspect_num;
                        }	
			g.inspect(inspect_num);
		} // else if
		else if (cmd == "hand") {
			g.displayHand();
		} // else if
		else if (cmd == "board"){
		    	g.displayBoard();
		} // else if
		else if (testing_on){
			//enabling testing flag enabled commands
			if ( cmd == "draw"){
				g.getAP()->Draw();
			}
			else if(cmd == "discard"){
				int discard_index = 0;
				ss >> discard_index;
                       	 	if(ss.fail()) {
                       	        	 cin >> discard_index;
                       		 }			

				//converting from user input to normal index
				discard_index --;
				g.getAP()->getHand()->discard(discard_index);
			}//end of if
		}//end of if
	}// while
	
	cout << "GAME OVER! PLAYER " << winner << " WON!";
} //end of main
