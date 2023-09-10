#include "LedStrips.h"
#include "Wave.h"
#include "RunningLight.h"

#include <stdint.h>

namespace LedStrips{

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

	

	//typedef LedStrip* tt;
	//static tt ledStrips[25];

	static LedStrip* ledStrips[25];

	/*static LedStrip ledStrips[] = {
		LedStrip(Leds_J1_1, animationCallback_x4y0),
		LedStrip(Leds_J1_2, animationCallback_x4y1),
		LedStrip(Leds_J1_3, animationCallback_x4y2),
		LedStrip(Leds_J1_4, animationCallback_x4y3),
		LedStrip(Leds_J1_5, animationCallback_x4y4),
		LedStrip(Leds_J2_1, animationCallback_x3y0),
		LedStrip(Leds_J2_2, animationCallback_x3y1),
		LedStrip(Leds_J2_3, animationCallback_x3y2),
		LedStrip(Leds_J2_4, animationCallback_x3y3),
		LedStrip(Leds_J2_5, animationCallback_x3y4),
		LedStrip(Leds_J3_1, animationCallback_x2y0),
		LedStrip(Leds_J3_2, animationCallback_x2y1),
		LedStrip(Leds_J3_3, animationCallback_x2y2),
		LedStrip(Leds_J3_4, animationCallback_x2y3),
		LedStrip(Leds_J3_5, animationCallback_x2y4),
		LedStrip(Leds_J4_1, animationCallback_x1y0),
		LedStrip(Leds_J4_2, animationCallback_x1y1),
		LedStrip(Leds_J4_3, animationCallback_x1y2),
		LedStrip(Leds_J4_4, animationCallback_x1y3),
		LedStrip(Leds_J4_5, animationCallback_x1y4),
		LedStrip(Leds_J5_1, animationCallback_x0y0),
		LedStrip(Leds_J5_2, animationCallback_x0y1),
		LedStrip(Leds_J5_3, animationCallback_x0y2),
		LedStrip(Leds_J5_4, animationCallback_x0y3),
		LedStrip(Leds_J5_5, animationCallback_x0y4),
	};*/

	static uint16_t animation(uint8_t x, uint8_t y){
		for(uint8_t z=0; z<pattern.MaxPixel.z; z++){
			Color_t color = pattern.getColor({x, y, z}, iteration);
			ledStrips[x*5+y]->setPixelColor(z, color.r, color.g, color.b);
			//ledStrips[x*5+y]->setPixelColor(7, 0, 0, 255);
		}

		if(x==4 && y==4){
			iteration++;
		}

		return 1;
	}

	void setup(){
		ledStrips[0] = new LedStrip(Leds_J1_1, animationCallback_x4y0);
		ledStrips[1] = new LedStrip(Leds_J1_2, animationCallback_x4y1);
		ledStrips[2] = new LedStrip(Leds_J1_3, animationCallback_x4y2);
		ledStrips[3] = new LedStrip(Leds_J1_4, animationCallback_x4y3);
		ledStrips[4] = new LedStrip(Leds_J1_5, animationCallback_x4y4);
		ledStrips[5] = new LedStrip(Leds_J2_1, animationCallback_x3y0);
		ledStrips[6] = new LedStrip(Leds_J2_2, animationCallback_x3y1);
		ledStrips[7] = new LedStrip(Leds_J2_3, animationCallback_x3y2);
		ledStrips[8] = new LedStrip(Leds_J2_4, animationCallback_x3y3);
		ledStrips[9] = new LedStrip(Leds_J2_5, animationCallback_x3y4);
		ledStrips[10] = new LedStrip(Leds_J3_1, animationCallback_x2y0);
		ledStrips[11] = new LedStrip(Leds_J3_2, animationCallback_x2y1);
		ledStrips[12] = new LedStrip(Leds_J3_3, animationCallback_x2y2);
		ledStrips[13] = new LedStrip(Leds_J3_4, animationCallback_x2y3);
		ledStrips[14] = new LedStrip(Leds_J3_5, animationCallback_x2y4);
		ledStrips[15] = new LedStrip(Leds_J4_1, animationCallback_x1y0);
		ledStrips[16] = new LedStrip(Leds_J4_2, animationCallback_x1y1);
		ledStrips[17] = new LedStrip(Leds_J4_3, animationCallback_x1y2);
		ledStrips[18] = new LedStrip(Leds_J4_4, animationCallback_x1y3);
		ledStrips[19] = new LedStrip(Leds_J4_5, animationCallback_x1y4);
		ledStrips[20] = new LedStrip(Leds_J5_1, animationCallback_x0y0);
		ledStrips[21] = new LedStrip(Leds_J5_2, animationCallback_x0y1);
		ledStrips[22] = new LedStrip(Leds_J5_3, animationCallback_x0y2);
		ledStrips[23] = new LedStrip(Leds_J5_4, animationCallback_x0y3);
		ledStrips[24] = new LedStrip(Leds_J5_5, animationCallback_x0y4);
	}


	/*LedStrips::LedStrips():
		ledStrips({
			LedStrip(Leds_J1_1, animationCallback_0 ),
			LedStrip(Leds_J1_2, animationCallback_1 ),
			LedStrip(Leds_J1_3, animationCallback_2 ),
			LedStrip(Leds_J1_4, animationCallback_3 ),
			LedStrip(Leds_J1_5, animationCallback_4 ),
			LedStrip(Leds_J2_1, animationCallback_5 ),
			LedStrip(Leds_J2_2, animationCallback_6 ),
			LedStrip(Leds_J2_3, animationCallback_7 ),
			LedStrip(Leds_J2_4, animationCallback_8 ),
			LedStrip(Leds_J2_5, animationCallback_9 ),
			LedStrip(Leds_J3_1, animationCallback_10),
			LedStrip(Leds_J3_2, animationCallback_11),
			LedStrip(Leds_J3_3, animationCallback_12),
			LedStrip(Leds_J3_4, animationCallback_13),
			LedStrip(Leds_J3_5, animationCallback_14),
			LedStrip(Leds_J4_1, animationCallback_15),
			LedStrip(Leds_J4_2, animationCallback_16),
			LedStrip(Leds_J4_3, animationCallback_17),
			LedStrip(Leds_J4_4, animationCallback_18),
			LedStrip(Leds_J4_5, animationCallback_19),
			LedStrip(Leds_J5_1, animationCallback_20),
			LedStrip(Leds_J5_2, animationCallback_21),
			LedStrip(Leds_J5_3, animationCallback_22),
			LedStrip(Leds_J5_4, animationCallback_23),
			LedStrip(Leds_J5_5, animationCallback_24),
		})
	{}*/


	void setPattern(const char* name){
		return;
	}

	void animate(){
		for(LedStrip* ledStrip : ledStrips){
			ledStrip->animate();
		}
	}
}