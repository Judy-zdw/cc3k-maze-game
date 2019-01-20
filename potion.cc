#include "potion.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

using namespace std;

Potion::Potion(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold):
  Unit{max_HP, HP, Atk, Def, extra_Atk, extra_Def, Gold} {}

Potion::~Potion() {}

string Potion::printlogo() {
  return "P";
}

int Potion::notify(Unit *neighbour) {
  return 2;
}

bool Potion::beused(Hero *usedby) {
  usedby->change_Stat(get_stat());
  return ValidAction;
}

bool Potion::beused(Shade *usedby) {
  return Potion::beused(dynamic_cast<Hero*>(usedby));
}

bool Potion::beused(Drow *usedby) {
  Stat enhance = get_stat();
  enhance.HP *= 1.5;
  enhance.extra_Atk *= 1.5;
  enhance.extra_Def *= 1.5;
  usedby->change_Stat(enhance);
  return ValidAction;
}

bool Potion::beused(Vampire *usedby) {
  return Potion::beused(dynamic_cast<Hero*>(usedby));
}

bool Potion::beused(Troll *usedby) {
  Stat tastyblood{0, 5, 0, 0, 0, 0, 0};
  usedby->change_Stat(tastyblood);
  return Potion::beused(dynamic_cast<Hero*>(usedby));
}

bool Potion::beused(Goblin *usedby) {
  return Potion::beused(dynamic_cast<Hero*>(usedby));
}

//int Potion::beattacked(Hero *attackedby) {
//  return InvalidAction;
//}




