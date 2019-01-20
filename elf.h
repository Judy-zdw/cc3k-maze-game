#ifndef ELF_H__
#define ELF_H__
#include "enemy.h"

class Unit;

class Elf: public Enemy {
public:
  Elf(double max_HP = 140, double HP = 140, double Atk = 30, double Def = 10, double extra_Atk=0, double extra_Def=0, int Gold = 0);
  ~Elf() {}
   int attack(Unit *toattack) override;
   std::string print() override;
  std::string printlogo() override;
};

#endif
