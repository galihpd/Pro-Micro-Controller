#include <Joystick.h>

// Define pins
const int potPin = A0; // Pin for potentiometer

int potValue = 0;

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,
JOYSTICK_TYPE_JOYSTICK, 0, 0); // No brake or steering

void setup() {

  Serial.begin(9600);
  Joystick.begin();

}

void loop() {

  potValue = analogRead(potPin);
  int invertedValue = map(potValue, 0, 1023, 1023, 0);
  Joystick.setXAxis(invertedValue);

  delay(10);
}
