#include <iostream>
#include <fstream>

#include "gnuplot-iostream.h"

#include "I_LedPattern.h"
#include "Wave.h"
#include "RunningLight.h"


static void createPatternFile(I_LedPattern* pattern, const char* fileName){
	std::ofstream file;
	file.open(fileName);

	const uint16_t Iterations = pattern->getIterations();

	for(uint16_t iteration=0; iteration<Iterations; iteration++){
		file << "\n\n";
		for(uint8_t x=0; x<5; x++){
			for(uint8_t y=0; y<5; y++){
				for(uint8_t z=0; z<15; z++){
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


static void animate(const char* fileName){
	Gnuplot gp("gnuplot"); //pass "gnuplot" to prevent default: "gnuplot -persist"
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
		<< "bind 'Escape' 'done = 1'\n"

		<< "stats '" << fileName << "' nooutput\n"
		<< "n = 0\n"
		<< "while(!done){\n"
		<< "	splot 'pattern.dat' index n using ($1*100):($2*100):($3*33.25):($4) with points lt 7 lc rgbcolor variable\n"
		<< "	n = (n + 1) % STATS_blocks\n"
		<< "	pause(0.01)\n"
		<< "}\n";
}


int main(){
	//RunningLight pattern;
	Wave pattern;

	createPatternFile(&pattern, "pattern.dat");
	animate("pattern.dat");
}
