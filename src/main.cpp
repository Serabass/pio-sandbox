/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include "Arduino.h"

// #define DEBUG

#ifdef DEBUG
#include "avr8-stub.h"
#include "app_api.h" // only needed with flash breakpoints
#endif

class Test
{
public:
  int add(int a, int b);
};

int Test::add(int a, int b)
{
  return a + b;
}

Test *test = new Test();

void setup()
{
#ifdef DEBUG
  debug_init();
#endif

  while (!Serial)
  {
  }

  Serial.begin(9600);

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

  Serial.println(test->add(1, 3));
}
