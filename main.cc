#include <iostream>
#include <string>
#include <stdexcept>
#include "cell.h"
#include "map.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "shade.h"

using namespace std;

class Map;

static Dir corredir(string dir) {
	if (dir == "no") {
		return Dir::no;
	} else if (dir == "so") {
		return Dir::so;
	} else if (dir == "ea") {
		return Dir::ea;
	} else if (dir == "we") {
		return Dir::we;
	} else if (dir == "ne") {
		return Dir::ne;
	} else if (dir == "nw") {
		return Dir::nw;
	} else if (dir == "se") {
		return Dir::se;
	} else if (dir == "sw") {
		return Dir::sw;
	}
}

int main () {
	//Start a new game
	cout << "Starting the game, please wait." << endl;
	string hero;
	bool notgenerated = true;
	Map* mygame = new Map {};
	while(notgenerated) {
		cout << "Chose Your Hero: Shade(s)  Drow(d)  Vampire(v)  Troll(t)  Goblin(g)" << endl;
		getline(cin,hero);
		if (hero == "s") {
			mygame->changehero(0);
			notgenerated = false;
		} else if (hero == "d") {
			mygame->changehero(1);
			notgenerated = false;
		} else if (hero == "v") {
			mygame->changehero(2);
			notgenerated = false;
		} else if (hero == "t") {
			mygame->changehero(3);
			notgenerated = false;
		} else if (hero == "g") {
			mygame ->changehero(4);
			notgenerated = false;
		} else {
			cout << "Choose Your Hero again: Shade(s)  Drow(d)  Vampire(v)  Troll(t)  Goblin(g)"  << endl;
		}
	}
	bool freeze = false;
	mygame->printmap();

	//Start to play game
	string cmd;
	while (cin >> cmd) {
		//stand for successful action
		bool saction = false;
		if (cmd == "nw"||cmd == "no"||cmd == "ne"||
				cmd == "ea"||cmd == "se"||cmd == "so"||
				cmd == "sw"||cmd == "we") {
			Dir direction = corredir(cmd);
			saction = mygame->movePC(direction);
		} else if (cmd == "u") {
			cin >> cmd;
			 if (cmd == "nw"||cmd == "no"||cmd == "ne"||
                                cmd == "ea"||cmd == "se"||cmd == "so"||
                                cmd == "sw"||cmd == "we") {
			Dir direction = corredir(cmd);
			saction = mygame->use(direction);
			}
		} else if (cmd == "a"){
				cin >> cmd;
				 if (cmd == "nw"||cmd == "no"||cmd == "ne"||
                                cmd == "ea"||cmd == "se"||cmd == "so"||
                                cmd == "sw"||cmd == "we") {
				Dir direction = corredir(cmd);
				saction = mygame->attack(mygame->PCpos, direction);
				}
		} else if (cmd == "r") {
			cout << "Restarting the game, please wait." << endl;
			notgenerated = true;
			while(notgenerated) {
				cout << "Chose Your Hero: Shade(s)  Drow(d)  Vampire(v)  Troll(t)  Goblin(g)" << endl;
				cin >> hero;
				if (hero == "s") {
					delete mygame;
					mygame = new Map{0, 0, true, nullptr};
					notgenerated = false;
				} else if (hero == "d") {
					delete mygame;
					mygame = new Map{0, 1, true, nullptr};
					notgenerated = false;
				} else if (hero == "v") {
					delete mygame;
					mygame = new Map{0, 2, true, nullptr};
					notgenerated = false;
				} else if (hero == "t") {
					delete mygame;
					mygame = new Map{0, 3, true, nullptr};
					notgenerated = false;
				} else if (hero == "g") {
					delete mygame;
					mygame = new Map{0, 4, true, nullptr};
					notgenerated = false;
				} else {
					cout << "Choose Your Hero again: Shade(s)  Drow(d)  Vampire(v)  Troll(t)  Goblin(g)" << endl;
				}
		}
			freeze = false;
			 mygame->printmap();
			continue;
		} else if (cmd == "f") {
			saction = true;
			if(freeze) {
				freeze = false;	
			} else {
				freeze = true;
			}
		} else if (cmd == "q") {
			cout << "DEFEAT!!!" << endl;
			cout << "Your Score: " << mygame->gethero()->get_stat().Gold << endl;
			delete mygame;
			break;
		} else {
			cout << "Give me a valid command" << endl;
			continue;
		}

		if (!saction) {
			cout << "You action is illegal, try another action" << endl;
			continue;
		} else {
			if (mygame->nextfloor() && mygame->lastfloor()) {
				cout<< "VICTORY!" << endl;
				delete mygame;
				break;
			} else if (mygame->nextfloor()) {
				int floor = mygame->getfloor() + 1;
				int type = mygame->getherotype();
				Hero* temp = mygame->gethero();
				Stat temp1 = temp->get_stat();
				if (type == 0) {
				Hero* temp2 = new Shade {temp1.max_HP, temp1.HP, temp1.Atk, temp1.Def, temp1.extra_Atk, temp1.extra_Def, temp1.Gold};
				delete mygame;
                                mygame = new Map {floor, type, false, temp2};
				} else if (type == 1) {
				 Hero* temp2 = new Drow{temp1.max_HP, temp1.HP, temp1.Atk, temp1.Def, temp1.extra_Atk, temp1.extra_Def, temp1.Gold};
				delete mygame;
                                mygame = new Map {floor, type, false, temp2};
				} else if (type == 2) {
				 Hero* temp2 = new Vampire {temp1.max_HP, temp1.HP, temp1.Atk, temp1.Def, temp1.extra_Atk, temp1.extra_Def, temp1.Gold};
				delete mygame;
                                mygame = new Map {floor, type, false, temp2};
				} else if (type == 3) {
				 Hero* temp2 = new Troll {temp1.max_HP, temp1.HP, temp1.Atk, temp1.Def, temp1.extra_Atk, temp1.extra_Def, temp1.Gold};
				delete mygame;
                                mygame = new Map {floor, type, false, temp2};
				} else {
				 Hero* temp2 = new Goblin {temp1.max_HP, temp1.HP, temp1.Atk, temp1.Def, temp1.extra_Atk, temp1.extra_Def, temp1.Gold};
				delete mygame;
                                mygame = new Map {floor, type, false, temp2};}
			} else if (!freeze) {
				mygame->enemyround();
			}
		}
		if (mygame->getherotype() == -10) {
		cout << "DEFEAT!!!" << endl;
		cout << "Your Score: " << mygame->gethero()->get_stat().Gold << endl;
		delete mygame;
		break;
		}
		mygame->printmap();
	}
}


