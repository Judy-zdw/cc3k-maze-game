#ifndef ENEMY_H__
#define ENEMY_H__
#include "unit.h"
#include "hero.h"


extern const int Action;
extern const int Alive;
extern const int CommonDie;
extern const int HumanDie;
extern const int MerchantDie;
extern const int InvalidAction;

class Drow;
class Vampire;
class Troll;
class Goblin;
class Shade;
class Cell;
class Hero;

// Enemy class includes all enemies(NPC): Human, Dwarf, Elf, Orcs, Merchant, Dragon, and 
// Hoard_d. Hoard_d is seen as an enemy since it shares the qualities of enemy.

class Enemy: public Unit, public std::enable_shared_from_this<Enemy>{
 public:
  Enemy(double max_HP, double HP, double Atk, double Def, double extra_Atk=0, double extra_Def=0, int Gold=0);
  virtual ~Enemy() = 0;
  // it's called when being attacked by an unknown unit. it helps to determine its runtime
  // type and is the second step in visitor pattern. it passes down the death information 
  virtual int beattacked(Hero *attackby);
  virtual int beattacked(Shade *attackby);
  virtual int beattacked(Drow *attackby);
  virtual int beattacked(Vampire *attackby);
  virtual int beattacked(Troll *attackby);
  virtual int beattacked(Goblin *attackby);

  // it's a default for the last step of visitor pattern. it's default behavior of an enemy 
  // attacking a hero.
  virtual int attack(Unit *toattack) override;
  /*virtual int attack(std::shared_ptr<Hero> toattack);
  // the followings are specific one to one attack waiting for override. 
  virtual int attack(std::shared_ptr<Shade> toattack);
  virtual int attack(std::shared_ptr<Drow> toattack);
  virtual int attack(std::shared_ptr<Vampire> toattack);
  virtual int attack(std::shared_ptr<Troll> toattack);
  virtual int attack(std::shared_ptr<Goblin> toattack);*/
  int notify(Unit *neighbour) override;
  virtual int die() override;
  virtual bool move(Cell *moveto) override;
  virtual bool bemoved(Hero* movedby) override;
  virtual std::string print() override;
  virtual std::string printlogo() override;
};


#endif
