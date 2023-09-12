#pragma once

#include <WS2812FX.h>

typedef uint16_t (*AnimationCallback_t)();

class LedStrip{
	public:
		LedStrip(uint8_t pin, AnimationCallback_t animationCallback, uint16_t numberOfLeds);
		void setPixelColor(uint8_t z, uint8_t r, uint8_t g, uint8_t b);
		void animate();
	private:
		WS2812FX strip;
		uint8_t id;
		uint16_t animationCallback();
};
