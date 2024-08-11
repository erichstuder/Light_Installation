// mock
#include "CppUTestExt/MockSupport.h"

#include "WS2812FX.h"

WS2812FX::WS2812FX(uint16_t num_leds, uint8_t pin, neoPixelType type,
                   uint8_t max_num_segments,
                   uint8_t max_num_active_segments)
{
	mock().actualCall("WS2812FX::WS2812FX")
		.withIntParameter("num_leds", num_leds)
		.withIntParameter("pin", pin)
		.withIntParameter("type", type)
		.withIntParameter("max_num_segments", max_num_segments)
		.withIntParameter("max_num_active_segments", max_num_active_segments);
}


void WS2812FX::init() {
	mock().actualCall("WS2812FX::init");
}


void WS2812FX::start() {
	mock().actualCall("WS2812FX::start");
}


void WS2812FX::setMode(uint8_t m) {
	mock().actualCall("WS2812FX::setMode")
		.withIntParameter("m", m);
}


void WS2812FX::setCustomMode(uint16_t (*p)()) {
	mock().actualCall("WS2812FX::setCustomMode")
		.withFunctionPointerParameter("p", (void(*)())p);
}


void WS2812FX::setBrightness(uint8_t b) {
	mock().actualCall("WS2812FX::setBrightness")
		.withIntParameter("b", b);
}


void WS2812FX::setSegment(uint8_t n, uint16_t start, uint16_t stop, uint8_t mode, uint32_t color, uint16_t speed) {
	mock().actualCall("WS2812FX::setSegment")
		.withIntParameter("n", n)
		.withIntParameter("start", start)
		.withIntParameter("stop", stop)
		.withIntParameter("mode", mode)
		.withIntParameter("color", color)
		.withIntParameter("speed", speed);
}


void WS2812FX::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b) {
	mock().actualCall("WS2812FX::setPixelColor")
        .withIntParameter("n", n)
        .withIntParameter("r", r)
        .withIntParameter("g", g)
        .withIntParameter("b", b);
}


bool WS2812FX::service() {
	mock().actualCall("WS2812FX::service");
	return false; //constant as it is ignored anyway.
}
