#include "sensor_tcrt.hpp"
#include <iostream>

enum Orientacao {parar = 0, frente = 1, direita = 2, esquerda = 3}

void Sensor::Sensor(): pino_centro(32), pino_direta(34), pino_esquerda(35), direcao(0)
{
    pinMode(pino_centro, INPUT);
    pinMode(pino_direita, INPUT);
    pinMode(pino_esquerda, INPUT);
}

void Sensor::set_direcao()
{
    if (digitalRead(pino_centro) == LOW && digitalRead(pino_direta) == HIGH && digitalRead(pino_esquerda) == HIGH){
        this->direcao = Orientacao::frente;
    }else if (digitalRead(pino_centro) == LOW && digitalRead(pino_direta) == LOW && digitalRead(pino_esquerda) == HIGH){
        this->direcao = Orientacao::esquerda;
    }else if(digitalRead(pino_centro) == LOW && digitalRead(pino_direta) == HIGH && digitalRead(pino_esquerda) == LOW){
        this->direcao = Orientacao::direta;
    }else {
        this->direcao = Orientacao::parar;
    }
}

int Sensor::get_direcao() const
{
    return direcao;
}