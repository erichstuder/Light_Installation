#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "LedStrip_Factory.h"


TEST_GROUP(LedStrip_Factory) {
    void setup() {}
    void teardown() {}
};


TEST(LedStrip_Factory, LedStrip_constructor) {
    mock().ignoreOtherCalls();

    LedStrip_Factory ledStrip_factory;
    LedStrip_Interface* ledStrip = ledStrip_factory.create(1, nullptr, 0);
    CHECK(ledStrip != nullptr);
    delete ledStrip;
}
