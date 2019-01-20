#include "drow.h"
#include "elf.h"
using namespace std;


Drow::Drow(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold):
  Hero{max_HP, HP, Atk, Def, extra_Atk, extra_Def, Gold} {}

bool Drow::use(Unit *touse) {
  Stat enhence = touse->get_stat();
  enhence.HP *= 1.5;
  enhence.extra_Atk *= 1.5;
  enhence.extra_Def *= 1.5;
  change_Stat(enhence);
  return true;
}

int Drow::attack(Unit* toattack) {
  return toattack->beattacked(this);
}

int Drow::beattacked(Elf *attackedby) {
	double itsAtk = attackedby->get_stat().Atk + attackedby->get_stat().extra_Atk;
  double myDef = get_stat().Def + get_stat().extra_Def;
  double damage = ceil((100 / (100 + myDef)) * itsAtk);
  srand(time(nullptr));
  int miss = rand() % 2;
  if (!miss) {
    Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
    change_Stat(change);
  }
  return die();
}
