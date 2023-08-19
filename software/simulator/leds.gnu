nr_of_leds_x = 5
nr_of_leds_y = 5
nr_of_leds_z = 15
nr_of_leds = nr_of_leds_x * nr_of_leds_y * nr_of_leds_z
set xrange[0:nrOfLeds-1]
set samples nrOfLeds

led_spacing_mm_x = 100
led_spacing_mm_y = 100
led_spaning_mm_z = 33.25
#Note: x is not directly connected to the x coordinate of an led.
point_x(x) = int(x) % nr_of_leds_x * led_spacing_mm_x
point_y(x) = floor( x / nr_of_leds_x ) % nr_of_leds_y * led_spacing_mm_y
point_z(x) = floor( x / (nr_of_leds_x*nr_of_leds_y)) % nr_of_leds_z * led_spaning_mm_z

set table "leds.dat"
plot "+" using (point_x($1)):(point_y($1)):(point_z($1)) with table

unset table
