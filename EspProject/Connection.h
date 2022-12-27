#ifndef __CONNECTION__
#define __CONNECTION__
#include "Arduino.h"

/**
 * A class representing a connection to the network.
*/
class Connection {
public:

  /**
   * Connects to the network.
  */
  virtual void connecting();

  /**
   * Reconnects to the network.
  */
  virtual void reconnect();

  /**
   * Send data over the connection.
   * @param topic The topic of the data.
   * @param msg The message to send.
  */
  virtual void sendData(char* topic, String msg);

  /**
   * Processes incoming messages over the connection.
  */
  virtual void processIncomingMessages();
  
  /**
   * Checks if the connection is currently established.
   * @return true if the connection is established, false otherwise.
  */
  virtual bool isConnected();    
};

#endif
