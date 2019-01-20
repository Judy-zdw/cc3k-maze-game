#ifndef HOARD_D__H_
#define HOARD_D__H_
#include "enemy.h"

class Unit;
class Dragon;
class Cell;

class Hoard_d: public Enemy{
public:
  Hoard_d();
  ~Hoard_d() = default;
  std::string print() override;
  std::string printlogo() override;
  bool bemoved(Hero *movedby) override;
  int attack(Unit *toattack) override;
  bool move(Cell *object); 
};

#endif
