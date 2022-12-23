#ifndef __MSGSERVICEARDUINO__
#define __MSGSERVICEARDUINO__

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "MsgService.h"

/**
 * Deifnition of class MsgServiceArduino that implements the MsgService interface.
*/
class MsgServiceArduino : public MsgService {
    
public: 
  /**
   * The public constructor.
   * @param rxPin, the rx pin connected to Arduino.
   * @param txpin, the tx pin ocnnected to Arduino.
  */
  MsgServiceArduino(int rxPin, int txPin);  
  /**
   * Initialize the service.
  */
  void init(); 
  /**
   * Checks if a new message is available.
   * @return true if there is an available message, flse otherwise.
  */
  bool isMsgAvailable();
  /**
   * Reads the available message.
   * @return the message ridden.
  */
  Msg* receiveMsg();
  /**
   * Sends the message to Arduino.
   * @param the message to send.
  */
  void sendMsg(Msg msg);
  
private:
  String content;
  Msg* availableMsg;
  SoftwareSerial* channel;
  
};

#endif
