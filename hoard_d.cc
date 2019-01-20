#include "hoard_d.h"
#include "dragon.h"
#include "enemy.h"
using namespace std;

Hoard_d::Hoard_d():
  Enemy{150, 150, 20, 20, 0, 0, 6} {}

int Hoard_d::attack(Unit *toattack) {
  if(action > 0) {
  action -= 2;
  return toattack->beattacked(this);
  }
  return InvalidAction;
}

bool move(Cell *object) {
  return InvalidAction;
}


string Hoard_d::print() {
  if (get_stat().HP > 0) {
    return "Dragon";
  }
  return "Dragon Hoard";
}

string Hoard_d::printlogo() {
  return "G";
}

bool Hoard_d::bemoved(Hero *movedby) {
  if (get_stat().HP > 0) {
    return InvalidAction;
  } else {
    Stat earning {0, 0, 0, 0, 0, 0, 6};
    movedby->change_Stat(earning);
    return ValidAction;
  }
}

bool Hoard_d::move(Cell *object) {
  return InvalidAction;
}

