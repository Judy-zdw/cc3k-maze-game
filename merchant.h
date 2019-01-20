#ifndef MERCHANT_H__
#define MERCHANT_H__
#include "enemy.h"

class Unit;
class Hero;

class Merchant: public Enemy{
public:
  static bool friendly;
  Merchant();
  ~Merchant() {}
  int die() override;
  std::string print() override;
  std::string printlogo() override;
  int attack(Unit *toattack) override;
  int beattacked(Hero *attackedby) override;
  static void be_enemy();
};

#endif
