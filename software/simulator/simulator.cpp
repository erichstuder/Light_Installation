#include "gnuplot-iostream.h"

int main() {
	Gnuplot gp;
	gp	<< "set grid\n"

		<< "set xlabel 'x'\n"
		<< "set ylabel 'y'\n"
		<< "set zlabel 'z'\n"

		<< "set xrange[0:500]\n"
		<< "set yrange[0:500]\n"
		<< "set zrange[0:500]\n"

		<< "rgb(x,y,z,n) = (z/33.25 == n) ? 65536*255 + 25600*255*0 + 255*0 : 0\n"

		<< "n = 0\n"
		<< "while(1){\n"
		<< "	splot 'leds.dat' using 1:2:3:(rgb($1,$2,$3,n)) with points lt 7 lc rgbcolor variable\n"
		<< "	n = (n + 1) % 15\n"
		<< "	pause(0.01)\n"
		<< "}\n";
}
