#include "Animator.h"

#include "gnuplot-iostream.h"

void Animator::animate(const char* fileName) {
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
		<< "	splot 'build/pattern.dat' index n using ($1*100):($2*100):($3*33.25):($4) with points lt 7 lc rgbcolor variable\n"
		<< "	n = (n + 1) % STATS_blocks\n"
		<< "	pause(0.01)\n"
		<< "}\n";
}
