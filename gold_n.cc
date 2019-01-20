#include "gold_n.h"
using namespace std;

Gold_n::Gold_n(): Treasure{0, 0, 0, 0, 0, 0, 2} {};

Gold_n::~Gold_n() {};

string Gold_n::print() {
  return "Normal Gold";  
}
