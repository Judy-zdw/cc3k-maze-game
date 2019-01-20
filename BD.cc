#include "BD.h"
#include "hero.h"
using namespace std;

bool BD::known = false;

BD::BD():
  Potion{0, 0, 0, 0, 0, 5, 0} {}

string BD::print() {
  if (known) { return " BD"; }
  return "n Unknown Potion";
}

BD::~BD() {}

void BD::knowntype() {
  known = true;
}

bool BD::beused(Hero *usedby) {
        knowntype();
  	usedby->change_Stat(get_stat());
  	return ValidAction;
}
