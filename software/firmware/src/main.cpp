#include <Arduino.h>
#include <WS2812FX.h>

#define Leds_count 15

#define Leds1_pin 45
#define Leds2_pin 35
#define Leds3_pin 23
#define Leds4_pin 47
#define Leds5_pin 37
#define Leds6_pin 25
#define Leds7_pin 49
#define Leds8_pin 39
#define Leds9_pin 27
#define Leds10_pin 51
#define Leds11_pin 41
#define Leds12_pin 29
#define Leds13_pin 50
#define Leds14_pin 40
#define Leds15_pin 28
#define Leds16_pin 48
#define Leds17_pin 38
#define Leds18_pin 26
#define Leds19_pin 46
#define Leds20_pin 36
#define Leds21_pin 24
#define Leds22_pin 44
#define Leds23_pin 34
#define Leds24_pin 22
#define Leds25_pin 42


WS2812FX ledStrips[] = {
	WS2812FX(Leds_count, Leds1_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds2_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds3_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds4_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds5_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds6_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds7_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds8_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds9_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds10_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds11_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds12_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds13_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds14_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds15_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds16_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds17_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds18_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds19_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds20_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds21_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds22_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds23_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds24_pin, NEO_GRB + NEO_KHZ800, 1, 1),
	WS2812FX(Leds_count, Leds25_pin, NEO_GRB + NEO_KHZ800, 1, 1),
};

void setup(){
	for(WS2812FX &strip : ledStrips){
		strip.init();
		strip.setBrightness(255);
		strip.setSpeed(1000);
		strip.setMode(FX_MODE_CHASE_RAINBOW);
		strip.start();
	}
}

void loop(){
	for(WS2812FX &strip : ledStrips){
		strip.service();
	}
}
