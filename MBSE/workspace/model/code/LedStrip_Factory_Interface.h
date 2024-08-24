#pragma once

#include "LedStrip_Interface.h"


class LedStrip_Factory_Interface {
    public:
        virtual ~LedStrip_Factory_Interface() {}
        virtual LedStrip_Interface create(uint8_t pin, AnimationCallback_t animation_callback, uint16_t number_of_leds) = 0;
};
