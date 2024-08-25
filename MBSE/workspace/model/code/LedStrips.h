#pragma once

#include "LedStrip_Factory_Interface.h"
#include "Wave.h"
#include "RunningLight.h"
#include <stdint.h>


namespace LedStrips {
    void setup(LedStrip_Factory_Interface ledStrip_factory);
    void animate();
}
