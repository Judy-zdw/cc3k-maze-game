#include "halfling.h"
#include "hero.h"

using namespace std;

string Halfling::print() {
  return "L";
}

string Halfling::printlogo() {
  return "L";
}

int Halfling::attack(Unit* toattack) {
  return toattack->beattacked(this);
}

int Halfling::beattacked(Hero *attackedby) {
  double itsAtk = (attackedby->get_stat().Atk + attackedby->get_stat().extra_Atk);
  double myDef = get_stat().Def + get_stat().extra_Def;
  double damage = ceil((100 / (100 + myDef)) * itsAtk);
  srand(time(nullptr));
  int miss = rand() % 2;
  if (!miss) {
  Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
  change_Stat(change);
  return die();
  }
}

Halfling::Halfling(): Enemy{100, 100, 15, 20, 0, 0, 0} {}
