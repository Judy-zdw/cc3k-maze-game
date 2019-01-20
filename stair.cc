#include "stair.h"

using namespace std;

Stair::Stair(Unit* something, bool enemy):
Cell{something, enemy} {}

Stair::~Stair() {delete something;}

bool Stair::reached(Hero* movedby) {
  return ValidAction;
}

string Stair::printlogo() { return "\\"; }

