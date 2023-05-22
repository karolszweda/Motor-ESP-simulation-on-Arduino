#include "sensor.h"
#include "motor.h"
#include "esp.h"
#include "test.h"

#define MTR_SPEED 50
#define MTR_SPEED_PIN 6
#define MTR_DIR 0
#define MTR_DIR_PIN 9
#define BTN_PIN A0

Sensor button( BTN_PIN );
Motor motorDC(MTR_SPEED, MTR_SPEED_PIN, MTR_DIR, MTR_DIR_PIN);
ESP wheel( &button, &motorDC );

void setup() {
  Serial.begin( 9600 );
  //implementacja ESP w Arduino a analiza danych za pomocą komputera GUI w qt
}

void loop() {

  motorDC.work();
  button.work();
  wheel.work();

}
