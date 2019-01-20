#ifndef _BA_H_
#define _BA_H_
#include "potion.h"

class Hero;

//Boost Attack temporarily
class BA: public Potion {
	public:
	        static bool known;
		BA();
                std::string print();
                static void knowntype();
                bool beused(Hero *usedby) override;
		~BA();
};

#endif
