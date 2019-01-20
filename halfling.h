#ifndef HALFLING_H__
#define HALFLING_H__
#include "enemy.h"

class Unit;
class Hero;

class Halfling: public Enemy{
public:
  Halfling();
  ~Halfling() {}
  int attack(Unit *toattack) override;
  int beattacked(Hero *attackedby) override;
  std::string print() override;
  std::string printlogo() override;
};

#endif
