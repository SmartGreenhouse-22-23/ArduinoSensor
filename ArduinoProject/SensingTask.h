#ifndef __SENSING_TASK__
#define __SENSING_TASK__

#include "Task.h"
#include "Brightness.h"
#include "SoilMoistureSensor.h"
#include "Environment.h"
#include "Sender.h"

class SensingTask : public Task
{
    Brightness *photoresistor;
    SoilMoistureSensor *soilMoistureSensor;
    Environment *tempHum;
    Sender *sender;
    bool active;

public:
    SensingTask(Brightness *photoresistor, SoilMoistureSensor *soilMoistureSensor, Environment *tempHum, Sender *sender);
    void init(unsigned long period);
    void tick();
    void setActive(bool active);
    bool isActive();

private:
    float temperatureValue;
    float humidityValue;
    float brightnessValue;
    float soilMoistureValue;

};

#endif
