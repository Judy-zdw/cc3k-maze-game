#ifndef SHADE__H_
#define SHADE__H_
#include "hero.h"

class Unit;
class Shade: public Hero{
public:
  Shade(double max_HP=125, double HP=125, double Atk=25, double Def=25, double extra_Atk=0, double extra_Def=0, int Gold=0);
  ~Shade() = default;
  int attack(Unit *toattack) override;
  bool use(Unit *touse) override;
};

#endif
