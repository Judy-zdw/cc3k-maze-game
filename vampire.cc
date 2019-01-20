#include "vampire.h"

using namespace std;

Vampire::Vampire(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold):
  Hero{max_HP, HP, Atk, Def, extra_Atk, extra_Def, Gold} {}

/*int Vampire::attack(shared_ptr<Enemy> toattack) {
  double itsDef = toattack->get_stat().Def;
  double myAtk = ability.Atk;
  int damage = ceil((100 / (100 + itsDef)) * myAtk);
  Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
  toattack.change_Stat(change);
  Stat restore{0, 5, 0 ,0 ,0 ,0 ,0};
  change_Stat(restore};
  action -= 2;
  return toattack.die();
}

int Vampire::attack(shared_ptr<Dwarf> toattack) {
  double itsDef = toattack->get_stat().Def;
  double myAtk = ability.Atk;
  int damage = ceil((100 / (100 + itsDef)) * myAtk);
  Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
  toattack.change_Stat(change);
  Stat tastebad{0, -5, 0 ,0 ,0 ,0 ,0};
  change_Stat(tastebad};
  action -= 2;
  return toattack.die();
}
*/

int Vampire::attack(Unit* toattack) {
  return toattack->beattacked(this);
}

bool Vampire::use(Unit *touse) {
  return touse->beused(this);
}

