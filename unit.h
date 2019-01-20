#ifndef _UNIT_H_
#define _UNIT_H_
#include "const.h"
#include "stat.h"
#include <math.h>
#include <memory>
#include <string>
//#include "hero.h"
//#include "enemy.h"
#include <iostream>

//Unit is the basic unit for all character and items.
//Use move and bemoved, use and beused, attack and beattacked to 
//form a visitor pattern.
//All the subclass that need a specific method to bechanged should
//overload and override those methods.
extern const int Action;
extern const int InvalidAction;
extern const int Alive;

class Hero;
class Enemy;
class Treasure;
class Potion;
class Cell;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class Elf;
class Human;
class Dwarf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;
class Hoard_d;


class Unit {
	Stat ability;


	public:
		
		int action;
		Unit(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold);
                virtual ~Unit() = 0;

		// bemoved returns if the move action success.
		virtual bool bemoved(Hero *movedby);
		virtual bool bemoved(Enemy *movedby);
		// beused behaves the same as bemoved.
		virtual bool beused(Hero *usedby);
		// beattacked is called when some unknown unit is attacking it. it will be 
		// override by all subclasses. it also returns whether the attack action 
		// success and who dies due to the attack. It calls attackby's attack method.
	//	virtual int beattacked(Enemy *attackedby);
	//        virtual int beattacked(Hero *attackedby);
		virtual int beattacked(Shade *attackedby);
		virtual int beattacked(Drow *attackedby);
		virtual int beattacked(Vampire *attackedby);
		virtual int beattacked(Troll *attackedby);
		virtual int beattacked(Goblin *attackedby);
		// this method starts the attack action. it will pass down the death 
		// information to main function. it calls toattack's beattacked method.
		virtual int attack(Unit *toattack);
		// it behaves similarly to attack.
		virtual bool use(Unit *touse);
		// it calls the object cell's bemoved
		virtual bool move(Cell *object);
		// it's a mutator to mutate one's ability. it will be override in Potion and 
		// Treasure and does nothing in these two subclass.
                virtual void change_Stat(Stat change);
		// an accessor
		Stat get_stat();
		// returns an int to show whether the unit is alive and who is it if it dies.
                virtual int die();
		// it helps enemies to find the address of nearby PC. for PC, it gives out
		// its address to nearby enemies.
 	        virtual int notify(Unit *neighbour);
		virtual std::string print() = 0;
		virtual std::string printlogo() = 0;
		virtual int beattacked(Human *attackedby) ;
		virtual int beattacked(Dwarf *attackedby); 
		virtual int beattacked(Elf *attackedby) ;
		virtual int beattacked(Orcs *attackedby) ;
		virtual int beattacked(Merchant *attackedby);
		virtual int beattacked(Hoard_d *attackedby) ;
		virtual int beattacked(Halfling *attackedby) ;
};

#endif
