#include "Esp8266.h"

/**
 * Implementation of the Esp8266 class. 
*/
Esp8266::Esp8266(char *ssidName, char *pwd, char *mqttServer, MsgServiceArduino *msgARD):client(espClient)
{
    this->ssidName = ssidName;
    this->pwd = pwd;
    this->msgARD = msgARD;

    client.setServer(mqttServer, 1883);
    client.setCallback(std::bind(&Esp8266::callback, this,  std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

void Esp8266::callback(char* topic, byte* payload, unsigned int length){
  String message = String((char*)payload);
  Serial.println("Receive message " + String(topic) + ":" + message.substring(0, length) + " len: " + String(length));
  this->msgARD->sendMsg(String(topic) + ":" + message.substring(0, length));
  message = "";
}

void Esp8266::connecting()
{
    WiFi.begin(ssidName, pwd);
    Serial.print("Connecting...");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    WiFi.setSleepMode(WIFI_NONE_SLEEP);
}

void Esp8266::reconnect(){
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        String clientId = "ESP8266Client-";
        clientId += String(random(0xffff), HEX);
        if (client.connect(clientId.c_str())) {
            Serial.println("connected");
            client.subscribe(VENTILATION);
            client.subscribe(IRRIGATION);
            client.subscribe(LUMINOSITY);
            client.subscribe(TEMPERATURE);
        } else {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
  }
}

void Esp8266::processIncomingMessages(){
  if(!client.connected()){
    this->reconnect();
  }
  client.loop();
}

void Esp8266::sendData(char* topic, String msg){
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Not connecting");
        connecting();
    }
    if (WiFi.status() == WL_CONNECTED)
    {
       client.publish(topic, msg.c_str());
    }
}

bool Esp8266::isConnected()
{
    return WiFi.status() == WL_CONNECTED;
}
