#ifndef VAMPIRE__H_
#define VAMPIRE__H_
#include <climits>
#include "hero.h"

class Unit;

class Vampire: public Hero{
public:
  Vampire(double max_HP=10000, double HP = 50, double Atk = 25, double Def= 25, double extra_Atk = 0, double extra_Def = 0, 
int Gold = 0);
  ~Vampire() = default;
  //int attack(std::shared_ptr<Enemy> toattack) override;
  //int attack(std::shared_ptr<Dwarf> toattack) override;
  int attack(Unit *toattack) override;
  bool use(Unit *touse) override;
};


#endif
