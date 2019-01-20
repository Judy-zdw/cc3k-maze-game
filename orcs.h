#ifndef ORCS_H__
#define ORCS_H__
#include "enemy.h"

class Unit;

class Orcs: public Enemy {
public:
  Orcs(double max_HP = 180, double HP = 180, double Atk = 30, double Def = 25, double extra_Atk=0, double extra_Def=0, int Gold = 0);
  ~Orcs() {}
  int attack(Unit *toattack) override;
  std::string print() override;
  std::string printlogo() override;
};

#endif
