set grid

set xlabel "x"
set ylabel "y"
set zlabel "z"

set xrange[0:500]
set yrange[0:500]
set zrange[0:500]

rgb(x,y,z,n) = (z/33.25 == n) ? 65536*255 + 25600*255*0 + 255*0 : 0

n = 0
while(1){
	splot "leds.dat" using 1:2:3:(rgb($1,$2,$3,n)) with points lt 7 lc rgbcolor variable
	n = (n + 1) % 15
	pause(0.01)
}

#print time(0.0)
