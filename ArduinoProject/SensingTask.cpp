#include "SensingTask.h"

SensingTask::SensingTask(Brightness *photoresistor, SoilMoistureSensor *soilMoistureSensor, Environment *tempHum)
{
    this->photoresistor = photoresistor;
    this->soilMoistureSensor = soilMoistureSensor;
    this->tempHum = tempHum;
    this->active = false;
    
    this->temperatureValue = 0.0;
    this->humidityValue = 0.0;
    this->brightnessValue = 0.0;
    this->soilMoistureValue = 0.0;
}


void SensingTask::init(unsigned long period)
{
    Serial.println(period);
    Task::init(period);
}

void SensingTask::setActive(bool active)
{
    this->active = active;
}

bool SensingTask::isActive()
{
    return this->active;
}

void SensingTask::tick()
{
  Serial.println("SENSING TICK");
 /*
      temperatureValue = String(this->tempHum->getTemperature());
      humidityValue = String(this->tempHum->getHumidity());
      brightnessValue = String(this->photoresistor->getBrightness());
      soilMoistureValue = String(this->soilMoistureSensor->getValue());
      */

      temperatureValue = 20.0;
      humidityValue = 10.0;
      brightnessValue = 1000.0;
      soilMoistureValue = 30.0;
 
      Serial.println(temperatureValue);
      String msg ="Temperature: " + String(temperatureValue) + "\nHumidity: " + String(humidityValue) + "\nBrightness: " + String(brightnessValue) + "\nSoilMoisture: " + String(soilMoistureValue);
      //TODO usare sender e sistemare
      Serial.println(msg);
}
