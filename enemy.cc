#include "enemy.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "cell.h"


using namespace std;

int Enemy::die() {
  if (get_stat().HP > 0) return Alive;
  return CommonDie;
}

Enemy::Enemy(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold): 
   Unit{max_HP, HP, Atk, Def, extra_Atk, extra_Def, 0} {}

Enemy::~Enemy() {}

int Enemy::beattacked(Hero *attackedby) {
  double itsAtk = attackedby->get_stat().Atk + attackedby->get_stat().extra_Atk;
  double myDef = get_stat().Def + get_stat().extra_Def;
  double damage = ceil((100 / (100 + myDef)) * itsAtk);
  Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
  change_Stat(change);
  return die();
}

int Enemy::beattacked(Shade *attackedby) {
  return Enemy::beattacked(dynamic_cast<Hero*> (attackedby));
}

int Enemy::beattacked(Drow *attackedby) {
  return Enemy::beattacked(dynamic_cast<Hero*> (attackedby));
}

int Enemy::beattacked(Vampire *attackedby) {
  Stat tastyblood{0, 5, 0, 0, 0, 0, 0};
  attackedby->change_Stat(tastyblood);
  return Enemy::beattacked(dynamic_cast<Hero*> (attackedby));
}

int Enemy::beattacked(Troll *attackedby) {
  Stat recover{0, 5, 0, 0, 0, 0, 0};
  attackedby->change_Stat(recover);
  return Enemy::beattacked(dynamic_cast<Hero*> (attackedby));
}

int Enemy::beattacked(Goblin *attackedby) {
  int death = Enemy::beattacked(dynamic_cast<Hero*> (attackedby));
  if (death > 1) { 
    Stat steal{0, 0, 0, 0, 0, 0, 5};
    attackedby->change_Stat(steal);
  }
  return death;
}


int Enemy::attack(Unit *toattack) {}
string Enemy::print(){}
string Enemy::printlogo(){}

bool Enemy::move(Cell *moveto) {
  return moveto->bemoved(this);
}

bool Enemy::bemoved(Hero* movedby) {
  return InvalidAction;
}

/*int Enemy::attack(shared_ptr<Unit> toattack) {
  return InvalidAction;
}

int Enemy::attack(shared_ptr<Hero> toattack) {
  double itsDef = toattack->get_stat().Def + toattack->get_stat().extra_Def;
  double myAtk = get_stat().Atk + ability.extra_Atk;
  int damage = ceil((100 / (100 + itsDef)) * myAtk);
  srand(time(nullptr));
  int miss = rand() % 2;
  if (!miss) {
  Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
  toattack->stat_change(change);
  action -= 2;
  return toattack->die();
}


int Enemy::attack(shared_ptr<Shade> toattack) {
  return Enemy::attack(dynamic_cast<shared_ptr<Hero> > toattack);
}
  
int Enemy::attack(shared_ptr<Drow> toattack) {
  return Enemy::attack(static_cast<shared_ptr<Hero> > toattack);
}

int Enemy::attack(shared_ptr<Vampire> toattack) {
  return Enemy::attack(static_cast<shared_ptr<Hero> > toattack);
}

int Enemy::attack(shared_ptr<Troll> toattack) {
  return Enemy::attack(static_cast<shared_ptr<Hero> > toattack);
}

int Enemy::attack(shared_ptr<Goblin> toattack) {
  return Enemy::attack(static_cast<shared_ptr<Hero> > toattack);
}*/

int Enemy::notify(Unit *neighbour) {
  return 1;
}


