#include "Ventilation.h"
#include "Fan.h"

#define PIN_ENABLE 5
#define PIN_DIRA 3
#define PIN_DIRB 4

Ventilation *ventilation;

void setup() {
  Serial.begin(9600);
  ventilation = new Fan(PIN_ENABLE, PIN_DIRA, PIN_DIRB);

}

void loop() {
  if (ventilation->isActive()) {
    ventilation->deactivate();
  } else {
    ventilation->activate();
  }
  delay(2000);
}
