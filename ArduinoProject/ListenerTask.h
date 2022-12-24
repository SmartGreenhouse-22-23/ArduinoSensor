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
    ListenerTask(WaterPomp *waterPomp, Ventilation *ventilation, Light *temLamp, Light *lamp, MsgServiceEsp *msgEsp);
    void init(int period);
    void setActive(bool active);
    bool isActive();
    void tick();

    private:
    void handleMessage(String topic, String content);
    void manageIrrigationTopic(String content);
    void manageLuminosityTopic(String content);
    void manageTemperatureTopic(String content);
    void manageVentilationTopic(String content);
    
};

#endif