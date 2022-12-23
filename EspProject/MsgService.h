#ifndef __MSGSERVICE__
#define __MSGSERVICE__

#include "Arduino.h"

class Msg
{
  String content;

public:
  Msg(String content)
  {
    this->content = content;
  }

  String getContent()
  {
    return content;
  }
};

class MsgService
{
  public:
    virtual void init();
    virtual bool isMsgAvailable();
    virtual Msg *receiveMsg();
};
#endif