#include "SensingTask.h"

/**
 * Implementation of the class SensingTask.
*/
SensingTask::SensingTask(Brightness *photoresistor, SoilMoistureSensor *soilMoistureSensor, Environment *tempHum, Sender *sender)
{
    this->photoresistor = photoresistor;
    this->soilMoistureSensor = soilMoistureSensor;
    this->tempHum = tempHum;
    this->active = false;
    
    this->temperatureValue = 0.0;
    this->humidityValue = 0.0;
    this->brightnessValue = 0.0;
    this->soilMoistureValue = 0.0;

    this->sender = sender;
}


void SensingTask::init(unsigned long period)
{
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
    temperatureValue = this->tempHum->getTemperature();
    humidityValue = this->tempHum->getHumidity();
    brightnessValue = this->photoresistor->getBrightness();
    soilMoistureValue = this->soilMoistureSensor->getValue();

    String msg ="{'Temp': " + String(temperatureValue) + ",'Hum': " + String(humidityValue) + ",'Bright': " + String(brightnessValue) + ",'Soil': " + String(soilMoistureValue)+ "}";
    sender->notifyMsg(msg);
    msg = "";
}
