#include "dragon.h"
#include "hero.h"
#include "hoard_d.h"
using namespace std;

string Dragon::print() {
  return "D";
}

string Dragon::printlogo() {
  return "D";
} 

int Dragon::attack(Unit *toattack) {
  return InvalidAction;
}

int Dragon::attack(Hero *toattack) {
  return toattack->beattacked(myhoard);
}

int Dragon::beattacked(Hero *attackedby) {
  return myhoard->beattacked(attackedby);
}

Dragon::Dragon(Hoard_d* myhoard): Enemy{150, 150, 20, 20, 0, 0, 0}, myhoard{myhoard} {}

Dragon::~Dragon() {}
