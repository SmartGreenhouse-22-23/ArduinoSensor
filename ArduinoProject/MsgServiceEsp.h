#ifndef __MSGSERVICEESP__
#define __MSGSERVICEESP__

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "MsgService.h"

class MsgServiceEsp : public MsgService
{

public:
    MsgServiceEsp(int rxPin, int txPin);
    void init();
    bool isMsgAvailable();
    Msg *receiveMsg();
    bool sendMsg(const String &msg);

private:
    String content;
    Msg *availableMsg;
    SoftwareSerial *channel;
};

#endif