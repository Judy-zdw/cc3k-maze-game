#ifndef _PASSWAY_H_
#define _PASSWAY_H_

#include "cell.h"

class Hero;
class Unit;

// All Passways lead to Room, only PC can walk on it, because PC has the pass, which is nice.
// By the way, nothing can be put on it. DON"T BLOCK THE WAY.
class Passway final: public Cell {

	public:
		Passway(Unit* something = nullptr, bool enemy = false);
		~Passway();
		bool reached(Hero* movedby) override;
		std::string printlogo() override;
};

#endif
