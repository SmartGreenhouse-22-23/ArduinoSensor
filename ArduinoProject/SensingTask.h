#ifndef __SENSING_TASK__
#define __SENSING_TASK__

#include "Task.h"
#include "Brightness.h"
#include "SoilMoistureSensor.h"
#include "Environment.h"
#include "Sender.h"

/**
 * Definition of the class SensingTask that implement the Task interface.
*/
class SensingTask : public Task
{
    Brightness *photoresistor;
    SoilMoistureSensor *soilMoistureSensor;
    Environment *tempHum;
    Sender *sender;
    bool active;

public:
    /**
     * The public constructor.
     * @param photoresistor the photoresistor that registered the brigthness.
     * @param soilMoistureSensor the sensor that registered the soil moisture.
     * @param tempHum the DHT sensor that registered the humidity and the temperature.
     * @param sender the sender to send the data to the ESP.
    */
    SensingTask(Brightness *photoresistor, SoilMoistureSensor *soilMoistureSensor, Environment *tempHum, Sender *sender);
    /**
     * Initialize the task.
     * @param period the period of the task to be evaluated by the Scheduler.
    */
    void init(unsigned long period);
    /**
     * Method that changes the state of the task, called by the Scheduler.
    */
    void tick();
    /**
     * Setter that sets the task as active or not.
     * @param active, indicates if the task is active or not.
    */
    void setActive(bool active);
    /**
     * Checks if the task is active or not.
     * @return true if the task is active, false otherwise.
    */
    bool isActive();

private:
    float temperatureValue;
    float humidityValue;
    float brightnessValue;
    float soilMoistureValue;

};

#endif
