#ifndef _RH_H_
#define _RH_H_
#include "potion.h"

class Hero;
//Restore HP
class RH: public Potion {
	public:
        	static bool known;
		RH();
                static void knowntype();
                std::string print();
		bool beused(Hero *usedby) override;
                ~RH();
};

#endif
