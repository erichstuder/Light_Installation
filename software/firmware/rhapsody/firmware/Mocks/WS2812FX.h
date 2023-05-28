#pragma once

#include <stdint.h> //TODO: is it a good idea to include this here? for example for uint8_t

//TODO: es wäre schöner diese defines direkt aus der Library zu verwenden. Oder?
#define NEO_GRB 1

#define NEO_KHZ800 2

#define FX_MODE_CHASE_RAINBOW 33

typedef uint16_t neoPixelType;

class WS2812FX{
public:
	WS2812FX(uint16_t num_leds, uint8_t pin, neoPixelType type,
      uint8_t max_num_segments,
      uint8_t max_num_active_segments);
	WS2812FX();
	void service();
	void init();
	void setBrightness(uint8_t b);
	void setSpeed(uint16_t s);
	void setMode(uint8_t m);
	void start();
};
