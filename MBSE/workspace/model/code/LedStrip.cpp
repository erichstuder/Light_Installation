#include "LedStrip.h"

LedStrip::LedStrip(uint8_t pin, AnimationCallback_t animationCallback, uint16_t numberOfLeds)
// Start of user code LedStrip initializers (don't remove the 'Start/End of user code' markers)

    :
    strip(numberOfLeds, pin, NEO_GRB + NEO_KHZ800, 1, 1)

// End of user code
{
    // Start of user code LedStrip body (don't remove the 'Start/End of user code' markers)

    strip.init();
    strip.setBrightness(50);
    strip.setMode(FX_MODE_RAINBOW);
    strip.setSegment(0, 0, 14, FX_MODE_CUSTOM, ORANGE, 10);
    strip.start();
    strip.setCustomMode(animationCallback);

    // End of user code
}


void LedStrip::setPixelColor(uint8_t z, uint8_t r, uint8_t g, uint8_t b) {
    // Start of user code setPixelColor (don't remove the 'Start/End of user code' markers)

    strip.setPixelColor(z, r, g, b);

    // End of user code
}

void LedStrip::animate() {
    // Start of user code animate (don't remove the 'Start/End of user code' markers)

    // service() has an undocumented bool return value => ignored.
    strip.service();

    // End of user code
}

