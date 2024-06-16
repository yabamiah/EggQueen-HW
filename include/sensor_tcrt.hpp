#ifndef SENSOR_TCRT_HPP
#define SENSOR_TCRT_HPP

#include <Arduino.h>

enum Orientacao { parar = 0, frente, direita, esquerda }

class SensorTcrt 
{
    private:
        int sensor_centro;
        int sensor_direta;
        int sensor_esquerda;
        int direcao {0};

    public:
        Sensor();

        int get_direcao() const;
        void set_direcao(int direcao);
};

#endif 