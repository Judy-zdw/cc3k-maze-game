#ifndef _TILE_H_
#define _TILE_H_

#include "cell.h"

class Hero;
class Enemy;
class Unit;

// Room is made of Tiles. You can walk on it, put anything you like on it.
class Tile final: public Cell {

	public:
		Tile(Unit* something = nullptr, bool enemy = false);
		~Tile();
		bool reached(Enemy* movedby) override;
		bool reached(Hero* movedby) override;
		std::string printlogo() override;
		bool dropto() override;
};

#endif
