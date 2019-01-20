#include "RH.h"
#include "hero.h"

using namespace std;

bool RH::known = false;


RH::RH():
  Potion{0, 10, 0, 0, 0, 0, 0} {}

RH::~RH() {}

string RH::print() {
  if (known) { return " RH"; }
  return "n Unknown Potion";
}

void RH::knowntype() {
  known = true;
}

bool RH::beused(Hero *usedby) {
	knowntype();
  	usedby->change_Stat(get_stat());
  	return ValidAction;
}
