#include "treasure.h"

using namespace std;

Treasure::Treasure(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold): 
  Unit{max_HP, HP, Atk, Def, extra_Atk, extra_Def, Gold} {}

string Treasure::printlogo() {
  return "G";
}

Treasure::~Treasure() {}

bool Treasure::bemoved(Hero *movedby) {
  movedby->change_Stat(get_stat());
  return ValidAction;
}

//int Treasure::beattacked(Hero *attackedby) {
//  return InvalidAction;
//}

string Treasure::print() {}
