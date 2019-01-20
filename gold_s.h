#ifndef _GOLD_S_H_
#define _GOLD_S_H_

#include "treasure.h"

//The small gold spawned when the game begins.
class Gold_s: public Treasure {
	public:
		Gold_s();
                std::string print() override;
		~Gold_s();
};

#endif
