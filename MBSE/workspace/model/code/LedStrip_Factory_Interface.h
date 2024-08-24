#pragma once

#include "LedStrip_Interface.h"


class LedStrip_Factory_Interface {
    public:
        virtual ~LedStrip_Factory_Interface() {}
        virtual LedStrip_Interface create(EByte pin, AnimationCallback_t animation_callback, EInt number_of_leds) = 0;
};
