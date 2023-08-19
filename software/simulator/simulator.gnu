set grid

set xlabel "x"
set ylabel "y"
set zlabel "z"

rgb(r,g,b) = 65536 * int(100*r) + 25600 * int(0) + int(0)
splot "leds.dat" using 1:2:3:(rgb($1,$2,$3)) with points lt 7 lc rgbcolor variable
