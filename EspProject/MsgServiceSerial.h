#ifndef __MSGSERVICESERIAL__
#define __MSGSERVICESERIAL__

#include "Arduino.h"
#include "MsgService.h"


class Pattern {
public:
  virtual boolean match(const Msg& m) = 0;  
};

class MsgServiceSerial : public MsgService {
    
public: 
  
  Msg* currentMsg;
  bool msgAvailable;

  void init();  

  bool isMsgAvailable();
  Msg* receiveMsg();

  bool isMsgAvailable(Pattern& pattern);
  Msg* receiveMsg(Pattern& pattern);
  
  void sendMsg(const String& msg);
};

extern MsgServiceSerial MsgServiceSL;

#endif
