#ifndef __CONNECTION__
#define __CONNECTION__
#include "Arduino.h"
class Connection {
public:
  virtual void connecting();
  virtual void reconnect();
  virtual void sendData(char* topic, String msg);
  virtual void processIncomingMessages();
  virtual bool isConnected();    
};

#endif
