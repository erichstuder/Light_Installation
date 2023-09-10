#pragma once

#include "LedStrip.h"

/*class LedStrips{
	public:
		LedStrips();
		void setPattern(const char* name);
		void animate();
	private:
		LedStrip ledStrips[25];
};*/

namespace LedStrips{
	void setup();
	void setPattern(const char* name);
	void animate();
}
