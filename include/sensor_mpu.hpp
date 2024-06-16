#ifndef SENSOR_MPU_HPP
#define SENSOR_MPU_HPP

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <vector>

class SensorMpu
{
    private:
        Adafruit_MPU6050 mpu;
        sensors_event_t aceleracao;
        sensors_event_t rotacao;
    public:
        SensorMpu();
        void set_dados();
        std::vector<float> get_acelaracoes() const;
        std::vector<float> get_rotacoes() const;
};


#endif // SENSOR_MPU_HPP