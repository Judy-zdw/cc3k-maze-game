#ifndef _BD_H_
#define _BD_H_
#include "potion.h"

class Hero;

//Boost Defense temporarily
class BD: public Potion {
	public:
        static bool known;
	std::string print();
        static void knowntype();
        bool beused(Hero *usedby) override;
        BD();
	~BD();
};

#endif
