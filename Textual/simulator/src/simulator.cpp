#include <iostream>
#include <fstream>
#include <filesystem>

#include "simulator.h"
#include "gnuplot-iostream.h"
#include "LedPattern_Interface.h"
#include "Wave.h"
#include "RunningLight.h"

#include "Animator.h"

void createPatternFile(LedPattern_Interface* pattern, const char* fileName) {
    std::filesystem::path filePath = std::filesystem::absolute(fileName);
    std::filesystem::create_directories(filePath.parent_path());
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


void simulator(LedPattern_Interface* pattern, Animator_Interface* animator) {
    if(pattern == nullptr) {
        throw std::invalid_argument("pattern is null");
    }

    createPatternFile(pattern, "build/pattern.dat");

    animator->animate("build/pattern.dat");
}


#ifndef CUCUMBER
#ifndef UNIT_TEST
int main() {
    //RunningLight pattern;
    Wave pattern;

    Animator animator;

    simulator(&pattern, &animator);
}
#endif
#endif
