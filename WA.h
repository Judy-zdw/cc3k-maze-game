#ifndef _WA_H_
#define _WA_H_
#include "potion.h"

class Hero;

//Wound Atk temporarily
class WA: public Potion {
      public:
        	static bool known;
       		std::string print();
                static void knowntype();
 		bool beused(Hero *usedby) override;
                WA();
		~WA();
};

#endif
