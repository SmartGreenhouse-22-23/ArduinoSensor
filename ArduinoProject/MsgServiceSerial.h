#ifndef __MSGSERVICESERIAL__
#define __MSGSERVICESERIAL__

#include "Arduino.h"
#include "MsgService.h"

/**
 * Declaration of the interface Pattern.
*/
class Pattern
{
public:
    /**
     * Verify that a given message metches a specific pattern.
     * @param true of the message satisfies the pattern, false otherwise.
    */
    virtual boolean match(const Msg &m) = 0;
};

/**
 * Declaration of the MsgServiceSerial class, that implements MsgService.
*/
class MsgServiceSerial : public MsgService
{

public:
    /**
     * Current message ridden.
    */
    Msg *currentMsg;
    /**
     * Determines if there are message available or not.
    */
    bool msgAvailable;
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
     * Checks if there is a message available that satisfies the given Pattern.
     * @param pattern the Pattern to satisfy.
     * @return true if there is a message available and satisfies the given pattern, false if there are no messages available
     * or the message doesn't satisfies the pattern.
    */
    bool isMsgAvailable(Pattern &pattern);
    /**
     * Method that reads the messageavailable that satisfies the given Pattern.
     * @param pattern the Pattern to satisfy.
     * @return the message ridden.
    */
    Msg *receiveMsg(Pattern &pattern);
     /**
     * Sends messages via serial comunication to the ESP.
     * @param msg the message to send.
    */
    void sendMsg(const String &msg);
};

extern MsgServiceSerial MsgServiceSL;

#endif
