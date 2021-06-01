#include "Arduino.h"
#include "test.h"

// #define DEBUG

#ifdef DEBUG
#include "avr8-stub.h"
#include "app_api.h" // only needed with flash breakpoints
#endif

Test *test;
int a;

void setup()
{
#ifdef DEBUG
  debug_init();
#endif

  test = new Test();
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  // wait for a second
  delay(1000);

  a = test->add(a, 1);
}
