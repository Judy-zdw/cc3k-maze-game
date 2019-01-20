#include "unit.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "hero.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "halfling.h"



using namespace std;

Unit::Unit(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold): ability{max_HP, HP, Atk, Def, extra_Atk, extra_Def, Gold}, action{Action} {};

bool Unit::bemoved(Enemy *movedby) {
	return InvalidAction;
}

bool Unit::bemoved(Hero *movedby) {
	return InvalidAction;
}

bool Unit::beused(Hero *usedby) {
	return InvalidAction;
}

//int Unit::beattacked(Enemy *attackedby) {
//	return InvalidAction;
//}

//int Unit::beattacked(Hero *attackedby) {
//        return InvalidAction;
//}

/*int Unit::beattacked(Hero *attackedby) {
  double itsAtk = attackedby->get_stat().Atk + attackedby->get_stat().extra_Atk;
  double myDef = get_stat().Def + get_stat().extra_Def;
  double damage = ceil((100 / (100 + myDef)) * itsAtk);
  Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
  change_Stat(change);
  return die();
}*/

int Unit::beattacked(Human *attackedby) {
  return 0; //Hero::beattacked(dynamic_cast<Enemy*>(attackedby));
}

int Unit::beattacked(Dwarf *attackedby) {
  return 0; //Hero::beattacked(dynamic_cast<Enemy*>(attackedby));
}

int Unit::beattacked(Elf *attackedby) {
  //int death = Hero::beattacked(dynamic_cast<Enemy*>(attackedby));
  //if (death <= 1) { death = Hero::beattacked(dynamic_cast<Enemy*>(attackedby));}
  return 0; //death;
}

int Unit::beattacked(Orcs *attackedby) {
  return 0; //Hero::beattacked(dynamic_cast<Enemy*>(attackedby));
}

int Unit::beattacked(Merchant *attackedby) {
  return 0; //Hero::beattacked(dynamic_cast<Enemy*>(attackedby));
}

int Unit::beattacked(Hoard_d *attackedby) {
  return 0; //Hero::beattacked(dynamic_cast<Enemy*>(attackedby));
}

int Unit::beattacked(Halfling *attackedby) {
  return 0; //Hero::beattacked(dynamic_cast<Enemy*>(attackedby));
}


int Unit::beattacked(Shade *attackedby) {
  return 0;//Unit::beattacked(dynamic_cast<Hero*> (attackedby));
}

int Unit::beattacked(Drow *attackedby) {
  return 0;//Unit::beattacked(dynamic_cast<Hero*> (attackedby));
}

int Unit::beattacked(Vampire *attackedby) {
//  Stat tastyblood{0, 5, 0, 0, 0, 0, 0};
//  attackedby->change_Stat(tastyblood);
  return 0; //Unit::beattacked(dynamic_cast<Hero*> (attackedby));
}

int Unit::beattacked(Troll *attackedby) {
//  Stat recover{0, 5, 0, 0, 0, 0, 0};
//  attackedby->change_Stat(recover);
  return 0; //Unit::beattacked(dynamic_cast<Hero*> (attackedby));
}

int Unit::beattacked(Goblin *attackedby) {
//  int death = Unit::beattacked(dynamic_cast<Hero*> (attackedby));
//  if (death > 1) {
//    Stat steal{0, 0, 0, 0, 0, 0, 5};
//    attackedby->change_Stat(steal);
//  }
  return 0;
}


int Unit::attack(Unit *toattack) {
	return InvalidAction;;
}

bool Unit::use(Unit *touse) {
	return InvalidAction;
}

bool Unit::move(Cell *object) {
	return InvalidAction;
}

void Unit::change_Stat(Stat change) {
	ability.max_HP += change.max_HP;
	ability.HP += change.HP;
	if (ability.HP > ability.max_HP) ability.HP = ability.max_HP;
	ability.extra_Atk += change.extra_Atk;
	if (ability.Atk + ability.extra_Atk < 0) ability.extra_Atk = 0 - ability.Atk;
	ability.extra_Def += change.extra_Def;
	if (ability.Def + ability.extra_Def < 0) ability.extra_Def = 0 - ability.Def;
	ability.Atk += change.Atk;
	ability.Def += change.Def;
	ability.Gold += change.Gold;
}

Stat Unit::get_stat() {
	return ability;
}

int Unit::die() {
	return Alive;
}

int Unit::notify(Unit *neighbour) {
	return 0;
}

Unit::~Unit(){}
