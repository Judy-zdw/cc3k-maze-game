#ifndef DWARF_H__
#define DWARF_H__
#include "enemy.h"

class vampire;
class Unit;

class Dwarf: public Enemy{
public:
  Dwarf();
  ~Dwarf() {}
  std::string print() override;
  std::string printlogo() override;
  int attack(Unit *toattack) override;
  int beattacked(Vampire *attackedby) override;
};

#endif
