#include "Arduino.h"
#include "MsgServiceSerial.h"

String content;

MsgServiceSerial MsgServiceSL;

bool MsgServiceSerial::isMsgAvailable()
{
    return msgAvailable;
}

Msg *MsgServiceSerial::receiveMsg()
{
    if (msgAvailable)
    {
        Msg *msg = currentMsg;
        msgAvailable = false;
        currentMsg = NULL;
        content = "";
        return msg;
    }
    else
    {
        return NULL;
    }
}

void MsgServiceSerial::init()
{
    Serial.begin(9600);
    content.reserve(256);
    content = "";
    currentMsg = NULL;
    msgAvailable = false;
}

void MsgServiceSerial::sendMsg(const String &msg)
{
    Serial.println(msg);
}

bool MsgServiceSerial::isMsgAvailable(Pattern &pattern)
{
    return (msgAvailable && pattern.match(*currentMsg));
}

Msg *MsgServiceSerial::receiveMsg(Pattern &pattern)
{
    if (msgAvailable && pattern.match(*currentMsg))
    {
        Msg *msg = currentMsg;
        msgAvailable = false;
        currentMsg = NULL;
        content = "";
        return msg;
    }
    else
    {
        return NULL;
    }
}

void serialEvent()
{
    /* reading the content */
    while (Serial.available())
    {
        char ch = (char)Serial.read();
        if (ch == '\n')
        {
            MsgServiceSL.currentMsg = new Msg(content);
            MsgServiceSL.msgAvailable = true;
        }
        else
        {
            content += ch;
        }
    }
}