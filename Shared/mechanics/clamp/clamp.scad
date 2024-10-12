$fn = 180;

/*
calculation of connector height:
- 12mm plate + 20mm cage + 10mm of led strip => 42mm
*/

plate_height = 3;
connector_height = 42;
ver = "vXX.XX.XX";


part();


module part(){
	difference(){
		union(){
			cube([100, 100, plate_height], center=true);
			cylinder(d=29.9, h=connector_height+plate_height/2);
		}
		#translate([0, 0, connector_height/2])
			cube([15.8, 7.1, connector_height+plate_height], center=true);
		ledStrip_depth = 10;
		#translate([0, 0, connector_height+plate_height/2-ledStrip_depth/2])
			cube([17.2, 8.5, ledStrip_depth], center=true);

		for(angle = [0:90:270]){
			rotate([0, 0, angle])
				translate([50, 0])
					cylinder(d=50, h=plate_height+1, center=true);
		}

		xyAbs = 40;
		xy = [-xyAbs, xyAbs];
		for(x=xy, y=xy){
			translate([x, y]){
				cylinder(d=2.6, h=plate_height+1, center=true);
				translate([0, 0, -plate_height/2+1])
					cylinder(d1=4.9, d2=2.6, h=2, center=true);
			}
		}

		version_id();
	}
}


module version_id(){
	translate([0, 20, -plate_height/2])
		rotate([180])
			linear_extrude(1, center=true)
				text(ver, size=7, halign="center");
}
