#include "Wave.h"

#ifdef PLATFORMIO
	#include <Arduino.h>
#endif

#include <math.h>

static const float Period = 1.0f;
static const float DeltaTime = 0.01f;

uint16_t Wave::getIterations(){
	return (uint16_t)(Period / DeltaTime);
}

Color_t Wave::getColor(Pixel_t pixel, uint16_t iteration){
	const float MaxRadius = sqrt(pow(MaxPixel.x - CenterPixel.x, 2) + pow(MaxPixel.y - CenterPixel.y, 2));
	const float Amplitude = (float)(MaxPixel.z-1) / 2;
	const float Omega = 2.0f * M_PI / Period;

	float radius = sqrt(pow(pixel.x - CenterPixel.x, 2) + pow(pixel.y - CenterPixel.y, 2));
	float z = Amplitude * sin(Omega * DeltaTime * (float)iteration - M_PI*radius/MaxRadius) + CenterPixel.z;
	z = min(max(z, 0.0f), (float)MaxPixel.z);

	if(z == pixel.z){
		return {0, 255, 0};
	}
	else if(z < pixel.z && z > 0 && z > pixel.z-1){
		return {0, (uint8_t)(255.0f * (z - pixel.z + 1)), 0};
	}
	else if(z > pixel.z && z < pixel.z+1){
		return {0, (uint8_t)(255.0f * (pixel.z - z + 1)), 0};
	}
	else{
		return {0, 0, 0};
	}
}
