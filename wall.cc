#include "wall.h"
#include "unit.h"

using namespace std;

Wall::Wall(Unit* something, bool enemy, bool vertical):
Cell{something, enemy}, vertical{vertical} {}

Wall::~Wall() {delete something;}

bool Wall::reached(Hero *moved) {
  return InvalidAction;
}

string Wall::printlogo() {
  if (something) { return something->printlogo(); }
  if (vertical) { return "|"; }
  return "-";
}
