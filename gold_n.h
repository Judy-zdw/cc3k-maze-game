#ifndef _GOLD_N_H_
#define _GOLD_N_H_

#include "treasure.h"

// The normal gold spawned at the beginning of the game
// or dropped when a human is killed.
class Gold_n: public Treasure {
	public:
		Gold_n();
                std::string print() override;
		~Gold_n();
};

#endif
