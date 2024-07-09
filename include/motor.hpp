#pragma once

class Motor {
public:
	void loop();	
	bool isRunning = true;
private:
	const int in1 = 26; 
	const int in2 = 25;
	const int in3 = 32;
	const int in4 = 35;

	const int ena = 27;
	const int enb = 33;

	const int maxSpeed = 180;
	const int minSpeed = 180;
	const int midSpeed = 20;

	const int digital_pin_right = 5;
	const int digital_pin_mid = 19;
	const int digital_pin_left = 18;

	void foward();
	void left();
	void right();
	void stop();
};
