#include"human.h"
using namespace std;

Human::Human(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold):
Enemy{max_HP, HP, Atk, Def, extra_Atk, extra_Def, Gold} {}

int Human::die() {
  if(get_stat().HP > 0) return Alive;
  return HumanDie;
}

string Human::print() {
  return "H";
}

string Human::printlogo() {
  return "H";
}

int Human::attack(Unit* toattack) {
  return toattack->beattacked(this);
}
