#include "Temperature.h"

Temperature::Temperature(Environment *env)
{
   this->env = env;
}

float Temperature::getTemperature()
{
    return this->env->getTemperature();
}
