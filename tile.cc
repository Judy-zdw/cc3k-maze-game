#include "tile.h"
#include "unit.h"
using namespace std;

bool Tile::dropto() {
	return ValidAction;
}

Tile::Tile(Unit* something, bool enemy):
Cell{something, enemy} {}

Tile::~Tile() {
  if (something) delete something;
}

bool Tile::reached(Hero* movedby) {
  return ValidAction;
}

bool Tile::reached(Enemy* movedby) {
  return ValidAction;
}

string Tile::printlogo() { 
	if(something) {
		return something->printlogo();
	}else {
		return "."; 
	}
}
