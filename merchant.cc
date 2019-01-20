#include "merchant.h"
#include "hero.h"

using namespace std;

bool Merchant::friendly = true;

Merchant::Merchant():
  Enemy{30, 30, 70, 5, 0, 0, 0} {}

/*int Merchant::attack(shared_ptr<Hero> toattack) override {
  if(!friendly) {
    double itsDef = toattack->get_stat()->Def;
    double myAtk = get_stat().Atk;
    int damage = ceil((100 / (100 + itsDef)) * myAtk);
    srand(time(nullptr));
    int miss = rand() % 2;
    if (!miss) {
    Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
    toattack->stat_change(change);
    action -= 2;
    return toattack->die();
  }
  return InvalidAction;
}
*/

void Merchant::be_enemy() {
  Merchant::friendly = false;
}

int Merchant::beattacked(Hero *attackedby) {
  Merchant::be_enemy();
  double itsAtk = attackedby->get_stat().Atk + attackedby->get_stat().extra_Atk;
  double myDef = get_stat().Def + get_stat().extra_Def;
  double damage = ceil((100 / (100 + myDef)) * itsAtk);
  Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
  change_Stat(change);
  return die();
}


string Merchant::print() {
  return "M";
}

string Merchant::printlogo() {
  return "M";
}
 
int Merchant::die() {
  if(get_stat().HP > 0) return Alive;
  return MerchantDie;
}

int Merchant::attack(Unit *toattack) {
  if (Merchant::friendly) return InvalidAction;
  return toattack->beattacked(this);
}

