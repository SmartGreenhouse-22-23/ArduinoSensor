#include "Light.h"
#include "Led.h"

#define PIN_ALARM 10
#define PIN_LAMP 9

Light *alarm;
Light *lamp;

int fade = 5;

void setup() {
  Serial.begin(9600);
  alarm = new Led(PIN_ALARM);
  lamp = new Led(PIN_LAMP);

  pinMode(PIN_LAMP, OUTPUT);
  pinMode(PIN_ALARM, OUTPUT);
  
  
  lamp->switchOn();
  lamp->setBrightness(0);
 
}

void loop() {
  lamp->setBrightness(lamp->getBrightness() + fade);
  if (lamp->getBrightness() <= 0 || lamp->getBrightness() >= 255){
    fade = -fade;
    alarm->switchOn();
    delay(1000); 
    alarm->switchOff();
  }
  delay(200); // Wait for 50 millisecond(s)
}
