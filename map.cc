#include "map.h"
#include "unit.h"
#include "vampire.h"
#include "shade.h"
#include "merchant.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orcs.h"
#include "dragon.h"
#include "hoard_d.h"
#include "BA.h"
#include "RH.h"
#include "BD.h"
#include "PH.h"
#include "WA.h"
#include "WD.h"
#include "gold_s.h"
#include "gold_n.h"
#include "hoard_m.h"
#include "stair.h"
#include "wall.h"
#include "tile.h"
#include "passway.h"
#include "doorway.h"
#include "nothing.h"



using namespace std;


//Return a random position in chamber 0
static vector<int> randpos0() {
	srand((unsigned)time(NULL));
	int pos = rand() % 104;
	int row = pos / 26 + 3;
	int col = pos % 26 + 3;
	vector<int> temp = {row, col};
	return temp;
}

static vector<int> randpos1() {
	srand((unsigned)time(NULL));
	int pos = rand() % 147;
	int row = pos / 21 + 15;
	int col = pos % 21 + 4;
	vector<int> temp = {row, col};
	return temp;	
}

static vector<int> randpos2() {
	srand((unsigned)time(NULL));
	int pos = rand() % 36;
	int row = pos / 12 + 10;
	int col = pos % 12 + 38;
	vector<int> temp = {row, col};
	return temp;	
}

static vector<int> randpos3() {
	srand((unsigned)time(NULL));
	int pos = rand() % 150+ 0;
	int row= 0;
	int col= 0;
	if (pos <= 116) {
		row = pos / 39 + 19;
	        col  = pos % 39 + 37;
	} else {
		pos -= 117;
		row = pos / 11 + 16;
		col = pos % 11 + 65;
	}
	vector<int> temp = {row, col};
	return temp;
}

static vector<int> randpos4() {
	srand((unsigned)time(NULL));
	int pos = rand() % 201;
	int row;
	int col;
	if (pos <= 45) {
		row = pos / 23 + 3;
		col = pos % 23 + 39;
	} else if (pos <= 76) {
		pos -= 46;
		row = pos / 31 + 5;
		col = pos % 31 + 39;
	} else if (pos <= 110) {
		pos -= 77;
		row = pos / 34 + 6;
		col = pos % 34 + 39;
	} else {
		pos -= 111;
		row = pos / 15 + 7;
		col = pos % 15 + 61;
	}
	vector<int> temp = {row, col};
	return temp;
}

static Hero* makeHero(int hero) {
	if (hero == 0) {
		Shade *PC = new Shade{};
		return PC;
	} else if (hero == 1) {
		Drow* PC = new Drow{};
		return PC;
	} else if (hero == 2) {
		Vampire* PC = new Vampire{};
		return PC;
	} else if (hero == 3) {
		Troll* PC = new Troll{};
		return PC;
	} else {
		Goblin* PC = new Goblin{};
		return PC;
	}
}

void Map::changehero(int newtype) {
	delete grid.at(PCpos.at(0)).at(PCpos.at(1))->something;
	hero = makeHero(newtype);
	herotype = newtype;
	 grid.at(PCpos.at(0)).at(PCpos.at(1))->something = hero;
}
static Enemy* makeEnemy(int enemy) {
	if (enemy >= 0 && enemy <= 3) {
		Human* en = new Human{};
		return en;
	} else if (enemy >= 4 && enemy <= 6) {
		Dwarf* en = new Dwarf{};
		return en;
	} else if (enemy >=7 && enemy <= 11) {
		Halfling* en = new Halfling {};
		return en;
	} else if (enemy >= 12 && enemy <= 13) {
		Elf* en = new Elf{};
		return en; 
	} else if (enemy >= 14 && enemy <= 15) {
		Orcs* en = new Orcs{};
		return en;
	} else {
		Merchant* en = new Merchant{};
		return en;
	}
}

static Potion* makePotion(int drink) {
	if (drink == 0) {
		RH* magic = new RH{};
		return magic;
	} else if (drink == 1) {
		BA* magic = new BA{};
		return magic;
	} else if (drink == 2) {
		BD* magic = new BD{};
		return magic;
	} else if (drink == 3) {
		PH* magic = new PH{};
		return magic;
	} else if (drink == 4){
		WA* magic = new WA{};
		return magic;
	} else {
		WD* magic = new WD{};
		return magic;
	}
}

static Unit* makeGold(int Gold, bool* dragon) {
	if (Gold >= 0 && Gold <= 4) {
		Gold_n* G = new Gold_n{};
		return G;
	} else if (Gold >= 5 && Gold <= 6){
		Gold_s* G = new Gold_s{};
		return G;
	} else {
		*dragon = true;
		Hoard_d* G = new Hoard_d{}; //Make a dragon them make the Dragon Hoard.
		return G;
	}
}

static Dir convertdir(int direction) {
	if (direction == 0) {
		return Dir::nw;
	} else if (direction == 1) {
		return Dir::no;
	} else if (direction == 2) {
		return Dir::ne;
	} else if (direction == 3) {
		return Dir::ea;
	} else if (direction == 4) {
		return Dir::se;
	} else if (direction == 5) {
		return Dir::so;
	} else if (direction == 6) {
		return Dir::sw;
	} else if (direction == 7) {
		return Dir::we;
	}
}

static vector<int> nbpos(vector<int> mypos, Dir direction) {
	vector<int> toreturn;
	if (direction == Dir::nw) {
		toreturn = {mypos.at(0) - 1, mypos.at(1) - 1};
	} else if (direction == Dir::no) {
		toreturn = {mypos.at(0) - 1, mypos.at(1)};
	} else if (direction == Dir::ne) {
		toreturn = {mypos.at(0) - 1, mypos.at(1) + 1};
	} else if (direction == Dir::ea) {
		toreturn = {mypos.at(0), mypos.at(1) + 1};
	} else if (direction == Dir::se) {
		toreturn = {mypos.at(0) + 1, mypos.at(1) + 1};
	} else if (direction == Dir::so) {
		toreturn = {mypos.at(0) + 1, mypos.at(1)};
	} else if (direction == Dir::sw) {
		toreturn = {mypos.at(0) + 1, mypos.at(1) - 1};
	} else if (direction == Dir::we) {
		toreturn = {mypos.at(0), mypos.at(1) - 1};
	}
	return toreturn;
}

void Map::dropgold(int death, vector<int> gold_pos) {
	if (death == 2) {
		int amount = rand() % 2 + 1;
		Stat gold = {0, 0, 0, 0, 0, 0, amount};
		hero->change_Stat(gold);
	} else if (death == 3) {
		int row = gold_pos.at(0);
		int col = gold_pos.at(1);
		grid.at(row).at(col)->something = new Gold_n{};
		vector<int> nb0 = {row-1, col - 1};
		vector<int> nb1 = {row-1, col};
		vector<int> nb2 = {row-1, col + 1};
		vector<int> nb3 = {row, col + 1};
		vector<int> nb4 = {row+1, col + 1};
		vector<int> nb5 = {row+1, col};
		vector<int> nb6 = {row+1, col - 1};
		vector<int> nb7 = {row, col - 1};
		vector<vector<int>> neighbours = {nb0, nb1, nb2, nb3, nb4, nb5, nb6, nb7};
		bool notdrop = true;
		int i = 8;
		while (neighbours.size() > 0 && notdrop) {
			srand((unsigned)time(NULL));
			int pos = rand() % i;
			int n_row = neighbours.at(pos).at(0);
			int n_col = neighbours.at(pos).at(1);
			if (!grid.at(neighbours.at(pos).at(0)).at(neighbours.at(pos).at(1))->something && 
grid.at(neighbours.at(pos).at(0)).at(neighbours.at(pos).at(1))->dropto()) {
				grid.at(n_row).at(n_col)->something = new Gold_n{};
				notdrop = false;
			} else {
				neighbours.erase(neighbours.begin()+pos);
				--i;
			}
		}
		if (notdrop) {
			Stat gold = {0, 0, 0, 0, 0, 0, 2};
			hero->change_Stat(gold);
		}
	} else if (death == 4) {
		int row = gold_pos.at(0);
		int col = gold_pos.at(1);
		grid.at(row).at(col)->something = new Hoard_m{};
	}
}

void Map::putstair(int whichchamber, vector<vector<Cell*>> gird) {
	bool generated = false;
	vector<int> temp= {-1, -1};
	while(!generated) {
		if (whichchamber == 0){
			temp = randpos0();
		} else if (whichchamber == 1) {
			temp = randpos1();
		} else if (whichchamber == 2) {
			temp = randpos2();
		} else if (whichchamber == 3) {
			temp = randpos3();
		} else if (whichchamber == 4) {
			temp = randpos4();
		}
		int row = temp.at(0);
		int col = temp.at(1);
		if (!grid.at(row).at(col)->something) {
			Stair* temp2 = new Stair{};
			grid.at(row).at(col) = temp2;
			generated = true;
			rooms.at(whichchamber).stair = true;
			stairpos = {row, col};
		}
	}
}

bool Map::nextfloor() {
	return PCpos.at(0) == stairpos.at(0) && PCpos.at(1) == stairpos.at(1);
}

bool Map::lastfloor() {
	return floor == 4;
}

int Map::getfloor() {
	return floor;
}

int Map::getherotype(){
	return herotype;
}

Hero* Map::gethero(){
	return hero;
}

vector<int> Map::put(Unit* toput, int whichchamber, 
                       vector<vector<Cell*>> grid) {
	bool generated = false;
	vector<int> toreturn;
	while(!generated) {
		vector<int> temp = {0, 0};
		if (whichchamber == 0){
			temp = randpos0();
		} else if (whichchamber == 1) {
			temp = randpos1();
		} else if (whichchamber == 2) {
			temp = randpos2();
		} else if (whichchamber == 3) {
			temp = randpos3();
		} else if(whichchamber == 4) {
			temp = randpos4();
		}
		int row = temp.at(0);
		int col = temp.at(1);
		if (!grid.at(row).at(col)->something) {
			grid.at(row).at(col)->something = toput;
			toreturn = {row, col};
			generated = true;
		}
	}
	return toreturn;
}

bool Map::put_Dragon(Hoard_d* HD, vector<int> DH_pos, int whichchamber, vector<vector<Cell*>> grid) {
		int row = DH_pos.at(0);
		int col = DH_pos.at(1);
		vector<int> nb0 = {row-1, col - 1};
		vector<int> nb1 = {row-1, col};
		vector<int> nb2 = {row-1, col + 1};
		vector<int> nb3 = {row, col + 1};
		vector<int> nb4 = {row+1, col + 1};
		vector<int> nb5 = {row+1, col};
		vector<int> nb6 = {row+1, col - 1};
		vector<int> nb7 = {row, col - 1};
		vector<vector<int>> neighbours = {nb0, nb1, nb2, nb3, nb4, nb5, nb6, nb7};
		bool notdrop = true;
		int i = 8;
		while (neighbours.size() > 0 && notdrop) {
			srand((unsigned)time(NULL));
			int pos = rand() % i;
			int n_row = neighbours.at(pos).at(0);
			int n_col = neighbours.at(pos).at(1);
			if (!grid.at(neighbours.at(pos).at(0)).at(neighbours.at(pos).at(1))->something && 
grid.at(neighbours.at(pos).at(0)).at(neighbours.at(pos).at(1))->dropto()) {
				grid.at(n_row).at(n_col)->something = new Dragon(HD);
				notdrop = false;
				return true;
			} else {
				neighbours.erase(neighbours.begin()+pos);
				--i;
			}
		}
		return false;
}

//Constructor of Map
Map::Map(int floor, int newtype, bool newgame, Hero* oldhero): floor{floor}, width{79}, length{25}, herotype{herotype}, newgame{newgame} {
	
	//Readin all the empty map and determine the rooms.
	Chamber chamber0, chamber1, chamber2, chamber3, chamber4;
	
	vector<vector<int>> rect;

	vector<int> vtemp = {2, 2, 28, 6};
	rect.push_back(vtemp);
	chamber0 = {rect, false};
	rect.clear();
	
	vtemp = {14, 3, 23, 9};
	rect.push_back(vtemp);
	chamber1 = {rect, false};
	rect.clear();
	
	vtemp = {9, 37, 14, 5};
	rect.push_back(vtemp);
	chamber2 = {rect, false};
	rect.clear();
	
	vtemp = {18, 36, 41, 5};
	rect.push_back(vtemp);
	vtemp = {15, 64, 13, 3};
	rect.push_back(vtemp);
	chamber3 = {rect, false};
	rect.clear();
	
	vtemp = {2, 38, 25, 6};
	rect.push_back(vtemp);
	vtemp = {4, 63, 9, 4};
	rect.push_back(vtemp);
	vtemp = {5, 71, 4, 3};
	rect.push_back(vtemp);
	vtemp = {6, 74, 4, 2};
	rect.push_back(vtemp);
	vtemp = {8, 60, 17, 6};
	rect.push_back(vtemp);
	chamber4 = {rect, false};
	rect.clear();
        rooms = {chamber0, chamber1, chamber2, chamber3, chamber4};

	ifstream mapfile;
	mapfile.open("emptyfloor.txt");
	string line;
	for (int i = 0; i < 30; ++ i) {

		getline(mapfile, line);
		istringstream ss (line);

		vector<Cell* > aRow;
		grid.push_back(aRow);
		char construction;

		for (int j = 0; j < 79; ++j) {
			ss >> construction;
			if (construction == '|') {
				Wall* cur = new Wall {nullptr, false, true};
				grid.at(i).push_back(cur);
			} else if (construction == '-') {
				Wall* cur = new Wall {nullptr, false, false};
				grid.at(i).push_back(cur);
			} else if (construction == '.') {
				Tile* cur = new Tile {};
				grid.at(i).push_back(cur);
			} else if (construction == '#') {
				Passway* cur = new Passway {};
				grid.at(i).push_back(cur);
			} else if (construction == '+') {
				Doorway* cur = new Doorway {};
				grid.at(i).push_back(cur);
			} else {
				Nothing* cur = new Nothing {};
				grid.at(i).push_back(cur);
			}
		}
	}

	//We shall generate all the gold. potions and characters now. Also the stair
		srand((unsigned)time(NULL));
		int chamber = rand() % 5;
		//Generate the stair
		putstair(chamber, grid);
		//Generate the PC;
		bool Herogen = false;
		while (!Herogen){
			srand((unsigned)time(NULL));
			chamber = rand() % 5;
			if (!rooms.at(chamber).stair) {
				if(newgame){
					hero = makeHero(newtype);
					herotype = newtype;
					PCpos = put(hero, chamber, grid);
				} else {
					double max_HP = oldhero->get_stat().max_HP;
					double HP = oldhero->get_stat().HP;
					double Atk = oldhero->get_stat().Atk;
					double Def = oldhero->get_stat().Def;
					double extra_Def = oldhero->get_stat().extra_Def;
					double extra_Atk = oldhero->get_stat().extra_Atk;
					int Gold = oldhero->get_stat().Gold;
					Stat newone = {0, 0, 0, 0, -1*extra_Atk, -1* extra_Def, 0};
					
					oldhero->change_Stat(newone);
					hero = oldhero;
					herotype = newtype;
					PCpos = put(oldhero, chamber, grid);
				}
				newgame = false;
				Herogen = true;
			}
		}
		//Generate Potion;
		int potionleft = 10;
		while (potionleft > 0) {
			srand((unsigned)time(NULL));
			chamber = rand() % 5;
			srand((unsigned)time(NULL));
			int potion = rand() % 6;
			put(makePotion(potion), chamber, grid);
			--potionleft;
		}
		//Generate gold;
		int Goldleft = 10;
		while (Goldleft > 0) {
			srand((unsigned)time(NULL));
			chamber = rand() % 5;
			srand((unsigned)time(NULL));
			int Gold = rand() % 8;
			bool dragon = false;
			Gold_n* G1 = nullptr;
			Gold_s* G2 = nullptr;
			Hoard_d* HD = nullptr;
			if (Gold >= 0 && Gold <= 4) {
				delete G1;
				G1 = new Gold_n{};
			} else if (Gold >=5 && Gold <=6) {
				delete G2;
				G2 = new Gold_s{};
			} else {
				delete HD;
				HD = new Hoard_d{};
				dragon = true;
			}
			Unit* temp = makeGold(Gold, &dragon);
			if (dragon){
				vector<int> temp =  put(HD, chamber, grid);
				if(put_Dragon(HD, temp, chamber, grid)){
					grid.at(temp.at(0)).at(temp.at(1))->enemy = true;					--Goldleft;
				} else {}
			} else if (Gold >=5 && Gold <=6){
				put(G2, chamber, grid);
				--Goldleft;
			} else {
				put(G1, chamber, grid);
				--Goldleft;
			}
		}

		//Generate Enemy
		int Enemyleft = 20;
		while (Enemyleft > 0) {
			srand((unsigned)time(NULL));
			chamber = rand() % 5;
			srand((unsigned)time(NULL));
			int Enemy = rand() % 18;
			vector<int> temp = put(makeEnemy(Enemy), chamber, grid);
			grid.at(temp.at(0)).at(temp.at(1))->enemy = true;
			--Enemyleft;
		}
		result = "Play Character has spawned.";
}


Map::~Map() {
	for (int i = 0; i < length; ++i) {
		int j = 0;
		for (; j < width; ++j) {
		//	if (grid.at(i).at(j)->something) {
		//	delete grid.at(i).at(j)->something;
		//	}
			if (grid.at(i).at(j)) {
			delete grid.at(i).at(j);
			}	
		}
	}
}

void Map::changePCpos(Dir direction) {
	if (direction == Dir::nw) {
		--PCpos.at(0);
		--PCpos.at(1);
	} else if (direction == Dir::no) {
		--PCpos.at(0);
	} else if (direction == Dir::ne) {
		--PCpos.at(0);
		++PCpos.at(1);
	} else if (direction == Dir::ea) {
		++PCpos.at(1);
	} else if (direction == Dir::se) {
		++PCpos.at(0);
		++PCpos.at(1);
	} else if (direction == Dir::so) {
		++PCpos.at(0);
	} else if (direction == Dir::sw) {
		++PCpos.at(0);
		--PCpos.at(1);
	} else if (direction == Dir::we) {
		--PCpos.at(1);
	}
}
void Map::tellenemy(bool succeed) {
 if (succeed) {
                vector<int> nb;
                int notified[8] = {0};
                for (int i = 0; i < 8; ++i) {
                        nb = nbpos(PCpos, convertdir(i));
                        if (grid.at(nb.at(0)).at(nb.at(1))->something) {
                                notified[i] = grid.at(PCpos.at(0)).at(PCpos.at(1))->notify(grid.at(nb.at(0)).at(nb.at(1)));
                        }
                }
                for (int j = 0; j < 8; ++j) {
                        if (notified[j] == 1) {
                                nb = nbpos(PCpos, convertdir(j));
                                attack(nb, convertdir((j + 4)%8));
                        }
                }
        }
}



bool Map::movePC(Dir direction) {
	stringstream action;

	string dir;
	vector<int> nb = nbpos(PCpos, direction);

	if (direction == Dir::nw) {
		dir = "NorthWest";
	} else if (direction == Dir::no) {
		dir = "North";
	} else if (direction == Dir::ne) {
		dir = "NorthEast";
	} else if (direction == Dir::ea) {
		dir = "East";
	} else if (direction == Dir::se) {
		dir = "SouthEast";
	} else if (direction == Dir::so) {
		dir = "South";
	} else if (direction == Dir::sw) {
		dir = "SouthWest";
	} else if (direction == Dir::we) {
		dir = "West";
	}
	action << "PC moves " << dir;
	cout << action.str();
	bool succeed = grid.at(PCpos.at(0)).at(PCpos.at(1))->move(grid.at(nb.at(0)).at(nb.at(1)));

	if (succeed) {
		changePCpos(direction);
		int notified[8] = {0};
		for (int i = 0; i < 8; ++i) {
			nb = nbpos(PCpos, convertdir(i));
			if (grid.at(nb.at(0)).at(nb.at(1))->something) {
				notified[i] = grid.at(PCpos.at(0)).at(PCpos.at(1))->notify(grid.at(nb.at(0)).at(nb.at(1)));
			}
		}
		for (int j = 0; j < 8; ++j) {
			if (notified[j] == 1) {
				nb = nbpos(PCpos, convertdir(j));
				attack(nb, convertdir((j + 4)%8));
			} else if (notified[j] == 2 && convertdir(j) == direction) {
				nb = nbpos(PCpos, convertdir(j));
				action << " and sees a " << grid.at(nb.at(0)).at(nb.at(1))->print();
			}
		}
	}
	result += action.str();
	return succeed;
}

bool Map::use(Dir direction) {
	stringstream action;
	vector<int> nb = nbpos(PCpos, direction);
	bool succeed = grid.at(PCpos.at(0)).at(PCpos.at(1))->use(grid.at(nb.at(0)).at(nb.at(1)));
	if(succeed) {
		action << "PC uses " << grid.at(nb.at(0)).at(nb.at(1))->print();
		delete grid.at(nb.at(0)).at(nb.at(1))->something;
		 grid.at(nb.at(0)).at(nb.at(1))->something = nullptr; 
		tellenemy(succeed);
	}
	result += action.str();
	return succeed;
}

static int damage(Cell* attack, Cell* beattack) {
	double itsDef = beattack->something->get_stat().Def + beattack->something->get_stat().extra_Def;
  	double myAtk = attack->something->get_stat().Atk + attack->something->get_stat().extra_Atk;
  	int dam = ceil((100 / (100 + itsDef)) * myAtk);
  	return dam;
}

bool Map::attack(vector<int> pos, Dir direction) {
	stringstream action;
	if (pos.at(0) == PCpos.at(0) && pos.at(1) == PCpos.at(1)) {
	action.str("");
	}
        vector<int> nb = nbpos(pos, direction);
	double oldPC_HP = grid.at(PCpos.at(0)).at(PCpos.at(1))->something->get_stat().HP;
	double oldNB_HP = grid.at(nb.at(0)).at(nb.at(1))->something->get_stat().HP;
	int death = 0;
	death = grid.at(pos.at(0)).at(pos.at(1))->attack(grid.at(nb.at(0)).at(nb.at(1)));
	if (death > 1) {
		int dam = damage(grid.at(pos.at(0)).at(pos.at(1)), grid.at(nb.at(0)).at(nb.at(1)));
		delete grid.at(nb.at(0)).at(nb.at(1))->something;
		grid.at(nb.at(0)).at(nb.at(1))->enemy = false;
		grid.at(nb.at(0)).at(nb.at(1))->something = nullptr;
		vector<int> gold_pos = {nb.at(0), nb.at(1)};
		dropgold(death, gold_pos);
		if (pos.at(0) == PCpos.at(0) && pos.at(1) == PCpos.at(1)) {
		action << grid.at(pos.at(0)).at(pos.at(1))->print()
                << " deals " << dam << " damage to the enemy and kills it";
		}
		if (death == 5) {
		herotype = -10;
		}
	} else if (death == 0) {
	} else {
	int dam = damage(grid.at(pos.at(0)).at(pos.at(1)), grid.at(nb.at(0)).at(nb.at(1)));
	action << grid.at(pos.at(0)).at(pos.at(1))->print()
		<< " deals " << dam << " damage to " 
		<< grid.at(nb.at(0)).at(nb.at(1))->print()
		<< " (" << grid.at(nb.at(0)).at(nb.at(1))->something->get_stat().HP
		<< " HP)";
	  if (oldPC_HP == grid.at(PCpos.at(0)).at(PCpos.at(1))->something->get_stat().HP && oldNB_HP == grid.at(nb.at(0)).at(nb.at(1))->something->get_stat().HP) {
	    action << ", but it missed";
	  }
	action << ".";
	}
	if ((death >= 1) && (pos.at(0) == PCpos.at(0) && pos.at(1) == PCpos.at(1))){
		tellenemy(true);
	}
	result += action.str();
	return death;
}

void Map::enemyround() {
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < width; ++j) {
			if(grid.at(i).at(j)->enemy && grid.at(i).at(j)->something->action > 0) {
				vector<int> nb0 = {i-1, j - 1};
				vector<int> nb1 = {i-1, j};
				vector<int> nb2 = {i-1, j + 1};
				vector<int> nb3 = {i, j + 1};
				vector<int> nb4 = {i+1, j + 1};
				vector<int> nb5 = {i+1, j};
				vector<int> nb6 = {i+1, j - 1};
				vector<int> nb7 = {i, j - 1};
				vector<vector<int>> neighbours = {nb0, nb1, nb2, nb3, nb4, nb5, nb6, nb7};
				bool notmove = true;
				int k = 8;
				while (neighbours.size() > 0 && notmove) {
					srand((unsigned)time(NULL));
					int pos = rand() % k;
					int n_row = neighbours.at(pos).at(0);
					int n_col = neighbours.at(pos).at(1);
					if (grid.at(i).at(j)->move(grid.at(n_row).at(n_col))) {
						notmove = false;
						grid.at(i).at(j)->enemy = false;
						grid.at(n_row).at(n_col)->enemy = true;
					} else {
						neighbours.erase(neighbours.begin()+pos);
						--k;
					}
				}
			   	
			}
		}
	}
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < width; ++j) {
			if(grid.at(i).at(j)->enemy) {
				grid.at(i).at(j)->refresh();
			}
		}
	}
}

void Map::printmap() {
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < width; ++j) {
			cout << grid.at(i).at(j)->printlogo();
		}
		cout << endl;
	}
	string heroname;
	if (herotype == 0) {
		heroname = "Shade";
	} else if (herotype == 1) {
		heroname = "Drow";
	} else if (herotype == 2) {
		heroname = "Vampire";
	} else if (herotype == 3) {
		heroname = "Troll";
	} else {
		heroname = "Goblin";
	}
	cout << "Race " << heroname << " Gold: " << hero->get_stat().Gold << endl;
	cout << "HP: " << static_cast<int>(hero->get_stat().HP) << endl;
	cout << "Atk: " << static_cast<int>(hero->get_stat().Atk) + static_cast<int>(hero->get_stat().extra_Atk) << endl;
	cout << "Def: " << static_cast<int>(hero->get_stat().Def) + static_cast<int>(hero->get_stat().extra_Def) << endl;
	cout << "Action: ";
	cout << result << endl;
	result = "";
}
	






