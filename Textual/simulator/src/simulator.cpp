#include <iostream>
#include <fstream>

#include "simulator.h"
#include "gnuplot-iostream.h"
#include "LedPattern_Interface.h"
#include "Wave.h"
#include "RunningLight.h"

#include "Animator.h"

static void createPatternFile(LedPattern_Interface* pattern, const char* fileName) {
    std::ofstream file;
    file.open(fileName);

    const uint16_t Iterations = pattern->getIterations();

    for(uint16_t iteration=0; iteration<Iterations; iteration++) {
        file << "\n\n";
        for(uint8_t x=0; x<5; x++) {
            for(uint8_t y=0; y<5; y++) {
                for(uint8_t z=0; z<15; z++) {
                    Color_t color = pattern->getColor({x,y,z}, iteration);
                    file << std::to_string(x) << " " << std::to_string(y) << " " << std::to_string(z) << " "
                    << "0x00" << std::hex
                    << std::setw(2) << std::setfill('0') << (int)color.r
                    << std::setw(2) << std::setfill('0') << (int)color.g
                    << std::setw(2) << std::setfill('0') << (int)color.b
                    << "\n";
                }
            }
        }
    }
    file.close();
}


void simulator(Animator_Interface* animator) {
    //RunningLight pattern;
    Wave pattern;

    createPatternFile(&pattern, "build/pattern.dat");

    animator->animate("build/pattern.dat");
}


#ifndef CUCUMBER
int main() {
    Animator animator;

    simulator(&animator);
}
#endif
