#ifndef _TREASURE_H
#define _TREASURE_H
#include "unit.h"
#include "hero.h"

class Hero;
//In Strategy Pattern, this should be treated as the Abstracted Strategy
//It will increase the amount of gold PC carries when PC moved on it.
class Treasure: public Unit {
	public:
		Treasure(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold);
		virtual ~Treasure() = 0;
	        virtual std::string print() override;
	        std::string printlogo() override;
		bool bemoved(Hero *movedby) override;
	//	int beattacked(Hero *attackedby) override;
};

#endif
