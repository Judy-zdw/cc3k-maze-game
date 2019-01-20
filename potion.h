#ifndef _POTION_H
#define _POTION_H

#include "unit.h"
#include "hero.h"

class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class Hero;

//Uses strategy pattern and visitor pattern, 
//Ithis should be the abstract strategy
//The Potion will have different effect on some specific characters
//If it has been used once, it became known, so PC will know its
//effect next time see the same kind of Potion.
class Potion: public Unit {
	public:
		Potion(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold);
		virtual ~Potion();
                std::string printlogo();
                virtual std::string print() = 0;
		virtual bool beused(Hero *usedby);
                virtual bool beused(Shade *usedby);
                virtual bool beused(Drow *usedby);
                virtual bool beused(Vampire *usedby);
                virtual bool beused(Troll *usedby);
                virtual bool beused(Goblin *usedby);
	//	int beattacked(Hero *attackedby) override;
		int notify(Unit *neighbour);
};

#endif
