#include "LedStrip_Factory.h"

LedStrip_Interface LedStrip_Factory::create(uint8_t pin, AnimationCallback_t animationCallback, uint16_t numberOfLeds) {
    // Start of user code create (don't remove the 'Start/End of user code' markers)

    return new LedStrip(pin, animationCallback, numberOfLeds);

    // End of user code
}

