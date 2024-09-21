#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

#include "simulator.h"
#include "Wave.h"
#include "Animator_Interface.h"

class Animator_Mock: public Animator_Interface {
    public:
        void animate(const char* fileName) { isAnimating = true; }
        bool isAnimating = false;
};

static Animator_Mock animator_mock;

WHEN("^I start the simulator$") {
    Wave pattern;
    simulator(&pattern, &animator_mock);
}

THEN("^the led animation starts rightaway$") {
    EXPECT_TRUE(animator_mock.isAnimating);
}


bool exception_thrown = false;

WHEN("^I start the simulator without an LED pattern$") {
    try {
        simulator(nullptr, &animator_mock);
    } catch (const std::invalid_argument&) {
        exception_thrown = true;
    }
}

THEN("^an error happens$") {
    EXPECT_TRUE(exception_thrown);
}
