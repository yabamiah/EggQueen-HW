#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "Arduino"
#include "sensor_tcrt.hpp"

namespace motor
{
    const int in1 = 32;
    const int in2 = 35;
    const int ena = 33;
    const int in3 = 26;
    const int in4 = 25;
    const int enb = 27;

    void vrum_vrum();

} // namespace motor


#endif // MOTOR_HPP
