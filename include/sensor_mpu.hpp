#pragma once
#include <MadgwickAHRS.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

#define SENSOR_RATE 1000.0

namespace MPU{

	void setup();
	void update_filter();
	float getDirection();
}

