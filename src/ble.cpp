#include <Arduino.h>
#include <cstring>

#include "ble.hpp"
#include "BLE2902.h"
#include "BLECharacteristic.h"
#include "BLEDevice.h"

bool BLE::is_connected() {
	return connected;
}
void BLE::PID_CharacteristicCallbacks::onWrite(BLECharacteristic *characteristic)
{
	std::string value = characteristic->getValue();
	if (value.length() <= 0 ) return;
	double *pid = (double*)value.c_str();

	Serial.println(value.length());
	Serial.printf("%lf %lf %lf\n", pid[0], pid[1], pid[2]);
	Serial.println();
};

void BLE::notify_car(float vel, float dir, float isRunning)
{
	float data[3] = {vel, dir, isRunning};
	CAR_characteristic->setValue((uint8_t*)data, 3*sizeof(float));
	CAR_characteristic->notify();
}

void BLE::ServerCallback::onConnect(BLEServer *server)
{
	Serial.println("Device connected");
	connected = true;
}
void BLE::ServerCallback::onDisconnect(BLEServer *server)
{
	Serial.println("Device disconnected");
	connected = false;
}

void BLE::bluetooth_setup()
{
	BLEDevice::init(DEVICE_NAME);

	server = BLEDevice::createServer();
	server->setCallbacks(new ServerCallback());

	connected = false;

	BLEService *service = server->createService(SERVICE_UUID);

	CAR_characteristic = service->createCharacteristic(
		CAR_CHARACTERISTIC_UUID,
		BLECharacteristic::PROPERTY_READ 		|
		BLECharacteristic::PROPERTY_NOTIFY 	
	);

	ACS712_characteristic = service->createCharacteristic(
		ACS_CHARACTERISTIC_UUID,
		BLECharacteristic::PROPERTY_READ 		|
		BLECharacteristic::PROPERTY_NOTIFY 	
	);

	PID_characteristic = service->createCharacteristic(
		PID_CHARACTERISTIC_UUID,
		BLECharacteristic::PROPERTY_READ 		|
		BLECharacteristic::PROPERTY_WRITE 	
	);

	PID_characteristic->setCallbacks(new BLE::PID_CharacteristicCallbacks());
	
	ACS712_characteristic->addDescriptor(new BLE2902());
	PID_characteristic->addDescriptor(new BLE2902());
	CAR_characteristic->addDescriptor(new BLE2902());

	service->start();

	BLEAdvertising *advertising = BLEDevice::getAdvertising();
	advertising->addServiceUUID(SERVICE_UUID);
	advertising->setScanResponse(false);
	advertising->setMinPreferred(0x0);
	BLEDevice::startAdvertising();
	Serial.printf("Waiting for connection\n");
}

void BLE::start_advertising()
{
	server->startAdvertising();
	printf("Waiting for connection");
}
