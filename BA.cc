#include "BA.h"
#include "hero.h"
using namespace std;

bool BA::known = false;

BA::BA():
  Potion{0, 0, 0, 0, 5, 0, 0} {}

string BA::print() {
  if (known) { return " BA"; }
  return "n Unknown Potion";
}

void BA::knowntype() {
  known = true;
}

BA::~BA() {}

bool BA::beused(Hero *usedby) {
	knowntype();
  	usedby->change_Stat(get_stat());
  	return ValidAction;
}
