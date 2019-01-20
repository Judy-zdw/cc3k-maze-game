#ifndef _MAP_H
#define _MAP_H

#include "chamber.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <utility>

class Hero;
class Cell;
class Unit;
class Vampire;
class Shade;
class Merchant;
class Drow;
class Troll;
class Goblin;
class Human;
class Dwarf;
class Halfling;
class Elf;
class Orcs;
class Dragon;
class Hoard_d;
class BA;
class RH;
class BD;
class PH;
class WA;
class WD;
class Gold_s;
class Gold_n;
class Hoard_m;
class Stair;
class Wall;
class Tile;
class Passway;
class Doorway;
class Nothing;



enum class Dir {nw=0, no, ne, we, ea, sw, so, se};

class Map {
	std::vector<Chamber> rooms;
	int width;
	int length;
	std::vector<std::vector<Cell*>> grid;
	int floor;
	std::string result;

	
	std::vector<int> stairpos;

	bool newgame;
	int herotype;
	Hero* hero;
	
	void tellenemy(bool succeed);
	void changePCpos(Dir direction);
	void putstair(int whichchamber, std::vector<std::vector<Cell*>> gird);
	void dropgold(int death, std::vector<int> gold_pos);
	std::vector<int> put(Unit* toput, int whichchamber, 
                       std::vector<std::vector<Cell*>> grid);
	bool put_Dragon(Hoard_d* HD,std::vector<int> H_pos, int whichchamber, std::vector<std::vector<Cell*>> grid);
public:
	Map(int floor = 0, int herotype = 0, bool newgame = true, Hero* oldhero = nullptr);
	~Map();
	
	std::vector<int> PCpos;

	int getfloor();
	int getherotype();
	Hero* gethero();
	void changehero(int newtype);

	bool nextfloor();
	bool lastfloor();
	
	
	bool movePC(Dir direction);
	bool use(Dir direction);
	bool attack(std::vector<int> pos, Dir direction);

	void enemyround();
	void printmap();
};

#endif
