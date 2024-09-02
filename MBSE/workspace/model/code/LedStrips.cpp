#include "LedStrips.h"

namespace LedStrips {

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
    static uint16_t iteration = 0;
    static LedStrip_Interface* ledStrips[25];


    static uint16_t animation(uint8_t x, uint8_t y) {
        // Start of user code animation (don't remove the 'Start/End of user code' markers)

        for(uint8_t z=0; z<pattern.MaxPixel.z; z++){
            Color_t color = pattern.getColor({x, y, z}, iteration);
            ledStrips[x*5+y]->setPixelColor(z, color.r, color.g, color.b);
        }

        if(x==4 && y==4){
            iteration++;
        }

        return 1;

        // End of user code
    }


    static uint16_t animationCallback_x0y0() {
        // Start of user code animationCallback_x0y0 (don't remove the 'Start/End of user code' markers)

        return animation(0, 0);

        // End of user code
    }


    static uint16_t animationCallback_x0y1() {
        // Start of user code animationCallback_x0y1 (don't remove the 'Start/End of user code' markers)

        return animation(0, 1);

        // End of user code
    }


    static uint16_t animationCallback_x0y2() {
        // Start of user code animationCallback_x0y2 (don't remove the 'Start/End of user code' markers)

        return animation(0, 2);

        // End of user code
    }


    static uint16_t animationCallback_x0y3() {
        // Start of user code animationCallback_x0y3 (don't remove the 'Start/End of user code' markers)

        return animation(0, 3);

        // End of user code
    }


    static uint16_t animationCallback_x0y4() {
        // Start of user code animationCallback_x0y4 (don't remove the 'Start/End of user code' markers)

        return animation(0, 4);

        // End of user code
    }


    static uint16_t animationCallback_x1y0() {
        // Start of user code animationCallback_x1y0 (don't remove the 'Start/End of user code' markers)

        return animation(1, 0);

        // End of user code
    }


    static uint16_t animationCallback_x1y1() {
        // Start of user code animationCallback_x1y1 (don't remove the 'Start/End of user code' markers)

        return animation(1, 1);

        // End of user code
    }


    static uint16_t animationCallback_x1y2() {
        // Start of user code animationCallback_x1y2 (don't remove the 'Start/End of user code' markers)

        return animation(1, 2);

        // End of user code
    }


    static uint16_t animationCallback_x1y3() {
        // Start of user code animationCallback_x1y3 (don't remove the 'Start/End of user code' markers)

        return animation(1, 3);

        // End of user code
    }


    static uint16_t animationCallback_x1y4() {
        // Start of user code animationCallback_x1y4 (don't remove the 'Start/End of user code' markers)

        return animation(1, 4);

        // End of user code
    }


    static uint16_t animationCallback_x2y0() {
        // Start of user code animationCallback_x2y0 (don't remove the 'Start/End of user code' markers)

        return animation(2, 0);

        // End of user code
    }


    static uint16_t animationCallback_x2y1() {
        // Start of user code animationCallback_x2y1 (don't remove the 'Start/End of user code' markers)

        return animation(2, 1);

        // End of user code
    }


    static uint16_t animationCallback_x2y2() {
        // Start of user code animationCallback_x2y2 (don't remove the 'Start/End of user code' markers)

        return animation(2, 2);

        // End of user code
    }


    static uint16_t animationCallback_x2y3() {
        // Start of user code animationCallback_x2y3 (don't remove the 'Start/End of user code' markers)

        return animation(2, 3);

        // End of user code
    }


    static uint16_t animationCallback_x2y4() {
        // Start of user code animationCallback_x2y4 (don't remove the 'Start/End of user code' markers)

        return animation(2, 4);

        // End of user code
    }


    static uint16_t animationCallback_x3y0() {
        // Start of user code animationCallback_x3y0 (don't remove the 'Start/End of user code' markers)

        return animation(3, 0);

        // End of user code
    }


    static uint16_t animationCallback_x3y1() {
        // Start of user code animationCallback_x3y1 (don't remove the 'Start/End of user code' markers)

        return animation(3, 1);

        // End of user code
    }


    static uint16_t animationCallback_x3y2() {
        // Start of user code animationCallback_x3y2 (don't remove the 'Start/End of user code' markers)

        return animation(3, 2);

        // End of user code
    }


    static uint16_t animationCallback_x3y3() {
        // Start of user code animationCallback_x3y3 (don't remove the 'Start/End of user code' markers)

        return animation(3, 3);

        // End of user code
    }


    static uint16_t animationCallback_x3y4() {
        // Start of user code animationCallback_x3y4 (don't remove the 'Start/End of user code' markers)

        return animation(3, 4);

        // End of user code
    }


    static uint16_t animationCallback_x4y0() {
        // Start of user code animationCallback_x4y0 (don't remove the 'Start/End of user code' markers)

        return animation(4, 0);

        // End of user code
    }


    static uint16_t animationCallback_x4y1() {
        // Start of user code animationCallback_x4y1 (don't remove the 'Start/End of user code' markers)

        return animation(4, 1);

        // End of user code
    }


    static uint16_t animationCallback_x4y2() {
        // Start of user code animationCallback_x4y2 (don't remove the 'Start/End of user code' markers)

        return animation(4, 2);

        // End of user code
    }


    static uint16_t animationCallback_x4y3() {
        // Start of user code animationCallback_x4y3 (don't remove the 'Start/End of user code' markers)

        return animation(4, 3);

        // End of user code
    }


    static uint16_t animationCallback_x4y4() {
        // Start of user code animationCallback_x4y4 (don't remove the 'Start/End of user code' markers)

        return animation(4, 4);

        // End of user code
    }


    void setup(LedStrip_Factory_Interface ledStrip_factory) {
        // Start of user code setup (don't remove the 'Start/End of user code' markers)

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

        // End of user code
    }


    void animate() {
        // Start of user code animate (don't remove the 'Start/End of user code' markers)

        for(LedStrip_Interface* ledStrip : ledStrips) {
            ledStrip->animate();
        }

        // End of user code
    }


}
