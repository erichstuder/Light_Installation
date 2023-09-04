#include <iostream>
#include <fstream>

#include "gnuplot-iostream.h"

typedef struct{
	uint8_t x, y, z;
} Pixel_t;

typedef struct{
	uint8_t r, g, b;
} Color_t;

static const uint8_t Nr_Of_Leds_Z = 15;

static Color_t running_light(Pixel_t pixel, uint8_t iteraction_count){
	//TODO: assert that pixel.z is of same type as interation_count?
	if(pixel.z == iteraction_count % Nr_Of_Leds_Z){
		return {255, 0, 0};
	}
	return {0, 0, 0};
}

static void create_pattern(){
	std::ofstream pattern_file;
	pattern_file.open("pattern.dat");

	for(uint8_t iteration_count=0; iteration_count<15; iteration_count++){
		pattern_file << "\n\n";
		for(uint8_t x=0; x<5; x++){
			for(uint8_t y=0; y<5; y++){
				for(uint8_t z=0; z<15; z++){
					Color_t color = running_light({x,y,z}, iteration_count);
					pattern_file << std::to_string(x) << " " << std::to_string(y) << " " << std::to_string(z) << " "
					<< "0x00"
					<< std::setfill('0') << std::setw(2) << std::hex << (int)color.r
					<< std::setfill('0') << std::setw(2) << std::hex << (int)color.g
					<< std::setfill('0') << std::setw(2) << std::hex << (int)color.b
					<< "\n";
				}
			}
		}
	}
	//TODO: muss auch bei einer Exception geschlossen werden.
	pattern_file.close();
}

int main(){
	create_pattern();

	Gnuplot gp("gnuplot");
	gp	<< "set grid\n"

		<< "set xlabel 'x'\n"
		<< "set ylabel 'y'\n"
		<< "set zlabel 'z'\n"

		<< "set xrange[0:500]\n"
		<< "set yrange[0:500]\n"
		<< "set zrange[0:500]\n"

		<< "done = 0\n"
		<< "bind 'ctrl-c' 'done = 1'\n"
		<< "bind 'q' 'done = 1'\n"
		<< "bind 'Close' 'done = 1'\n"

		<< "stats 'pattern.dat' nooutput\n"
		<< "n = 0\n"
		<< "while(!done){\n"
		<< "	splot 'pattern.dat' index n using ($1*100):($2*100):($3*33.25):($4) with points lt 7 lc rgbcolor variable\n"
		<< "	n = (n + 1) % STATS_blocks\n"
		<< "	pause(0.01)\n"
		<< "}\n";
}
