#ifndef DROW__H_
#define DROW__H_
#include "hero.h"

class Elf;
class Unit;

class Drow: public Hero{
public:
  Drow(double max_HP=150, double HP=150, double Atk=25, double Def=15, double extra_Atk=0, double extra_Def=0, int Gold=0);
  ~Drow() = default;
  bool use(Unit *touse) override;
  int attack(Unit *toattack) override;
  int beattacked(Elf *attackedby) override;
};


#endif
