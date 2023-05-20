#include <Arduino.h>
//#include <WS2812FX.h>
#include "../rhapsody/firmware/Component/Config/Application.h"

/*
#define Leds_per_strip 15

//see schematic for connector names
static const uint8_t Leds_J1_1 = 15;
static const uint8_t Leds_J1_2 = 16;
static const uint8_t Leds_J1_3 = 14;
static const uint8_t Leds_J1_4 = 17;
static const uint8_t Leds_J1_5 = 18;
static const uint8_t Leds_J2_1 = 6;
static const uint8_t Leds_J2_2 = 5;
static const uint8_t Leds_J2_3 = 7;
static const uint8_t Leds_J2_4 = 4;
static const uint8_t Leds_J2_5 = 3;
static const uint8_t Leds_J3_1 = 11;
static const uint8_t Leds_J3_2 = 10;
static const uint8_t Leds_J3_3 = 12;
static const uint8_t Leds_J3_4 = 9;
static const uint8_t Leds_J3_5 = 8;
static const uint8_t Leds_J4_1 = 52;
static const uint8_t Leds_J4_2 = 44;
static const uint8_t Leds_J4_3 = 50;
static const uint8_t Leds_J4_4 = 46;
static const uint8_t Leds_J4_5 = 48;
static const uint8_t Leds_J5_1 = 42;
static const uint8_t Leds_J5_2 = 34;
static const uint8_t Leds_J5_3 = 40;
static const uint8_t Leds_J5_4 = 36;
static const uint8_t Leds_J5_5 = 38;


WS2812FX ledStrips[] = {
	WS2812FX(Leds_per_strip, Leds_J1_1, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J1_2, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J1_3, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J1_4, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J1_5, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J2_1, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J2_2, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J2_3, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J2_4, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J2_5, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J3_1, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J3_2, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J3_3, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J3_4, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J3_5, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J4_1, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J4_2, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J4_3, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J4_4, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J4_5, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J5_1, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J5_2, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J5_3, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J5_4, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_per_strip, Leds_J5_5, NEO_GRB + NEO_KHZ800, 1, 1),
};*/

Application* application;

void setup(){
	/*for(WS2812FX &strip : ledStrips){
		strip.init();
		strip.setBrightness(255);
		strip.setSpeed(1000);
		strip.setMode(FX_MODE_CHASE_RAINBOW);
		strip.start();
	}*/

	//blink = Blink();

	application = new Application();
}

void loop(){
	/*for(WS2812FX &strip : ledStrips){
		strip.service();
	}*/

	/*blink.led_on();
	delay(500);
	blink.led_off();
	delay(500);*/

	application->tick();
}
