// mock
#pragma once

#include <cstdint>

#define ORANGE (uint32_t)0xFF3000

// see: Adafruit_NeoPixel.h
#define NEO_GRB ((1 << 6) | (1 << 4) | (0 << 2) | (2))
#define NEO_KHZ800 0x0000
typedef uint16_t neoPixelType;


// see: modes_arduino.h
#define FX_MODE_RAINBOW 11
#define FX_MODE_CUSTOM  57


class WS2812FX {
	public:
		WS2812FX(uint16_t num_leds, uint8_t pin, neoPixelType type,
      			 uint8_t max_num_segments,
      			 uint8_t max_num_active_segments);
		void init();
		void start();
		void setMode(uint8_t m);
		void setCustomMode(uint16_t (*p)());
		void setBrightness(uint8_t b);
		void setSegment(uint8_t n, uint16_t start, uint16_t stop, uint8_t mode, uint32_t color, uint16_t speed);
		void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
		bool service();
};



	


	
	