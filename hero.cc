#include "hero.h"
#include "treasure.h"
#include "hoard_d.h"
#include "cell.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "halfling.h"

using namespace std;

Hero::Hero(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold):
  Unit{max_HP, HP, Atk, Def, extra_Atk, extra_Def, Gold} {}

Hero::~Hero() {}

string Hero::print() {
  return "PC";
}

string Hero::printlogo() {
  return "@";
}

int Hero::beattacked(Enemy *attackedby) {
  double itsAtk = attackedby->get_stat().Atk + attackedby->get_stat().extra_Atk;
  double myDef = get_stat().Def + get_stat().extra_Def;
  double damage = ceil((100 / (100 + myDef)) * itsAtk);
  srand(time(nullptr));
  int miss = rand() % 2;
  if (!miss) {
    Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
    change_Stat(change);
  }
  return die();
}

int Hero::beattacked(Human *attackedby) {
  return Hero::beattacked(dynamic_cast<Enemy*>(attackedby));
}

int Hero::beattacked(Dwarf *attackedby) {
  return Hero::beattacked(dynamic_cast<Enemy*>(attackedby));
}

int Hero::beattacked(Elf *attackedby) {
  int death = Hero::beattacked(dynamic_cast<Enemy*>(attackedby));
  if (death <= 1) { death = Hero::beattacked(dynamic_cast<Enemy*>(attackedby));}
  return death;
}

int Hero::beattacked(Orcs *attackedby) {
  return Hero::beattacked(dynamic_cast<Enemy*>(attackedby));
}

int Hero::beattacked(Merchant *attackedby) {
  return Hero::beattacked(dynamic_cast<Enemy*>(attackedby));
}

int Hero::beattacked(Hoard_d *attackedby) {
  return Hero::beattacked(dynamic_cast<Enemy*>(attackedby));
}

int Hero::beattacked(Halfling *attackedby) {
  return Hero::beattacked(dynamic_cast<Enemy*>(attackedby));
}

int Hero::attack(Unit *toattack) {}

//int Hero::attack(Potion *toattack) {return InvalidAction;}

//int Hero:: attack(Treasure *toattack) {return InvalidAction;}

bool use(Unit *touse) {}

/*int Hero::attack(shared<Unit> toattack) {
  return InvalidAction;
}

int Hero::attack(shared<Enemy> toattack) {
  double itsDef = toattack->get_stat().Def + toattack->get_stat().extra_Def;
  double myAtk = get_stat().Atk + ability.extra_Atk;
  int damage = ceil((100 / (100 + itsDef)) * myAtk);
  Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
  toattack.change_Stat(change);
  return toattack.die();
}

int Hero::attack(shared_ptr<Human> toattack) {
  return Hero::attack(static_cast<shared_ptr<Enemy> > toattack);
}

int Hero::attack(shared_ptr<Dwarf> toattack) {
  return Hero::attack(static_cast<shared_ptr<Enemy> > toattack);
}

int Hero::attack(shared_ptr<Elf> toattack) {
  return Hero::attack(static_cast<shared_ptr<Enemy> > toattack);
}

int Hero::attack(shared_ptr<Orcs> toattack) {
  return Hero::attack(static_cast<shared_ptr<Enemy> > toattack);
}

int Hero::attack(shared_ptr<Merchant> toattack) {
  return Hero::attack(static_cast<shared_ptr<Enemy> > toattack);
}

int Hero::attack(shared_ptr<Dragon> toattack) {
  return Hero::attack(static_cast<shared_ptr<Enemy> > toattack);
}

int Hero::attack(shared_ptr<Hoard_d> toattack) {
  return InvalidAction;
}*/


bool Hero::move(Cell *moveto) {
  return moveto->bemoved(this);
}

bool Hero::use(Unit *touse) {
  return InvalidAction;
}

/*bool Hero::use(shared_ptr<Potion> touse) {
  change_Stat(touse->get_stat());
  return ValidAction;
}*/

int Hero::notify(Unit *neighbour) {
  return neighbour->notify(this);
}

int Hero::die() {
  if (get_stat().HP > 0) return Alive;
  return PC_die;
}


