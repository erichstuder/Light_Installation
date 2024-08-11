#pragma once

#include "LedStrip_Interface.h"

class LedStrip_Factory_Interface {
	public:
		virtual ~LedStrip_Factory_Interface() {}
		virtual LedStrip_Interface* create(uint8_t pin, AnimationCallback_t animationCallback, uint16_t numberOfLeds) = 0;
};
