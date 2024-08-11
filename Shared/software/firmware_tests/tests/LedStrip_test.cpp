#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "LedStrip.h"

static uint16_t animationCallback_mock() {
    return 42;
}

LedStrip* ledStrip;

TEST_GROUP(LedStrip) {
    void setup() {
        mock().disable();
        ledStrip = new LedStrip(12, animationCallback_mock, 12);
        mock().enable();
    }

    void teardown() {
        mock().checkExpectations();
        mock().clear();
        delete ledStrip;
    }
};


TEST(LedStrip, LedStrip_constructor) {
    const uint8_t Pin = 12;
    const uint16_t NumberOfLeds = 55;

    delete ledStrip;
    mock().expectOneCall("WS2812FX::WS2812FX")
		.withIntParameter("num_leds", NumberOfLeds)
		.withIntParameter("pin", Pin)
		.withIntParameter("type", NEO_GRB + NEO_KHZ800)
		.withIntParameter("max_num_segments", 1)
		.withIntParameter("max_num_active_segments", 1);
    mock().expectOneCall("WS2812FX::init");
    mock().expectOneCall("WS2812FX::setBrightness")
        .withIntParameter("b", 50);
    mock().expectOneCall("WS2812FX::setMode")
        .withIntParameter("m", FX_MODE_RAINBOW);
    mock().expectOneCall("WS2812FX::setSegment")
		.withIntParameter("n", 0)
		.withIntParameter("start", 0)
		.withIntParameter("stop", 14)
		.withIntParameter("mode", FX_MODE_CUSTOM)
		.withIntParameter("color", ORANGE)
		.withIntParameter("speed", 10);
    mock().expectOneCall("WS2812FX::start");
    mock().expectOneCall("WS2812FX::setCustomMode")
        .withFunctionPointerParameter("p", (void(*)())animationCallback_mock);

    ledStrip = new LedStrip(Pin, animationCallback_mock, NumberOfLeds);
}


TEST(LedStrip, service) {
    mock().expectOneCall("WS2812FX::service");
    ledStrip->animate();
}


TEST(LedStrip, setPixelColor) {
    const uint8_t Z=1, R=2, G=3, B=4;

    mock().expectOneCall("WS2812FX::setPixelColor")
        .withIntParameter("n", Z)
        .withIntParameter("r", R)
        .withIntParameter("g", G)
        .withIntParameter("b", B);
    ledStrip->setPixelColor(Z, R, G, B);
}
