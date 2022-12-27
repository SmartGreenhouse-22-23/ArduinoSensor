#ifndef __LISTENER_TASK__
#define __LISTENER_TASK__

#define IRRIGATION "IRRIGATION"
#define LUMINOSITY "LUMINOSITY"
#define TEMPERATURE "TEMPERATURE"
#define VENTILATION "VENTILATION"

#include "Task.h"
#include "WaterPomp.h"
#include "Ventilation.h"
#include "Light.h"
#include "MsgServiceEsp.h"

class ListenerTask: public Task 
{
    bool active;
    WaterPomp *waterPomp;
    Ventilation *ventilation;
    Light *temLamp;
    Light *lamp;
    MsgServiceEsp *msgEsp;

    public:
        /**
         * The public constructor.
         * @param waterPomp the waterpomp used for irrigation.
         * @param ventilation the fan used for ventilation.
         * @param temLamp the led representing the heat lamp.
         * @param lamp the led representing the luminosity lamp.
         * @param msgEsp the message service that communicate through the ESP.
         */
        ListenerTask(WaterPomp *waterPomp, Ventilation *ventilation, Light *temLamp, Light *lamp, MsgServiceEsp *msgEsp);
        /**
         * Initialize the task.
         * @param period the period of the task to be evaluated by the Scheduler.
         */
        void init(int period);
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
        /**
         * Method that changes the state of the task, called by the Scheduler.
         */
        void tick();

    private:
        void handleMessage(String topic, String content);
        void manageIrrigationTopic(String content);
        void manageLuminosityTopic(String content);
        void manageTemperatureTopic(String content);
        void manageVentilationTopic(String content);
    
};

#endif