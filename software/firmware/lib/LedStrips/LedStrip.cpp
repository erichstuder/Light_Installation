#include "LedStrip.h"

//TODO: weiter aussen ansiedeln
static const uint16_t LedsPerStrip = 15;


LedStrip::LedStrip(uint8_t pin, AnimationCallback_t animationCallback):
	strip(LedsPerStrip, pin, NEO_GRB + NEO_KHZ800, 1, 1)
{
	strip.init();
	strip.setBrightness(50);
	strip.setMode(FX_MODE_RAINBOW);
	strip.setSegment(0, 0, 14, FX_MODE_CUSTOM, ORANGE, 10);
	strip.start();
	strip.setCustomMode(animationCallback);
	/*strip.init();
	strip.setBrightness(100);
	strip.setSpeed(200);
	strip.setMode(FX_MODE_RAINBOW_CYCLE);
	strip.start();*/
}



void LedStrip::setPixelColor(uint8_t z, uint8_t r, uint8_t g, uint8_t b){
	strip.setPixelColor(z, r, g, b);
}


void LedStrip::animate(){
	// TODO: service hat einen Rückgabewert!
	strip.service();
}
