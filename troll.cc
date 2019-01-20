#include "troll.h"
#include "cell.h"
#include "potion.h"

using namespace std;

Troll::Troll(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold):
  Hero{max_HP, HP, Atk, Def, extra_Atk, extra_Def, Gold} {}

/*int Troll::attack(shared_ptr<Enemy> toattack) {
  double itsDef = toattack->get_stat().Def;
  double myAtk = ability.Atk;
  int damage = ceil((100 / (100 + itsDef)) * myAtk);
  Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
  toattack.change_Stat(change);
  Stat regain{0, 5, 0, 0, 0, 0, 0};
  change_Stat(regain);
  return toattack.die();
}*/

bool Troll::move(Cell *moveto) {
  bool valid = moveto->bemoved(this);
  if (valid) {
    Stat regain{0, 5, 0, 0, 0, 0, 0};
    change_Stat(regain);
  }
  return valid;
}

bool Troll::use(Unit *touse) {
  bool valid = touse->beused(this);
  if (valid) {
  Stat regain{0, 5, 0, 0, 0, 0, 0};
  change_Stat(regain);
}
  return touse->beused(this);
}

int Troll::attack(Unit* toattack) {
  return toattack->beattacked(this);
}
