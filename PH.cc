#include "PH.h"
#include "hero.h"

using namespace std;

bool PH::known = false;


void PH::knowntype() {
  known = true;
}

PH::PH():
  Potion{0, -10, 0, 0, 0, 0, 0} {}

string PH::print() {
  if (known) { return " PH"; }
  return "n Unknown Potion";
}

PH::~PH() {}

bool PH::beused(Hero *usedby) {
	knowntype();
  	usedby->change_Stat(get_stat());
  	return ValidAction;
}
