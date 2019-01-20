#ifndef CELL_H__
#define CELL_H__
#include <string>
#include <memory>
#include <math.h>
#include <iostream>
#include "const.h"



class Hero;
class Enemy;
class Dragon;
class Hoard_d;
class Unit;

class Cell {
 public:
  Unit *something; // the unit that stands on cell, nullptr if no one on it
  bool enemy; // determine whether there is an enemy standing on it

  Cell(Unit *something=nullptr, bool enemy = false); // ctor
  virtual ~Cell() = 0; // make the class abstract
  bool move(Cell *subject); // move from this to subject, success or not
  bool bemoved(Hero *subject); // be moved by something in subject cell, success or not
  bool bemoved(Enemy *subject);
  bool bemoved(Dragon *subject);
  bool bemoved(Hoard_d *subject);
  virtual bool touched(Unit *subject); // a construction be attacked or used by others, return whether it success.
  virtual bool reached(Hero *movedby) = 0; // a construction be moved by others, return whether it success.
  virtual bool reached(Enemy *movedby);
  bool use(Cell *object); // use something in object cell, success or not
  virtual int attack(Cell *object); // attack something in object cell, success or not. it returns 
  virtual bool dropto();                          // whether the object is died and who is it.
  void refresh();
  int notify(Cell *object);
  virtual std::string printlogo();
  std::string print();
};


#endif
