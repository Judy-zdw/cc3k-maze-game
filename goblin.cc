#include "goblin.h"
#include "orcs.h"

using namespace std;

Goblin::Goblin(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold):
  Hero{max_HP, HP, Atk, Def, extra_Atk, extra_Def, Gold} {}

/*int Goblin::attack(shared<Enemy> toattack) {
  double itsDef = toattack->get_stat().Def;
  double myAtk = ability.Atk;
  int damage = ceil((100 / (100 + itsDef)) * myAtk);
  Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
  toattack.change_Stat(change);
  int death = toattack.die();
  if (death > 1) {
    Stat steal{0, 0, 0, 0, 0, 0, 5};
    change_Stat(steal);
  }
  return death;
}

*/
int Goblin::beattacked(Orcs *attackedby) {
  double itsAtk = (attackedby->get_stat().Atk + attackedby->get_stat().extra_Atk) * 1.5;
  double myDef = get_stat().Def + get_stat().extra_Def;
  double damage = ceil((100 / (100 + myDef)) * itsAtk);
  srand(time(nullptr));
  int miss = rand() % 2;
  if (!miss) {
  Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
  change_Stat(change);
  return die();
}
}

int Goblin::attack(Unit *toattack) {
  return toattack->beattacked(this);
}

bool Goblin::use(Unit *touse) {
  return touse->beused(this);
}

