#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "simulator.h"
#include "Animator_Interface.h"

class Animator_Mock: public Animator_Interface {
    public:
        void animate(const char* fileName) { isAnimating = true; }
        bool isAnimating = false;
};

static Animator_Mock animator_mock;

WHEN("^I start the simulator") {
    simulator(&animator_mock);
}

THEN("^a 3D model of the Light Installation is shown$") {
    pending();
}

THEN("^the led animation starts rightaway") {
    EXPECT_TRUE(animator_mock.isAnimating);
}
