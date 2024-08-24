#pragma once

#include "LedStrip_Factory_Interface.h"


class LedStrip_Factory : public LedStrip_Factory_Interface {
    public:
        ~LedStrip_Factory() {}
        LedStrip_Interface create(EByte pin, AnimationCallback_t animationCallback, EInt numberOfLeds);
    private:
};
