#include "nothing.h"
#include "unit.h"

using namespace std;

Nothing::Nothing(Unit* something, bool enemy):
Cell{something, enemy} {}

Nothing::~Nothing() {delete something;}

bool Nothing::reached(Hero *movedby) {
  return InvalidAction;
}


string Nothing::printlogo() { 
  if (something) { return something->printlogo(); }
  return " "; 
}
