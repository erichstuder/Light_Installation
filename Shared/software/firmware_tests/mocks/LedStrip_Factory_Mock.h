#pragma once

#include "LedStrip_Factory_Interface.h"

class LedStrip_Factory_Mock : public LedStrip_Factory_Interface {
	public:
		LedStrip_Interface* create(uint8_t pin, AnimationCallback_t animationCallback, uint16_t numberOfLeds);
		~LedStrip_Factory_Mock();
	private:
		LedStrip_Interface* ledStrip = nullptr;
};
