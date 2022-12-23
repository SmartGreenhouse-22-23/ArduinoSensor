#ifndef __SENDER__
#define __SENDER__

#include "Arduino.h"
#include "MsgServiceEsp.h"

/**
 * Declaration of the class Sender.
*/
class Sender
{
public:
    /**
     * The public constructor.
     * @param msgEsp the esp message service.
    */
    Sender(MsgServiceEsp *msgEsp);
    /**
     * Sends a message via the service specified in the constructor.
     * @param msg the message to send.
    */
    void notifyMsg(String msg);

private:
    MsgServiceEsp *msgEsp;
};

#endif