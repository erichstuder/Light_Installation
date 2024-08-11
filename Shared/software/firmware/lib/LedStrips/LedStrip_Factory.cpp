#include "LedStrip_Factory.h"
#include "LedStrip.h"

LedStrip_Interface* LedStrip_Factory::create(uint8_t pin, AnimationCallback_t animationCallback, uint16_t numberOfLeds) {
	return new LedStrip(pin, animationCallback, numberOfLeds);
}
