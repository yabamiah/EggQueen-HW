#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);

  while (!Serial)
  {
    delay(10);
  }

  Serial.println("MPU 6050 teste");

  if (!mpu.begin())
  {
    Serial.println("Falha ao procurar o MPU6050");
    while (1)
    {
      delay(10);
    }
  }

  Serial.println("MPU6050 foi encontrado");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
 
  Serial.println("");
  delay(100);
}

void loop() {
  sensors_event_t a, g;
  mpu.getEvent(&a, &g);

  /* Print out the values */
  Serial.print("Aceleracao X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s");

  Serial.print("Rotacao X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");
  
  Serial.println("");
  delay(500);
}
