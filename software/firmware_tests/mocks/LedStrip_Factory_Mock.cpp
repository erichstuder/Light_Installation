#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "LedStrip_Factory_Mock.h"


class LedStrip_mock : public LedStrip_Interface{
	public:
		void setPixelColor(uint8_t z, uint8_t r, uint8_t g, uint8_t b) {}
		void animate() { mock().actualCall("LedStrip_mock::animate"); }
};


LedStrip_Interface* LedStrip_Factory_Mock::create(uint8_t pin, AnimationCallback_t animationCallback, uint16_t numberOfLeds) {
	mock().actualCall("LedStrip_Factory_Mock::create")
		.withIntParameter("pin", pin)
		.withIntParameter("numberOfLeds", numberOfLeds);

	CHECK(animationCallback != nullptr);

	if(ledStrip == nullptr) {
		ledStrip = new LedStrip_mock();
	}

	return ledStrip;
}


LedStrip_Factory_Mock::~LedStrip_Factory_Mock() {
	if(ledStrip != nullptr) {
		delete ledStrip;
	}
}