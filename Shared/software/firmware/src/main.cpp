#include <Arduino.h>
#include "LedStrips.h"
#include "LedStrip_Factory.h"


void setup(){
	LedStrip_Factory ledStrip_factory;
	LedStrips::setup(&ledStrip_factory);
}

void loop(){
	LedStrips::animate();
}
