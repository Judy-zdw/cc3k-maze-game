#ifndef TROLL_H_
#define TROLL_H_
#include "hero.h"

class Troll: public Hero {
public:
  Troll(double max_HP=110, double HP=110, double Atk=15, double Def=20, double extra_Atk=0, double extra_Def=0, int Gold=0);
  ~Troll() = default;
//  int attack(std::shared_ptr<Enemy> toattack) override;
  int attack(Unit *toattack) override;
  bool move(Cell *moveto) override;
  bool use(Unit *touse) override;
};


#endif
