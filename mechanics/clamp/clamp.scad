$fn = 180;

plate_height = 3;
ver = "vX.X.X";



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
		xAbs = 9;
		for(x = [-xAbs, xAbs]){
			translate([x, 0, 38.5])
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
		xAbs = 9;
		for(x = [-xAbs, xAbs]){
			translate([x, 0, 38.5])
				rotate([-90, 0, 0])
					#cylinder(d=2.6, h=15);
		}
	}
}


module cut(){
	translate([0, -7.5, 38.5])
		cube([50, 15, 10], center=true);
}


module base(){
	difference(){
		union(){
			cube([100, 100, plate_height], center=true);
			cylinder(d=29.9, h=42+plate_height/2);
		}
		translate([0, 0, 15])
			cube([12, 4, 60], center=true);

		for(angle = [0:90:270]){
			rotate([0, 0, angle])
				translate([50, 0])
					cylinder(d=50, h=plate_height+1, center=true);
		}

		xyAbs = 40;
		for(x=[-xyAbs, xyAbs], y=[-xyAbs, xyAbs]){
			translate([x, y]){
				cylinder(d=2.6, h=plate_height+1, center=true);
				translate([0, 0, -plate_height/2+1])
					cylinder(d1=4.9, d2=2.6, h=2, center=true);
			}
		}

		version_ids();
	}
}


module version_ids(){
	translate([0, 20, -plate_height/2])
		rotate([180])
			linear_extrude(1, center=true)
				text(ver, size=10, halign="center");

	translate([0, -8, 42+plate_height/2])
		linear_extrude(1, center=true)
			text(ver, size=4, halign="center");
}
