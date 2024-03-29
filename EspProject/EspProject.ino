#include "Connection.h"
#include "MsgServiceSerial.h"
#include "MsgServiceArduino.h"
#include "Esp8266.h"
#include <stdio.h>
#include <string.h>

/**
 * This file represent the .ino entry point for the EspProject, it was designed to run on an ESP8266
 * By executing this file it will be possible to load the program on the ESP and check its work.
*/


/* wifi network name */
#define SSIDNAME "wifi_network_name"
/* WPA2 PSK password */
#define PWD "password"
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
        conn->sendData("dataSG", m);
        delete message;
    }
    delay(1000);
}
    
    
