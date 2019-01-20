#include "passway.h"
#include "unit.h"

using namespace std;

Passway::Passway(Unit* something, bool enemy):
Cell{something, enemy} {}

Passway::~Passway() {
  if (something) delete something;
}

bool Passway::reached(Hero* movedby) {
  return ValidAction;
}

string Passway::printlogo() { 
  if (something) { return something->printlogo(); }
  else return "#";
}
