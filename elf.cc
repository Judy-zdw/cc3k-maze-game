#include "elf.h"
using namespace std;

Elf::Elf(double max_HP, double HP, double Atk, double Def, double extra_Atk, double extra_Def, int Gold): Enemy{max_HP, HP, Atk, Def, extra_Atk, extra_Def, Gold} {}

/*int Elf::attack(shared_ptr<Vampire> toattack) override {
  int result = Enemy::attack(static_cast<shared_ptr<Hero>> toattack);
  if(result == Alive) {
    return Enemy::attack(static_cast<shared_ptr<Hero>> toattack);
  }
  return result;
}

int Elf::attack(shared_ptr<Shade> toattack) override {
  return Elf::attack(static_cast<shared_ptr<Vampire>> toattack);
}

int Elf::attack(shared_ptr<Troll> toattack) override {
  return Elf::attack(static_cast<shared_ptr<Vampire>> toattack);
}

int Elf::attack(shared_ptr<Goblin> toattack) override {
  return Elf::attack(static_cast<shared_ptr<Vampire>> toattack);
}
*/

int Elf::attack(Unit* toattack) {
  return toattack->beattacked(this);
}

string Elf::print() {
  return "E";
}

string Elf::printlogo() {
  return "E";
}
