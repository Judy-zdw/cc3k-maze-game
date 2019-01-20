#ifndef HERO_H__
#define HERO_H__
#include <cstdlib>
#include <ctime>
#include "unit.h"



// Hero is a very similar class to Enemy. almost all its methods behaves the same as those of
// Enemy. Hero is the PC that controlled by player.

extern const int Action;
extern const int alive;
extern const int PC_die;

class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;
class Treasure;
class Potion;
class Hoard_d;

class Hero: public Unit {
 public:
  Hero(double max_HP, double HP, double Atk, double Def, double extra_Atk=0, double extra_Def=0, int Gold=0);
  virtual std::string print() override;
  virtual std::string printlogo() override;
  virtual ~Hero() = 0;
  virtual int beattacked(Enemy *attackedby);
  virtual int beattacked(Human *attackedby) override;
  virtual int beattacked(Dwarf *attackedby) override;
  virtual int beattacked(Elf *attackedby) override;
  virtual int beattacked(Orcs *attackedby) override;
  virtual int beattacked(Merchant *attackedby) override;
  virtual int beattacked(Hoard_d *attackedby) override;
  virtual int beattacked(Halfling *attackedby) override;

  virtual int attack(Unit *toattack) override;
//  int attack(Potion *toattack) override;
//  int attack(Treasure *toattack) override;


  virtual bool use(Unit *touse) override;
  /*virtual int attack(std::shared_ptr<Enemy> toattack);
  virtual int attack(std::shared_ptr<Human> toattack);
  virtual int attack(std::shared_ptr<Dwarf> toattack);
  virtual int attack(std::shared_ptr<Elf> toattack);
  virtual int attack(std::shared_ptr<Orcs> toattack);
  virtual int attack(std::shared_ptr<Merchant> toattack);
  virtual int attack(std::shared_ptr<Dragon> toattack);
  virtual int attack(std::shared_ptr<Hoard_d> toattack);*/
  virtual int notify(Unit *neighbour) override;
  virtual int die() override;
  virtual bool move(Cell *moveto) override;
  //virtual bool use(std::shared_ptr<Unit> touse);
  //virtual bool use(std::shared_ptr<Potion> touse);
  // kill helps to do the stuff like killing reward. in this case, it helps Goblin to steel
  // Gold after evey kill.
};

#endif
