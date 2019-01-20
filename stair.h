#ifndef _STAIR_H_
#define _STAIR_H_

#include "cell.h"

class Unit;
class Hero;

// Stair will let the charater go to the next floor, it's move is very different that other constructions.
class Stair final: public Cell {

	public:
		Stair(Unit* something = nullptr, bool enemy = false);
		~Stair();
		bool reached(Hero* movedby) override;
		std::string printlogo() override;
};

#endif
