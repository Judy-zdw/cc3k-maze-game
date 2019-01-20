#include"orcs.h"
#include "enemy.h"
using namespace std;

Orcs::Orcs(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold): Enemy{max_HP, HP, Atk, Def, extra_Atk, extra_Def, Gold} {}

string Orcs::print() {
  return "O";
}

string Orcs::printlogo() {
  return "O";
}

int Orcs::attack(Unit* toattack) {
  return toattack->beattacked(this);
}
/*
int Orcs::attack(std::shared_ptr<Goblin> toattack) override {
  double itsDef = toattack->get_stat()->Def;
  double myAtk = ability.Atk * 1.5;
  int damage = ceil((100 / (100 + itsDef)) * myAtk);
  srand(time(nullptr));
  int miss = rand() % 2;
  if (!miss) {
  Stat change{0, damage*(-1), 0, 0, 0, 0, 0};
  toattack->stat_change(change);
  action -= 2;
  return toattack->die();
}*/
