#include "gold_s.h"
using namespace std;

Gold_s::Gold_s(): Treasure{0, 0, 0, 0, 0, 0, 1} {}

Gold_s::~Gold_s() {}

string Gold_s::print() {
  return "Small Gold";  
}
