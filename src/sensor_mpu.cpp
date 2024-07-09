#include "mpu.hpp"

MPU6050 mpu(Wire);
Madgwick filter;

void MPU::setup()
{
	mpu.begin();
	mpu.calcGyroOffsets(true);
	filter.begin(549.78);
}

void MPU::update_filter()
{
	mpu.update();
	filter.updateIMU(
		mpu.getGyroX(),
		mpu.getGyroY(),
		mpu.getGyroZ(),
		mpu.getAccX(),
		mpu.getAccY(),
		mpu.getAccZ()
	);
}

float MPU::getDirection() {
	auto heading = filter.getYaw();
	return heading;
}
