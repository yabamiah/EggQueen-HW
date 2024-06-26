#ifndef MOTOR_HPP
#define MOTOR_HPP

class motor
{
private:
    int velocidade;
    int pin1;
    int pin2;
    int pin_en;

public:
    motor(int in1, int in2, int in_en);
    void set_velocidade(int velocidade);
    void para_frente();
    void parar();
};


#endif // MOTOR_HPP
