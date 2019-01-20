#include "doorway.h"
#include "unit.h"

using namespace std;

Doorway::Doorway(Unit* something, bool enemy):
Cell{something, enemy} {}

Doorway::~Doorway() { 
  if (something) { delete something; }
}

bool Doorway::reached(Hero* movedby) {
  return ValidAction;
}

string Doorway::printlogo() { 
  if (something) { return something->printlogo(); }
  return "+";
}


