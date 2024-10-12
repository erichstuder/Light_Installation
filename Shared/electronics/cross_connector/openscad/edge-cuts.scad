$fn = 90;

width = 40; 

shape();
translate([50, -width/2, 0]) rotate([0, 0, 90])
	arduino_shape();
		

module shape(){
	length = 450;
	circleDistance = length-width;
	square([circleDistance, width], center=true);
	xAbs = circleDistance/2;
	for(x = [-xAbs, xAbs]){
		translate([x, 0]) circle(d=width);
	}
}


module arduino_shape(){
	//based on the coordinates from the footprint (courtyard)
	maxWidth = 0.254+53.594;
	xOffset = 0.254;
	translate([xOffset, -maxWidth/2, 0]) mirror([0,1,0])
		polygon([	[  -0.254,   0.254 ],
					[  99.314,   0.254 ],
					[ 101.854,  -3.683 ],
					[ 101.854, -38.227 ],
					[  99.314, -40.767 ],
					[  99.314, -51.943 ],
					[  97.663, -53.594 ],
					[  -0.254, -53.594 ]]);
}
