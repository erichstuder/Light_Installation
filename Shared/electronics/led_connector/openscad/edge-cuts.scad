$fn = 90;

difference(){
	shape();
	holes();
}


module shape(){
	length = 450;
	width = 40;
	circleDistance = length-width;
	square([circleDistance, width], center=true);
	xAbs = circleDistance/2;
	for(x = [-xAbs, xAbs]){
		translate([x, 0]) circle(d=width);
	}
}

module holes(){
	hole_distance = 100;
	for(n = [-2:2]){
		translate([n*hole_distance, 0]) square([10, 20], center=true);
	}
}
