#ifndef GOBLIN_H_
#define GOBLIN_H_
#include "hero.h"

class Orcs;
class Unit;

class Goblin: public Hero{
public:
  Goblin(double max_HP=120, double HP=25, double Atk=15, double Def=0, double extra_Atk=0, double extra_Def=0, int Gold=0);
  ~Goblin() = default;
  int attack(Unit *toattack) override;
  int beattacked(Orcs *attackedby) override;
  bool use(Unit *touse) override;
};

#endif
