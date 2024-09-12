#pragma once

#include "LedPattern_Interface.h"

class Wave: public LedPattern_Interface {
	public:
		uint16_t getIterations();
		Color_t getColor(Pixel_t pixel, uint16_t iteration);
};
