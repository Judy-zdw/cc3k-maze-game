#ifndef Dragon_H_
#define Dragon_H_
#include "enemy.h"

class Unit;

class Dragon: public Enemy{
  Hoard_d *myhoard;
public:
  Dragon(Hoard_d* myhoard=nullptr);
  int attack(Unit *toattack) override;
  int attack(Hero *toattack);
  int beattacked(Hero *attackedby) override;
  ~Dragon();
  std::string print() override;
  std::string printlogo() override;
};


#endif
