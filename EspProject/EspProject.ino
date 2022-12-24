#include "Connection.h"
#include "MsgServiceSerial.h"
#include "MsgServiceArduino.h"
#include "Esp8266.h"
//#include <ArduinoJson.h>
#include <stdio.h>
#include <string.h>

/* wifi network name */
#define SSIDNAME "HNR 70"
/* WPA2 PSK password */
#define PWD "jialijiali"
/* MQTT server */
#define MQTT_SERVER "broker.mqtt-dashboard.com"

#define INIT 0
#define RECEIVE 1
#define SEND 2

#define RX D6
#define TX D5

#define FREQ1 5000
#define FREQ2 20

MsgServiceArduino *msgARD;
Connection *conn;

int state;
int id;
int i = 0;
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;


void setup()
{
    Serial.begin(9600);

    msgARD = new MsgServiceArduino(RX, TX);
    msgARD->init();

    conn = new Esp8266(SSIDNAME, PWD, MQTT_SERVER, msgARD);
    conn->connecting();

    state = RECEIVE;

}

void loop()
{
    conn->processIncomingMessages();
    if (msgARD->isMsgAvailable()){
        Msg *message = msgARD->receiveMsg();
        String m = message->getContent();

        //invia dati con mqtt
        // conn->sendData("SGinTopic", m);
        delete message;
    }
    delay(500);
}
    
    
