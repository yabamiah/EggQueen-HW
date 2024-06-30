#include "motor.hpp"

pinMode(motor::ena, OUTPUT);
pinMode(motor::in1, OUTPUT);
pinMode(motor::in2, OUTPUT);
pinMode(motor::enb, OUTPUT);
pinMode(motor::in3, OUTPUT);
pinMode(motor::in4, OUTPUT);

void motor::vrum_vrum()
{
    SensorTcrt sensor_ir;
    sensor_ir.set_direcao();
    int dir = sensor_ir.get_direcao();

    switch (dir)
    {
    case Orientacao::frente :
        digitalWrite(motor::in1, HIGH);
        digitalWrite(motor::in2, LOW);
        analogWrite(motor::ena, 100);

        digitalWrite(motor::in3, HIGH);
        digitalWrite(motor::in4, LOW);
        analogWrite(motor::enb, 100);

        break;
    case Orientacao::direita :
        digitalWrite(motor::in1, HIGH);
        digitalWrite(motor::in2, LOW);
        analogWrite(motor::ena, 100);

        digitalWrite(motor::in3, HIGH);
        digitalWrite(motor::in4, LOW);
        analogWrite(motor::enb, 60);
        break;
    case Orientacao::esquerda :
        digitalWrite(motor::in1, HIGH);
        digitalWrite(motor::in2, LOW);
        analogWrite(motor::ena, 60);

        digitalWrite(motor::in3, HIGH);
        digitalWrite(motor::in4, LOW);
        analogWrite(motor::enb, 100);
        break;
    case Orientacao::parar :
        analogWrite(motor::ena, 0);;
        analogWrite(motor::enb, 0);
        break;
    }
}