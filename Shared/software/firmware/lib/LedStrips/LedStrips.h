#pragma once

#include "LedStrip_Factory_Interface.h"

namespace LedStrips {
	void setup(LedStrip_Factory_Interface* ledStrip_factory);
	void setPattern(const char* name);
	void animate();
}
