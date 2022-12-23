#ifndef __SENDER__
#define __SENDER__

#include "Arduino.h"
#include "MsgServiceEsp.h"

class Sender
{
public:
    Sender(MsgServiceEsp *msgEsp);
    void notifyMsg(String msg);

private:
    MsgServiceEsp *msgEsp;
};

#endif