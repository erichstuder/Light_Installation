#include <Arduino.h>
#include <WS2812FX.h>

#define LED_COUNT 150
#define LED_PIN 13

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
WS2812FX ws2812fx2 = WS2812FX(LED_COUNT, 6, NEO_GRB + NEO_KHZ800);

void setup(){
	ws2812fx.init();
	ws2812fx.setBrightness(255);
	ws2812fx.setSpeed(1000);
	ws2812fx.setMode(FX_MODE_CHASE_RAINBOW);
	//ws2812fx.setColor(WHITE);
	ws2812fx.start();


	pinMode(7, OUTPUT);
	digitalWrite(7, LOW);
	ws2812fx2.init();
	ws2812fx2.setBrightness(255);
	ws2812fx2.setSpeed(1000);
	ws2812fx2.setMode(FX_MODE_RAINBOW_CYCLE);
	//ws2812fx2.setColor(WHITE);
	ws2812fx2.start();
}

void loop(){
	ws2812fx.service();
	ws2812fx2.service();
}
