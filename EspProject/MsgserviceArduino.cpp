#include "Arduino.h"
#include "MsgServiceArduino.h"

/**
 * Implementation of the MsgServiceArduion class.
*/
MsgServiceArduino::MsgServiceArduino(int rxPin, int txPin){
  channel = new SoftwareSerial(rxPin, txPin);
}

void MsgServiceArduino::init(){
  content.reserve(256);
  channel->begin(9600);
  availableMsg = NULL;
}

void MsgServiceArduino::sendMsg(Msg msg){
  channel->println(msg.getContent());  
}

bool MsgServiceArduino::isMsgAvailable(){
  while (channel->available()) {
    char ch = (char) channel->read();
    if (ch == '\n'){
      availableMsg = new Msg(content); 
      content = "";
      return true;    
    } else {
      content += ch;      
    }
  }
  return false;  
}

Msg* MsgServiceArduino::receiveMsg(){
  if (availableMsg != NULL){
    Msg* msg = availableMsg;
    availableMsg = NULL;
    return msg;  
  } else {
    return NULL;
  }
}