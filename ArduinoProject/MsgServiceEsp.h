#ifndef __MSGSERVICEESP__
#define __MSGSERVICEESP__

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "MsgService.h"

/**
 * Declaration of class MsgServiceEsp that implements MsgService.
*/
class MsgServiceEsp : public MsgService
{

public:
    /**
     * The public constructor.
     * @param rxPin the rx pin to comunicate with ESP via serial comunication.
     * @param txPin the tx pin to comunicate with ESP via serial comunication.
    */
    MsgServiceEsp(int rxPin, int txPin);
    /**
     * Method to call for initializing the service.
    */
    void init();
    /**
     * Checks if a message is available.
     * @return true if there is a message to read, false otherwise.
    */
    bool isMsgAvailable();
     /**
     * Method that reads the available messages.
     * @return the Msg ridden.
    */
    Msg *receiveMsg();
    /**
     * Sends messages via serial comunication to the ESP.
     * @param msg the message to send.
    */
    void sendMsg(const String &msg);

private:
    String content;
    Msg *availableMsg;
    SoftwareSerial *channel;
};

#endif