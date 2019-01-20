#include "cell.h"
#include "unit.h"
#include <iostream>

#include <memory>
using namespace std;

Cell::Cell(Unit *something, bool enemy): something{something}, enemy{enemy} {};

Cell::~Cell() {}

bool Cell::dropto() {
	return InvalidAction;
}

bool Cell::move(Cell *object) {
  bool valid = something->move(object);
  if (valid) {
    something->action -= 2;
    object->something = something;
    something = nullptr;
  }
  return valid;
}

bool Cell::bemoved(Hero *subject) {
  if (something) {
    return something->bemoved(subject);
  } else {
    return reached(subject);
  }
}

bool Cell::bemoved(Enemy *subject) {
  if (something) {
    return something->bemoved(subject);
  } else {
    return reached(subject);
  }
}

bool Cell::bemoved(Dragon *subject) {
  return InvalidAction;
}

bool Cell::bemoved(Hoard_d *subject) {
  return InvalidAction;
}


bool Cell::reached(Enemy *movedby) { return InvalidAction; }

bool Cell::touched(Unit *subject) { return InvalidAction; }

bool Cell::use(Cell *object) {
  bool valid;
  if (!object->something) { valid = object->touched(something); }
  else { valid = something->use(object->something); }
  if (valid) {
    something->action -= 2;
  }
  return valid;
}

int Cell::attack(Cell *object) {
  int valid;
  if (!object->something) { valid = object->touched(something); 
  } else { valid = something->attack(object->something); }
  if (valid) {
    something->action -= 2;
  }
  return valid;
}

void Cell::refresh() {
  if (something) something->action = 2;
}

int Cell::notify(Cell *object) {
  if (!object->something) return 0;
  return something->notify(object->something);
}

string Cell::printlogo() {
  if (something) return something->printlogo();
}

string Cell::print() {
  if (something) return something->print();
}
