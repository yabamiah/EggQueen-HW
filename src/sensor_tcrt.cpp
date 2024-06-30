#include "include/sensor_tcrt.hpp"

void Sensor::Sensor()
    : sensor_centro(32), sensor_direta(34), sensor_esquerda(35), direcao(0)
{
    pinMode(sensor_centro, INPUT);
    pinMode(sensor_direita, INPUT);
    pinMode(sensor_esquerda, INPUT);

    this->sensor_centro_val = digitalRead(this->sensor_centro)
    this->sensor_direito_val = digitalRead(this->sensor_direito)
    this->sensor_esquerdo_val = digitalRead(this->sensor_esquerdo)
}

void Sensor::set_direcao()
{
    if ( this->sensor_centro_val == HIGH &&
         this->sensor_direito_val == LOW &&
         this->sensor_esquerdo_val == LOW)
    {
        this->direcao = Orientacao::frente;
    }
    else if (this->sensor_centro_val == HIGH &&
             this->sensor_direito_val == LOW &&
            this->sensor_esquerdo_val == HIGH)
    {
        this->direcao = Orientacao::esquerda;
    }
    else if( this->sensor_centro_val == HIGH &&
             this->sensor_direito_val == HIGH &&
             this->sensor_esquerdo_val == LOW)
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