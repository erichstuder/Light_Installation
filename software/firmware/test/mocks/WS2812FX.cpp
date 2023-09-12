// mock
#include "WS2812FX.h"

WS2812FX::WS2812FX(uint16_t num_leds, uint8_t pin, neoPixelType type,
      			 uint8_t max_num_segments,
      			 uint8_t max_num_active_segments){}
void WS2812FX::init(){}
void WS2812FX::start(){}
void WS2812FX::setMode(uint8_t m){}
void WS2812FX::setCustomMode(uint16_t (*p)()){}
void WS2812FX::setBrightness(uint8_t b){}
void WS2812FX::setSegment(uint8_t n, uint16_t start, uint16_t stop, uint8_t mode, uint32_t color, uint16_t speed){}
void WS2812FX::setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b){}
bool WS2812FX::service(){ return false; }
