#include "LedStrips.h"
#include "LedStrip_Factory_Interface.h"
#include "Wave.h"
#include "RunningLight.h"

#include <stdint.h>

namespace LedStrips {

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

	static const uint16_t LedsPerStrip = 15;

	static Wave pattern;

	static uint16_t iteration=0;

	//TODO: kann man diese Deklaration eliminieren?
	static uint16_t animation(uint8_t x, uint8_t y);

	static uint16_t animationCallback_x0y0(){ return animation(0, 0); }
	static uint16_t animationCallback_x0y1(){ return animation(0, 1); }
	static uint16_t animationCallback_x0y2(){ return animation(0, 2); }
	static uint16_t animationCallback_x0y3(){ return animation(0, 3); }
	static uint16_t animationCallback_x0y4(){ return animation(0, 4); }
	static uint16_t animationCallback_x1y0(){ return animation(1, 0); }
	static uint16_t animationCallback_x1y1(){ return animation(1, 1); }
	static uint16_t animationCallback_x1y2(){ return animation(1, 2); }
	static uint16_t animationCallback_x1y3(){ return animation(1, 3); }
	static uint16_t animationCallback_x1y4(){ return animation(1, 4); }
	static uint16_t animationCallback_x2y0(){ return animation(2, 0); }
	static uint16_t animationCallback_x2y1(){ return animation(2, 1); }
	static uint16_t animationCallback_x2y2(){ return animation(2, 2); }
	static uint16_t animationCallback_x2y3(){ return animation(2, 3); }
	static uint16_t animationCallback_x2y4(){ return animation(2, 4); }
	static uint16_t animationCallback_x3y0(){ return animation(3, 0); }
	static uint16_t animationCallback_x3y1(){ return animation(3, 1); }
	static uint16_t animationCallback_x3y2(){ return animation(3, 2); }
	static uint16_t animationCallback_x3y3(){ return animation(3, 3); }
	static uint16_t animationCallback_x3y4(){ return animation(3, 4); }
	static uint16_t animationCallback_x4y0(){ return animation(4, 0); }
	static uint16_t animationCallback_x4y1(){ return animation(4, 1); }
	static uint16_t animationCallback_x4y2(){ return animation(4, 2); }
	static uint16_t animationCallback_x4y3(){ return animation(4, 3); }
	static uint16_t animationCallback_x4y4(){ return animation(4, 4); }

	static LedStrip_Interface* ledStrips[25];


	static uint16_t animation(uint8_t x, uint8_t y) {
		for(uint8_t z=0; z<pattern.MaxPixel.z; z++){
			Color_t color = pattern.getColor({x, y, z}, iteration);
			ledStrips[x*5+y]->setPixelColor(z, color.r, color.g, color.b);
		}

		if(x==4 && y==4){
			iteration++;
		}

		return 1;
	}


	void setup(LedStrip_Factory_Interface* ledStrip_factory) {
		ledStrips[0]  = ledStrip_factory->create(Leds_J1_1, animationCallback_x4y0, LedsPerStrip);
		ledStrips[1]  = ledStrip_factory->create(Leds_J1_2, animationCallback_x4y1, LedsPerStrip);
		ledStrips[2]  = ledStrip_factory->create(Leds_J1_3, animationCallback_x4y2, LedsPerStrip);
		ledStrips[3]  = ledStrip_factory->create(Leds_J1_4, animationCallback_x4y3, LedsPerStrip);
		ledStrips[4]  = ledStrip_factory->create(Leds_J1_5, animationCallback_x4y4, LedsPerStrip);
		ledStrips[5]  = ledStrip_factory->create(Leds_J2_1, animationCallback_x3y0, LedsPerStrip);
		ledStrips[6]  = ledStrip_factory->create(Leds_J2_2, animationCallback_x3y1, LedsPerStrip);
		ledStrips[7]  = ledStrip_factory->create(Leds_J2_3, animationCallback_x3y2, LedsPerStrip);
		ledStrips[8]  = ledStrip_factory->create(Leds_J2_4, animationCallback_x3y3, LedsPerStrip);
		ledStrips[9]  = ledStrip_factory->create(Leds_J2_5, animationCallback_x3y4, LedsPerStrip);
		ledStrips[10] = ledStrip_factory->create(Leds_J3_1, animationCallback_x2y0, LedsPerStrip);
		ledStrips[11] = ledStrip_factory->create(Leds_J3_2, animationCallback_x2y1, LedsPerStrip);
		ledStrips[12] = ledStrip_factory->create(Leds_J3_3, animationCallback_x2y2, LedsPerStrip);
		ledStrips[13] = ledStrip_factory->create(Leds_J3_4, animationCallback_x2y3, LedsPerStrip);
		ledStrips[14] = ledStrip_factory->create(Leds_J3_5, animationCallback_x2y4, LedsPerStrip);
		ledStrips[15] = ledStrip_factory->create(Leds_J4_1, animationCallback_x1y0, LedsPerStrip);
		ledStrips[16] = ledStrip_factory->create(Leds_J4_2, animationCallback_x1y1, LedsPerStrip);
		ledStrips[17] = ledStrip_factory->create(Leds_J4_3, animationCallback_x1y2, LedsPerStrip);
		ledStrips[18] = ledStrip_factory->create(Leds_J4_4, animationCallback_x1y3, LedsPerStrip);
		ledStrips[19] = ledStrip_factory->create(Leds_J4_5, animationCallback_x1y4, LedsPerStrip);
		ledStrips[20] = ledStrip_factory->create(Leds_J5_1, animationCallback_x0y0, LedsPerStrip);
		ledStrips[21] = ledStrip_factory->create(Leds_J5_2, animationCallback_x0y1, LedsPerStrip);
		ledStrips[22] = ledStrip_factory->create(Leds_J5_3, animationCallback_x0y2, LedsPerStrip);
		ledStrips[23] = ledStrip_factory->create(Leds_J5_4, animationCallback_x0y3, LedsPerStrip);
		ledStrips[24] = ledStrip_factory->create(Leds_J5_5, animationCallback_x0y4, LedsPerStrip);
	}


	void animate() {
		for(LedStrip_Interface* ledStrip : ledStrips) {
			ledStrip->animate();
		}
	}
}
