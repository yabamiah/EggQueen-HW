#include<Arduino.h>
#include <Wire.h>
//#include "mpu.hpp"
#include "ble.hpp"
#include "dir.hpp"

long int t0 = 0, t1;
float vel = 0.0;
float a = 0, b = 0;

Motor motor;

void notify(void *params)
{
	for(;;) {
		if (BLE::is_connected()) {
			if (motor.isRunning)
			{
//				auto direction = MPU::getDirection();
				BLE::notify_car(1, 1, 3);
			}
			else BLE::notify_car(a, b, -1);
			a++; b++;
		}
		vTaskDelay(1000 / portTICK_PERIOD_MS);
	}
}


void setup() {
	Serial.begin(115200);
	Wire.begin();
	//MPU::setup();
	BLE::bluetooth_setup();
	xTaskCreatePinnedToCore(notify, "notify", 2048, NULL, 1, NULL, 1);
}

void loop() {
	//MPU::update_filter();
	//auto direction = MPU::getDirection();
	motor.loop();
}

