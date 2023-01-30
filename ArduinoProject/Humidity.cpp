#include "Humidity.h"

Humidity::Humidity(Environment *env)
{
   this->env = env;
}

float Humidity::getHumidity()
{
   return this->env->getHumidity();
}
