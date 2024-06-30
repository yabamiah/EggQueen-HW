#ifndef SENSOR_TCRT_HPP
#define SENSOR_TCRT_HPP

#include <Arduino.h>

enum Orientacao { parar = 0, frente, direita, esquerda }

class SensorTcrt 
{
    private:
        int sensor_centro, sensor_direta, sensor_esquerda;
        int sensor_centro_val, sensor_direta_val, sensor_esquerda_val;
        int direcao {0};

    public:
        Sensor();

        int get_direcao() const;
        void set_direcao();
};

#endif 