#include "WA.h"
#include "hero.h"

using namespace std;

bool WA::known = false;

WA::WA():
  Potion{0, 0, 0, 0, -5, 0, 0} {}

string WA::print() {
  if (known) { return " WA"; }
  return "n Unknown Potion";
}

WA::~WA() {}

void WA::knowntype() {
  known = true;
}

bool WA::beused(Hero *usedby) {
	knowntype();
  	usedby->change_Stat(get_stat());
  	return ValidAction;
}
