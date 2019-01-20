#include "WD.h"
#include "hero.h"

using namespace std;

bool WD::known = false;


WD::WD():
  Potion{0, 0, 0, 0, 0, -5, 0} {}

string WD::print() {
  if (known) { return " WD";}
  return "n Unknown Potion";
}
WD::~WD() {}

void WD::knowntype() {
  known = true;
}

bool WD::beused(Hero *usedby) {
	knowntype();
  	usedby->change_Stat(get_stat());
  	return ValidAction;
}

