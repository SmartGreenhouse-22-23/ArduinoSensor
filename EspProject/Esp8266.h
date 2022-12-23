#ifndef __ESP__
#define __ESP__

#include "Arduino.h"
#include "Connection.h"
#include "MsgServiceArduino.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

class Esp8266: public Connection { 

    public:
        Esp8266(char *ssidName, char *pwd, char *mqttServer, MsgServiceArduino *msgARD);
        void connecting();
        void sendData(char* topic, String msg);
        void processIncomingMessages();
        bool isConnected(); 
    private:
        char* ssidName;
        char* pwd; 
        WiFiClient espClient;
        PubSubClient client;
        MsgServiceArduino *msgARD;
        void reconnect();
};

#endif
