#include "hoard_m.h"
using namespace std;

Hoard_m::Hoard_m():
  Treasure{0, 0, 0, 0, 0, 0, 4} {};

Hoard_m::~Hoard_m() {};

string Hoard_m::print() {
  return "Merchant Hoard";  
}
