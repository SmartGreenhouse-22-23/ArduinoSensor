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

#define PIN_PHOTORES A1
#define PIN_SOILMOISTURE A0
#define PIN_WATERPOMP 2
#define PIN_DHT 3
#define PIN_ENABLE 5
#define PIN_DIRA 6
#define PIN_DIRB 4
#define PIN_ALARM 10
#define PIN_LAMP 9

#define SCHEDULE_TIME 20UL

Ventilation *ventilation;
Brightness *photoresistor;
SoilMoistureSensor *soilMoistureSensor;
WaterPomp *waterPomp;
Environment *tempHum;
Light *alarm;
Light *lamp;

int fade = 5;

SensingTask *sensingTask;

Scheduler scheduler;


void setup() {
  Serial.begin(9600);
  ventilation = new Fan(PIN_ENABLE, PIN_DIRA, PIN_DIRB);
  photoresistor = new Photoresistor(PIN_PHOTORES);
  soilMoistureSensor = new SoilMoistureSensor(PIN_SOILMOISTURE);
  waterPomp = new WaterPomp(PIN_WATERPOMP);
  tempHum = new TemperatureAndHumidity(PIN_DHT);
  alarm = new Led(PIN_ALARM);
  lamp = new Led(PIN_LAMP);
  pinMode(PIN_LAMP, OUTPUT);
  pinMode(PIN_ALARM, OUTPUT);
  lamp->switchOn();
  lamp->setBrightness(0);

  sensingTask = new SensingTask(photoresistor, soilMoistureSensor, tempHum);
  sensingTask->init(1000UL * 60UL * 15UL); //15min

  scheduler.init(SCHEDULE_TIME);

  scheduler.addTask(sensingTask);
  sensingTask->setActive(true);
  Serial.println("Task added");
}

void loop() {
  scheduler.schedule();
 /*
  Serial.println(soilMoistureSensor->getValue());
  waterPomp->activate();
  delay(500);
  waterPomp->deactivate();

  Serial.println(photoresistor->getBrightness());

  if (ventilation->isActive()) {
    ventilation->deactivate();
  } else {
    ventilation->activate();
  }
  delay(2000);

  Serial.print("Humidity:");
  Serial.println(tempHum->getHumidity());
  Serial.print("Temperature:");
  Serial.println(tempHum->getTemperature());
  delay(500);

  lamp->setBrightness(lamp->getBrightness() + fade);
  if (lamp->getBrightness() <= 0 || lamp->getBrightness() >= 255){
    fade = -fade;
    alarm->switchOn();
    delay(1000); 
    alarm->switchOff();
  }
  delay(200);
  */
}
