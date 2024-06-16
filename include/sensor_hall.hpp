#ifndef SENSOR_HALL_HPP
#define SENSOR_HALL_HPP

#include <Arduino.h>

class SensorHall
{
    private:
        int hall_sensor_pin;
        volatile unsigned long last_time {0};
        volatile unsigned long current_time {0};
        volatile bool sensor_ativado {false};
        const float roda_perim {0.204};
        float rpm;
        float velocidade;

    public:
        SensorHall(int _pin);

        void set_velocidade();
        float get_rpm() const;
        float get_velocidade() const;
        int get_leitura_analogica() const;
        int get_leitura_digital() const;
        void sensor_hall_interrupt();
};

#endif // SENSOR_HALL_HPP
