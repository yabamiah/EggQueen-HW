#include "dir.hpp"
#include <Arduino.h>

void Motor::loop() {
  int sensor_right = digitalRead(digital_pin_right);
  int sensor_mid  = digitalRead(digital_pin_mid);
  int sensor_left  = digitalRead(digital_pin_left);

  if (sensor_left == HIGH && sensor_mid == HIGH && sensor_right == LOW)
  {
      left();
      Serial.println("Esquerda");
  }   
  else if (sensor_left == HIGH && sensor_mid == LOW && sensor_right == LOW)
  {
      left();
      Serial.println("Esquerda");
  }   
  else if(sensor_left == LOW && sensor_mid == HIGH && sensor_right == HIGH)
  {
      right();
      Serial.println("Direita");
  }   
  else if(sensor_left == LOW && sensor_mid == HIGH && sensor_right == LOW)
  {
      foward();
      Serial.println("Frente");
  }    
  else if(sensor_left == LOW && sensor_mid == LOW && sensor_right == HIGH)
  {
      right();
      Serial.println("Direita");
  }
  else 
  {
      stop();
      Serial.println("Parar");
  }
}

void Motor::foward()
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ena, minSpeed);

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enb, minSpeed);

}
void Motor::left(){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ena, midSpeed);

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enb, minSpeed);
}

void Motor::right(){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ena, minSpeed);

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enb, midSpeed); 
}

void Motor::stop(){
		isRunning = false;	
    analogWrite(ena, 0);
    analogWrite(enb, 0);
}

