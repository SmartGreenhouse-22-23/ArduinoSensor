#ifndef __MSGSERVICE__
#define __MSGSERVICE__

#include "Arduino.h"

/**
 * Declaration of class Msg.
*/
class Msg
{
    String content;

public:
    /**
     * The public constructor.
     * @param content the message content.
    */
    Msg(String content)
    {
        this->content = content;
    }

    /**
     * Getter method for the message content.
     * @return the content of the message.
    */
    String getContent()
    {
        return content;
    }
};

/**
 * Declaration of interface MsgService.
*/
class MsgService
{
public:
    /**
     * Method to initialize the service.
    */
    virtual void init();
    /**
     * Checks if a message is available.
     * @return true if there is a message to read, false otherwise.
    */
    virtual bool isMsgAvailable();
    /**
     * Method that reads the available messages.
     * @return the Msg ridden.
    */
    virtual Msg *receiveMsg();
};
#endif