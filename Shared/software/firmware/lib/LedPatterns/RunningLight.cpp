#include "RunningLight.h"

uint16_t RunningLight::getIterations(){
	return 42;
}

Color_t RunningLight::getColor(Pixel_t pixel, uint16_t iteration){
	if(pixel.z == iteration % MaxPixel.z){
		return {255, 0, 0};
	}
	return {0, 0, 0};
}
