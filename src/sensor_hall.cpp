#include "hall.hpp"

void SensorHall::setup(int pin) {
    pinMode(this->hall_sensor_pin, INPUT);
		SensorHall::instance = this;
    attachInterrupt(
			digitalPinToInterrupt(this->hall_sensor_pin),
			[](){SensorHall::instance->sensor_hall_interrupt();},
			FALLING
	);

}

void SensorHall::set_velocidade()
{
    if (this->sensor_ativado)
    {
        unsigned long intervalo = this->current_time - this->last_time;
        this->last_time = this->current_time;

        this->rpm = (60.0 * 1000.0) / intervalo;
        this->velocidade = (this->rpm * this->roda_perim) / 60.0;

        this->sensor_ativado = false;
    }
}

float SensorHall::get_rpm() const
{
    return this->rpm;
}

float SensorHall::get_velocidade() const
{
    return this->velocidade;
}

int SensorHall::get_leitura_analogica() const
{
    return analogRead(this->hall_sensor_pin); 
}

int SensorHall::get_leitura_digital() const
{
    return digitalRead(this->hall_sensor_pin); 
}

void SensorHall::sensor_hall_interrupt()
{
    this->current_time = millis();
    this->sensor_ativado = true;
}
