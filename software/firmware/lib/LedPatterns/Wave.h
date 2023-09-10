#pragma once

#include "I_LedPattern.h"

class Wave: public I_LedPattern{
	public:
		uint16_t getIterations();
		Color_t getColor(Pixel_t pixel, uint16_t iteration);
};
