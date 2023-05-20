#include <Arduino.h>
#include "../rhapsody/firmware/Component/Config/Application.h"

Application* application;

void setup(){
	application = new Application();
}

void loop(){
	application->tick();
}
