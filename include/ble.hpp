#pragma once

#include <Arduino.h>
#include "BLECharacteristic.h"
#include "BLEServer.h"
#include "BLEService.h"

#define SERVICE_UUID "13d896e1-e37f-4fbd-bbc8-c88a93b17588"
#define ACS_CHARACTERISTIC_UUID "10bf25ce-0aca-4dbd-98ca-dce9beb4d9d8"
#define CAR_CHARACTERISTIC_UUID "ea2d09dd-0722-4fd2-b784-92090a5c0d67"
#define PID_CHARACTERISTIC_UUID "7ccc8569-b34b-47e4-a786-dc0798feb409"

#define DEVICE_NAME "ESP32"

namespace BLE{
	void bluetooth_setup();
	bool is_connected();

	void start_advertising();
	void notify_car(float vel, float dir, float isRunning);
	void notify_direction(float dir);
	void notify_acs();

	static bool connected = false;
	static BLEServer *server;
	static BLECharacteristic *ACS712_characteristic;
	static BLECharacteristic *CAR_characteristic;
	static BLECharacteristic *PID_characteristic;

	class ServerCallback: public BLEServerCallbacks {
		void onConnect(BLEServer *server);
		void onDisconnect(BLEServer *server);
	};

	class PID_CharacteristicCallbacks: public BLECharacteristicCallbacks {
		void onWrite(BLECharacteristic *characteristic);
	};

}
