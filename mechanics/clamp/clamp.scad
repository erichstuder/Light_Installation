$fn = 180;

back();

translate([50, 0, 0]){
	front();
}


module front(){
	difference(){
		intersection(){
			base();
			cut();
		}
		xAbs = 10;
		for(x = [-xAbs, xAbs]){
			translate([x, 0, -25])
				rotate([90, 0, 0]){
					#cylinder(d=3.9, h=15);
					translate([0, 0, 5])
						#cylinder(d=7.9, h=10);
				}
		}
	}
}

module back(){
	difference(){
		base();
		cut();
		xAbs = 10;
		for(x = [-xAbs, xAbs]){
			translate([x, 0, -25])
				rotate([-90, 0, 0])
					#cylinder(d=2.5, h=15);
		}
	}
}


module cut(){
	translate([0, -7.5, -25])
		cube([50, 15, 10], center=true);
}


module base(){
	difference(){
		union(){
			cube([50, 50, 5], center=true);
			translate([0, 0, -15])
				cylinder(d=30, h=30, center=true);
		}
		translate([0, 0, -15])
			cube([12, 4, 40], center=true);
	}
}
