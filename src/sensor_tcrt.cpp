#include "include/sensor_tcrt.hpp"

void Sensor::Sensor()
    : sensor_centro(32), sensor_direta(34), sensor_esquerda(35), direcao(0)
{
    pinMode(sensor_centro, INPUT);
    pinMode(sensor_direita, INPUT);
    pinMode(sensor_esquerda, INPUT);
}

void Sensor::set_direcao()
{
    int sensor_centro_val = digitalRead(this->sensor_centro)
    int sensor_direito_val = digitalRead(this->sensor_direito)
    int sensor_esquerdo_val = digitalRead(this->sensor_esquerdo)

    if (sensor_centro_val == LOW && sensor_direito_val == HIGH && sensor_esquerdo_val == HIGH)
    {
        this->direcao = Orientacao::frente;
    }
    else if (sensor_centro_val == LOW && sensor_direito_val == LOW && sensor_esquerdo_val == HIGH)
    {
        this->direcao = Orientacao::esquerda;
    }
    else if(sensor_centro_val == LOW && sensor_direito_val == HIGH && sensor_esquerdo_val == LOW)
    {
        this->direcao = Orientacao::direta;
    }
    else 
    {
        this->direcao = Orientacao::parar;
    }
}

int Sensor::get_direcao() const
{
    return this->direcao;
}