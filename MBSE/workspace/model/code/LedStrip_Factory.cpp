#include "LedStrip_Factory.h"
#include "LedStrip_Factory_Interface.h"

LedStrip_Interface LedStrip_Factory::create(EByte pin, AnimationCallback_t animationCallback, EInt numberOfLeds) {
    // Start of user code (don't remove the 'Start/End of user code' markers)

	return new LedStrip(pin, animationCallback, numberOfLeds);

    // End of user code
}
