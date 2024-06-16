#include "include/mpu.hpp"

SensorMpu::SensorMpu()
{
    this->mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    this->mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    this->mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
}

void SensorMpu::set_dados()
{
    this->mpu.getEvent(&a, &g); 
}

std::vector<float> SensorMpu::get_acelaracoes() const
{
    std::vector<float> dados (3);
    dados.push_back(this->aceleracao.acceleration.x);
    dados.push_back(this->aceleracao.acceleration.y);
    dados.push_back(this->aceleracao.acceleration.z);

    return dados;
}

std::vector<float> SensorMpu::get_rotacoes() const
{
    std::vector<float> dados (3);
    dados.push_back(this->rotacao.g.gyro.x);
    dados.push_back(this->rotacao.g.gyro.y);
    dados.push_back(this->rotacao.g.gyro.z);

    return dados;
}