#ifndef _WD_H_
#define _WD_H_
#include "potion.h"

class Hero;

//Wound Defense
class WD: public Potion {
    public:
        static bool known;
        std::string print();
        static void knowntype();
	bool beused(Hero *usedby) override;	
          WD();
		~WD();
};

#endif
