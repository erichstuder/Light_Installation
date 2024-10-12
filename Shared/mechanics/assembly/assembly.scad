opacity = 1;

for(y = [-200:100:200]){
	translate([0, y, 0.8])
		led_connector();
}

translate([-129, 0, 24.3-5]) rotate([0, 0, -90])
	cross_connector();

for(x = [-200:100:200], y = [-200:100:200]){
	translate([x, y, -1.5]) rotate([180, 0, 90])
		clamp();
}




module led_connector(){
	// It looks like blender exports stl files in meters (not millimeters).
	// At the moment the solution is to scale up the model by 1000.
	scale(1000) color("red", opacity)
		import("temp/3d_models/led_connector-3D_blender_top.stl");
}

module cross_connector(){
	// It looks like blender exports stl files in meters (not millimeters).
	// At the moment the solution is to scale up the model by 1000.
	scale(1000) color("green", opacity)
		import("temp/3d_models/cross_connector-3D_blender_top.stl");
}

module clamp(){
	color("blue", opacity)
		import("temp/3d_models/clamp.stl");
}
