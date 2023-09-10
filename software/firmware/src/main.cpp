#include <Arduino.h>
#include "LedStrips.h"


/*WS2812FX ledStrips[] = {
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
/*
typedef struct{
	uint8_t x, y, z;
} Pixel_t;

typedef struct{
	uint8_t r, g, b;
} Color_t;

static Color_t running_light(Pixel_t pixel, uint8_t iteration_count){
	//TODO: assert that pixel.z is of same type as interation_count?
	if(pixel.z == iteration_count % Leds_per_strip){
		return {255, 0, 0};
	}
	return {0, 0, 0};
}*/

/*static uint16_t myCustomEffect(uint8_t id) {
	static uint8_t iteration = 0;
	WS2812FX &strip = ledStrips[id];
	for(uint8_t n=0; n<15; n++){
		if(n == iteration % 15){
			strip.setPixelColor(n, 255, 0, 0);
		}
		else{
			strip.setPixelColor(n, 0, 0, 0);
		}
	}

	if(id == 14){
		iteration++;
	}

	return strip.getSpeed();
}*/

/*
static uint16_t custom_mode_strip_0(){ return myCustomEffect(0); }
static uint16_t custom_mode_strip_1(){ return myCustomEffect(1); }
static uint16_t custom_mode_strip_2(){ return myCustomEffect(2); }
static uint16_t custom_mode_strip_3(){ return myCustomEffect(3); }
static uint16_t custom_mode_strip_4(){ return myCustomEffect(4); }
static uint16_t custom_mode_strip_5(){ return myCustomEffect(5); }
static uint16_t custom_mode_strip_6(){ return myCustomEffect(6); }
static uint16_t custom_mode_strip_7(){ return myCustomEffect(7); }
static uint16_t custom_mode_strip_8(){ return myCustomEffect(8); }
static uint16_t custom_mode_strip_9(){ return myCustomEffect(9); }
static uint16_t custom_mode_strip_10(){ return myCustomEffect(10); }
static uint16_t custom_mode_strip_11(){ return myCustomEffect(11); }
static uint16_t custom_mode_strip_12(){ return myCustomEffect(12); }
static uint16_t custom_mode_strip_13(){ return myCustomEffect(13); }
static uint16_t custom_mode_strip_14(){ return myCustomEffect(14); }
static uint16_t custom_mode_strip_15(){ return myCustomEffect(15); }
static uint16_t custom_mode_strip_16(){ return myCustomEffect(16); }
static uint16_t custom_mode_strip_17(){ return myCustomEffect(17); }
static uint16_t custom_mode_strip_18(){ return myCustomEffect(18); }
static uint16_t custom_mode_strip_19(){ return myCustomEffect(19); }
static uint16_t custom_mode_strip_20(){ return myCustomEffect(20); }
static uint16_t custom_mode_strip_21(){ return myCustomEffect(21); }
static uint16_t custom_mode_strip_22(){ return myCustomEffect(22); }
static uint16_t custom_mode_strip_23(){ return myCustomEffect(23); }
static uint16_t custom_mode_strip_24(){ return myCustomEffect(24); }*/

//static LedStrips ledStrips;

//void setup(){
	
	///LedStrips::setPattern("Wave");

	//ledStrips

	/*for(WS2812FX &strip : ledStrips){
		strip.init();
		strip.setBrightness(50);
		//strip.setMode(FX_MODE_STATIC);
		//strip.setCustomMode(myCustomEffect);
		strip.setSegment(0, 0, 14, FX_MODE_CUSTOM, ORANGE, 10);
		strip.start();
	}
	ledStrips[0].setCustomMode(custom_mode_strip_0);
	ledStrips[1].setCustomMode(custom_mode_strip_1);
	ledStrips[2].setCustomMode(custom_mode_strip_2);
	ledStrips[3].setCustomMode(custom_mode_strip_3);
	ledStrips[4].setCustomMode(custom_mode_strip_4);
	ledStrips[5].setCustomMode(custom_mode_strip_5);
	ledStrips[6].setCustomMode(custom_mode_strip_6);
	ledStrips[7].setCustomMode(custom_mode_strip_7);
	ledStrips[8].setCustomMode(custom_mode_strip_8);
	ledStrips[9].setCustomMode(custom_mode_strip_9);
	ledStrips[10].setCustomMode(custom_mode_strip_10);
	ledStrips[11].setCustomMode(custom_mode_strip_11);
	ledStrips[12].setCustomMode(custom_mode_strip_12);
	ledStrips[13].setCustomMode(custom_mode_strip_13);
	ledStrips[14].setCustomMode(custom_mode_strip_14);
	ledStrips[15].setCustomMode(custom_mode_strip_15);
	ledStrips[16].setCustomMode(custom_mode_strip_16);
	ledStrips[17].setCustomMode(custom_mode_strip_17);
	ledStrips[18].setCustomMode(custom_mode_strip_18);
	ledStrips[19].setCustomMode(custom_mode_strip_19);
	ledStrips[20].setCustomMode(custom_mode_strip_20);
	ledStrips[21].setCustomMode(custom_mode_strip_21);
	ledStrips[22].setCustomMode(custom_mode_strip_22);
	ledStrips[23].setCustomMode(custom_mode_strip_23);
	ledStrips[24].setCustomMode(custom_mode_strip_24);*/
//}


void setup(){
	LedStrips::setup();
}

void loop(){
	LedStrips::animate();
}




/*
#include <WS2812FX.h>

#define LED_COUNT 30
#define LED_PIN 12

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800, 1, 1);

void setup() {
  ws2812fx.init();
  ws2812fx.setBrightness(100);
  ws2812fx.setSpeed(200);
  ws2812fx.setMode(FX_MODE_RAINBOW_CYCLE);
  ws2812fx.start();
}

void loop() {
  ws2812fx.service();
}*/
