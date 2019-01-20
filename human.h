#ifndef HUMAN_H__
#define HUMAN_H__
#include "enemy.h"

class Unit;

class Human: public Enemy{
public:
  Human(double max_HP = 140, double HP = 140, double Atk = 20, double Def = 20, double extra_Atk=0, double extra_Def=0, int Gold = 0);
  ~Human() {}
  virtual int die() override;
  std::string print() override;
  std::string printlogo() override;
  int attack(Unit *toattack) override;
};

#endif

