#include "Fan.h"

Fan::Fan(int enablePin, int diraPin, int dirbPin)
{
    this->enablePin = enablePin;
    this->diraPin = diraPin;
    this->dirbPin = dirbPin;
    this->active = false;

    pinMode(this->enablePin, OUTPUT);
    pinMode(this->diraPin, OUTPUT);
    pinMode(this->dirbPin, OUTPUT);
}

void Fan::activate() {
    analogWrite(this->enablePin, 255);
    digitalWrite(this->diraPin, LOW);
    digitalWrite(this->dirbPin, HIGH);
    this->active = true;
}

void Fan::deactivate() {
    analogWrite(this->enablePin, 0);
    this->active = false;
}

bool Fan::isActive() {
    return this->active;
}
