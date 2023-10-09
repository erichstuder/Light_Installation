#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "simulator.h"
#include "IAnimator.h"

class Animator_Mock: public IAnimator {
    public:
        void animate(const char* fileName) { isAnimating = true; }
        bool isAnimating = false;
};

static Animator_Mock animator_mock;

WHEN("^I start the simulator") {
    simulator(&animator_mock);
}

THEN("^the led animation starts rightaway") {
    EXPECT_TRUE(animator_mock.isAnimating);
}


GIVEN("^the simulator is running") { FAIL(); }

GIVEN("^the animation is running") { FAIL(); }

THEN("^the cube can be rotated with the mouse") { FAIL(); }
