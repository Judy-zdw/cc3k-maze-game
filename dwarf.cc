#include "dwarf.h"
#include "vampire.h"

using namespace std;

string Dwarf::print() {
  return "W";
}

string Dwarf::printlogo() {
  return "W";
}


int Dwarf::beattacked(Vampire *attackedby) {
  double itsAtk = attackedby->get_stat().Atk + attackedby->get_stat().extra_Atk;
  double myDef = get_stat().Def + get_stat().extra_Def;
  double damage = ceil((100 / (100 + myDef)) * itsAtk);
  Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
  change_Stat(change);
  Stat tastebad{0, -5, 0 ,0 ,0 ,0 ,0};
  change_Stat(tastebad);
  return attackedby->die();
}

int Dwarf::attack(Unit *toattack) {
  return toattack->beattacked(this);
}

Dwarf::Dwarf(): 
  Enemy{100, 100, 20, 30, 0, 0, 0} {}
