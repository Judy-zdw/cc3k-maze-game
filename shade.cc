#include "shade.h"
using namespace std;

Shade::Shade(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold):
 Hero{max_HP, HP, Atk, Def, extra_Atk, extra_Def, Gold} {}

int Shade::attack(Unit* toattack) {
  return toattack->beattacked(this);
}

bool Shade::use(Unit *touse) {
  return touse->beused(this);
}

