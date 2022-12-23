#ifndef __MSGSERVICE__
#define __MSGSERVICE__

#include "Arduino.h"

/**
 * Deifnition of class Msg.
*/
class Msg
{
  String content;

public:
  /**
   * The public constructor.
   * @param content, the content of the message.
  */
  Msg(String content)
  {
    this->content = content;
  }

/**
 * Getter for obtaining the content of the message.
 * @return the message content.
*/
  String getContent()
  {
    return content;
  }
};

/**
 * Interface MsgService.
*/
class MsgService
{
  public:
    /**
     * Initialize the service.
    */
    virtual void init();
    /**
     * Checks if a new message is available.
     * @return true if there is an available message, flse otherwise.
    */
    virtual bool isMsgAvailable();
    /**
     * Reads the available message.
     * @return the message ridden.
    */
    virtual Msg *receiveMsg();
};
#endif