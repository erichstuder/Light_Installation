#pragma once

#include <stdint.h>

typedef struct{
	uint8_t x, y, z;
} Pixel_t;

typedef struct{
	uint8_t r, g, b;
} Color_t;

class I_LedPattern{
	public:
		const Pixel_t MinPixel = {0, 0, 0};
		const Pixel_t MaxPixel = {5, 5, 15};
		const Pixel_t CenterPixel = {2, 2, 7};
		virtual uint16_t getIterations() = 0;
		virtual Color_t getColor(Pixel_t pixel, uint16_t iteration) = 0;
};
