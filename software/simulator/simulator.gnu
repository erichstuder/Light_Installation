set grid

set xlabel "x"
set ylabel "y"
set zlabel "z"

set xrange[-1:5]
set yrange[-1:5]
set zrange[-1:15]


rgb(r,g,b) = 65536*255*rand(0) + 25600*255*rand(0) + 255*rand(0)

print time(0.0)

while(1){
	splot "leds.dat" using 1:2:3:(rgb($1*n,$2,$3)) with points lt 7 lc rgbcolor variable
}

print time(0.0)
