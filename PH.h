#ifndef _PH_H_
#define _PH_H_
#include "potion.h"

class Hero;

//Poison HP
class PH: public Potion {
	public:  
	        static bool known;
                std::string print();
                static void knowntype();
 		bool beused(Hero *usedby) override;
                PH();
		~PH();
};

#endif
