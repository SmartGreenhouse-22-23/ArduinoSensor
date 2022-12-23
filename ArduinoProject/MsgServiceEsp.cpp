#include "Arduino.h"
#include "MsgServiceEsp.h"

MsgServiceEsp::MsgServiceEsp(int rxPin, int txPin)
{
    channel = new SoftwareSerial(rxPin, txPin);
}

void MsgServiceEsp::init()
{
    content.reserve(256);
    channel->begin(9600);
    availableMsg = NULL;
}

bool MsgServiceEsp::sendMsg(const String &msg)
{
    channel->println(msg);
}

bool MsgServiceEsp::isMsgAvailable()
{
    while (channel->available())
    {
        char ch = (char)channel->read();
        if (ch == '\n')
        {
            availableMsg = new Msg(content);
            content = "";
            return true;
        }
        else
        {
            content += ch;
        }
    }
    return false;
}

Msg *MsgServiceEsp::receiveMsg()
{
    if (availableMsg != NULL)
    {
        Msg *msg = availableMsg;
        availableMsg = NULL;
        return msg;
    }
    else
    {
        return NULL;
    }
}