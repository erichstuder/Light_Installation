#pragma once

#include <WS2812FX.h>

typedef uint16_t (*AnimationCallback_t)();

class LedStrip_Interface {
	public:
		virtual ~LedStrip_Interface() {};
		virtual void setPixelColor(uint8_t z, uint8_t r, uint8_t g, uint8_t b) = 0;
		virtual void animate() = 0;
};
