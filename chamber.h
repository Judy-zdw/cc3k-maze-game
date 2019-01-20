#ifndef _CHAMBER_H
#define _CHAMBER_H

#include <vector>
#include <sstream>
#include <string>
#include <fstream>

struct Chamber {
	// rects will store the rectangles, each rectangle is represented as (row, col, width, length)
	// where the (row, col) represent the left-top point of this rectangle on the map.
	std::vector<std::vector<int>> rects;
	bool stair;
};

#endif
