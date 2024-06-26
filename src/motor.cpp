#include "motor.hpp"

motor::motor(int in1, int in2, int in_en)
    : pin1(in1), pin2(in2), pin_en(in_en)
{
    pinMode(this->pin1, OUTPUT);
    pinMode(this->pin2, OUTPUT);
    pinMode(this->pin_en, OUTPUT);
}

void motor::set_velocidade(int vel)
{
    this->velocidade = vel;
}

void motor::para_frente()
{
    analogWrite(this->pin_en, this->velocidade);
    digitalWrite(this->pin1, HIGH);
    digitalWrite(this->pin2, LOW);
}

void motor::parar()
{
    analogWrite(this->pin_en, this->velocidade);
    digitalWrite(this->pin1, HIGH);
    digitalWrite(this->pin2, HIGH);
}