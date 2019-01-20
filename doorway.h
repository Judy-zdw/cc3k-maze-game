#ifndef _DOORWAY_H_
#define _DOORWAY_H_

#include "cell.h"

class Unit;
class Hero;

// Connect passways and rooms, best guard(much better than that dragon).
class Doorway: public Cell {
	public:
		Doorway(Unit* something = nullptr, bool enemy = false);
		~Doorway();
		bool reached(Hero* movedby) override;
		std::string printlogo() override;
};

#endif
