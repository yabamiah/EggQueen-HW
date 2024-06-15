#ifndef SENSOR_TCRT_HPP
#define SENSOR_TCRT_HPP

#include <iostream>
#include <Arduino.h>

enum Orientacao {parar = 0, frente = 1, direita = 2, esquerda = 3}

class Sensor{
    private:
        int pino_centro;
        int pino_direta;
        int pino_esquerda;
        int direcao;

    public:
        Sensor();
        Sensor(pino_centro, pino_direta, pino_esquerda, direcao);

        int get_direcao() const;
        void set_direcao(int direcao);
};

#endif 