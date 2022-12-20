#include "TemperatureAndHumidity.h"
#include "Environment.h"

#define PIN_DHT 3

Environment *tempHum;

void setup() {
  Serial.begin(9600);
  tempHum = new TemperatureAndHumidity(PIN_DHT);

}

void loop() {
  Serial.print("Humidity:");
  Serial.println(tempHum->getHumidity());
  Serial.print("Temperature:");
  Serial.println(tempHum->getTemperature());
  delay(500);
}
