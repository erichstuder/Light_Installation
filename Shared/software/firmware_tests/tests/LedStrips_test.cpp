#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "LedStrips.h"
#include "LedStrip_Factory_Mock.h"

static LedStrip_Factory_Interface* ledStrip_factory_mock;

TEST_GROUP(LedStrips) {
    void setup() {
        ledStrip_factory_mock = new LedStrip_Factory_Mock();
    }

    void teardown() {
        delete ledStrip_factory_mock;
        mock().checkExpectations();
        mock().clear();
    }
};


TEST(LedStrips, setup) {
    const uint8_t Pins[] = {15, 16, 14, 17, 18, 6, 5, 7, 4, 3, 11, 10, 12, 9, 8, 52, 44, 50, 46, 48, 42, 34, 40, 36, 38};

    for(uint8_t pin : Pins) {
        mock().expectOneCall("LedStrip_Factory_Mock::create")
            .withIntParameter("pin", pin)
            .withIntParameter("numberOfLeds", 15);
    }

	LedStrips::setup(ledStrip_factory_mock);
}


TEST(LedStrips, animate) {
    mock().expectNCalls(25, "LedStrip_mock::animate");
    mock().ignoreOtherCalls();

	LedStrips::setup(ledStrip_factory_mock);
    LedStrips::animate();
}
