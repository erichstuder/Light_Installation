set grid

set xlabel "x"
set ylabel "y"
set zlabel "z"

set xrange[0:500]
set yrange[0:500]
set zrange[0:500]


rgb(r,g,b) = 65536*255*rand(0) + 25600*255*rand(0) + 255*rand(0)

print time(0.0)

while(1){
	splot "leds.dat" using 1:2:3:(rgb($1,$2,$3)) with points lt 7 lc rgbcolor variable
}

print time(0.0)
