#include "Esp8266.h"

static void callback(char* topic, byte* payload, unsigned int length){
  String message = String((char*)payload);
  //Esp8266::msgARD->send(String(topic) + ":" + message);
}

Esp8266::Esp8266(char *ssidName, char *pwd, char *mqttServer, MsgServiceArduino *msgARD):client(espClient)
{
    this->ssidName = ssidName;
    this->pwd = pwd;
    this->msgARD = msgARD;

    client.setServer(mqttServer, 1883);
    client.setCallback(callback);
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
    //Serial.println("Connected: \n local IP: " + String(WiFi.localIP()));
}

void Esp8266::reconnect(){
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        String clientId = "ESP8266Client-";
        clientId += String(random(0xffff), HEX);
        if (client.connect(clientId.c_str())) {
            Serial.println("connected");
            // Once connected, publish an announcement...
            client.publish("outTopic", "hello world");
            // ... and resubscribe
            client.subscribe("inTopic");
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
