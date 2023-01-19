#include "SoilMoistureSensor.h"
#include "WaterPomp.h"
#include "Brightness.h"
#include "Photoresistor.h"
#include "Ventilation.h"
#include "Fan.h"
#include "TemperatureAndHumidity.h"
#include "Environment.h"
#include "Light.h"
#include "Led.h"
#include "Scheduler.h"
#include "SensingTask.h"
#include "ListenerTask.h"
#include "Sender.h"
#include "MsgServiceEsp.h"

/**
 * This file represent the .ino entry point for the arduinoProject, it was designed to run on an Arduino UNO
 * By executing this file it will be possible to load the program on the arduino and check its work.
*/

#define PIN_PHOTORES A1
#define PIN_SOILMOISTURE A0
#define PIN_WATERPOMP 2
#define PIN_DHT 3
#define PIN_ENABLE 5
#define PIN_DIRA 7
#define PIN_DIRB 4
#define PIN_TEM_LAMP 6
#define PIN_LAMP 11
#define PIN_RX A3
#define PIN_TX A4

#define SCHEDULE_TIME 20UL

Ventilation *ventilation;
Brightness *photoresistor;
SoilMoistureSensor *soilMoistureSensor;
WaterPomp *waterPomp;
Environment *tempHum;
Light *tempLamp;
Light *lamp;

int fade = 5;

SensingTask *sensingTask;
ListenerTask *listenerTask;

Scheduler scheduler;

Sender *sender;
MsgServiceEsp *msgServiceEsp;

/**
 * Setup of the arduino microprocessor.
 * Initializes and sets the initial values for sensors, task and scheduler.
 */
void setup() {
  Serial.begin(9600);
  ventilation = new Fan(PIN_ENABLE, PIN_DIRA, PIN_DIRB);
  photoresistor = new Photoresistor(PIN_PHOTORES);
  soilMoistureSensor = new SoilMoistureSensor(PIN_SOILMOISTURE);
  waterPomp = new WaterPomp(PIN_WATERPOMP);
  tempHum = new TemperatureAndHumidity(PIN_DHT);
  tempLamp = new Led(PIN_TEM_LAMP);
  lamp = new Led(PIN_LAMP);
  pinMode(PIN_LAMP, OUTPUT);
  pinMode(PIN_TEM_LAMP, OUTPUT);
  lamp->switchOn();
  lamp->setBrightness(0);
  waterPomp->deactivate();

  msgServiceEsp = new MsgServiceEsp(PIN_RX, PIN_TX);
  msgServiceEsp->init();
  sender = new Sender(msgServiceEsp);

  sensingTask = new SensingTask(photoresistor, soilMoistureSensor, tempHum, sender);
  sensingTask->init(1000UL * 60UL * 15UL);
  listenerTask = new ListenerTask(waterPomp, ventilation, tempLamp, lamp, msgServiceEsp);
  listenerTask->init(1000UL * 3UL);

  scheduler.init(SCHEDULE_TIME);

  sensingTask->setActive(true);
  listenerTask->setActive(true);

  scheduler.addTask(sensingTask);
  scheduler.addTask(listenerTask);
}

/**
 * The actively control the Arduino board. 
 * It start the scheduler.
 */
void loop() {
  scheduler.schedule();
}
