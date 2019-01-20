#ifndef _WALL_H_
#define _WALL_H_

#include "cell.h"

class Unit;

//It's a Wall, that's it.
class Wall final: public Cell {
	// This field decides whether it's a vertical or a horizontal
	// wall when it's displayed.
	bool vertical;

	public:
		Wall(Unit* something = nullptr, bool enemy = false, bool vertical = true);
		~Wall();
		bool reached(Hero *movedby) override;
		std::string printlogo() override;
};

#endif
