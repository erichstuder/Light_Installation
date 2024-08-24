#pragma once

#include "LedStrip_Interface.h"
#include <WS2812FX.h>

typedef uint16_t (*AnimationCallback_t)();

class LedStrip : public LedStrip_Interface {
    public:
        ~LedStrip() {}
        void LedStrip(uint8_t pin, AnimationCallback_t animationCallback, EInt numberOfLeds);
        void setPixelColor(EByte z, EByte r, EByte g, EByte b);
        void animate();
    private:
        WS2812FX strip;
        uint8_t id;
};
