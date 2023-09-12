#include "CppUTest/TestHarness.h"

#include "LedStrip.h"

/*extern "C"
{
#include "Example.h"
}*/

static uint16_t dummy() {
    return 42;
}

TEST_GROUP(LedStrip)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(LedStrip, service)
{
    LedStrip ledStrip(0, dummy);
    
    ledStrip.animate();

    //LONGS_EQUAL(22, 22);
}

