#ifndef _HOARD_M_H
#define _HOARD_M_H

#include "treasure.h"

//The hoard dropped by Merchant when the Merchant is killed.
class Hoard_m: public Treasure {
	public:
                std::string print() override;
		Hoard_m();
		~Hoard_m();
};

#endif
