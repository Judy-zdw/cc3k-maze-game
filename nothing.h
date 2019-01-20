#ifndef _NOTHING_H_
#define _NOTHING_H_

#include "cell.h"

class Unit;

// class nothing represent a cell which have nothing on it, nothing can be put on it nor move on it. 
// It's so nothing.
class Nothing final: public Cell {

	public:
		Nothing(Unit* something = nullptr, bool enemy = false);
		~Nothing();
		bool reached(Hero *movedby) override;
		std::string printlogo() override;
};

#endif
