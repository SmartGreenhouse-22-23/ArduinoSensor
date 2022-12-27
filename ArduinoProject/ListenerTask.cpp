#include "ListenerTask.h"
/**
 * Implementation of the ListenerTask class.
*/
ListenerTask::ListenerTask(WaterPomp *waterPomp, Ventilation *ventilation, Light *temLamp, Light *lamp, MsgServiceEsp *msgEsp)
{
    this->waterPomp = waterPomp;
    this->ventilation = ventilation;
    this->temLamp = temLamp;
    this->lamp = lamp;
    this->msgEsp = msgEsp;
    this->active = false;
}

void ListenerTask::init(int period)
{
    Task::init(period);
}

void ListenerTask::setActive(bool active)
{
    this->active = active;
}

bool ListenerTask::isActive()
{
    return this->active;
}

void ListenerTask::manageIrrigationTopic(String content)
{
    if (content.equals("on") && (!this->waterPomp->isActivated()))
    {
        this->waterPomp->activate();
    }
    else if (content.equals("off") && this->waterPomp->isActivated())
    {
        this->waterPomp->deactivate();
    }
}

void ListenerTask::manageLuminosityTopic(String content)
{
    this->lamp->setBrightness(content.toInt());
}

void ListenerTask::manageTemperatureTopic(String content)
{
    if (content.equals("increase"))
    {
        if (this->ventilation->isActive())
        {
            this->ventilation->deactivate();
        }
        this->temLamp->switchOn();
    }
    else if (content.equals("decrease"))
    {
        if (this->temLamp->isSwitchedOn())
        {
            this->temLamp->switchOff();
        }
        this->ventilation->activate();
    }
}

void ListenerTask::manageVentilationTopic(String content)
{
    if (content.equals("on") && !this->ventilation->isActive())
    {
        this->ventilation->activate();
    }
    else if (content.equals("off") && this->ventilation->isActive())
    {
        this->ventilation->deactivate();
    }
}

void ListenerTask::handleMessage(String topic, String content)
{
    content.trim();
    if (topic.equals(IRRIGATION))
    {
        this->manageIrrigationTopic(content);
    }
    else if (topic.equals(LUMINOSITY))
    {
        this->manageLuminosityTopic(content);
    }
    else if (topic.equals(TEMPERATURE))
    {
        this->manageTemperatureTopic(content);
    }
    else if (topic.equals(VENTILATION))
    {
        this->manageVentilationTopic(content);
    }
}

void ListenerTask::tick()
{
    if (msgEsp->isMsgAvailable())
    {
        Msg *message = msgEsp->receiveMsg();
        String m = message->getContent();
        int len = m.length();
        char msg[len];
        m.toCharArray(msg, len);

        String data = strtok(msg, ":");

        this->handleMessage(m.substring(0, data.length()), m.substring(data.length() + 1));

        delete message;
    }
}