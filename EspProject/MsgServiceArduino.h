#ifndef __MSGSERVICEARDUINO__
#define __MSGSERVICEARDUINO__

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "MsgService.h"


class MsgServiceArduino : public MsgService {
    
public: 
  MsgServiceArduino(int rxPin, int txPin);  
  void init();  
  bool isMsgAvailable();
  Msg* receiveMsg();
  bool sendMsg(Msg msg);

private:
  String content;
  Msg* availableMsg;
  SoftwareSerial* channel;
  
};

#endif
