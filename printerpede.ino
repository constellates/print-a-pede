#include "Adafruit_Thermal.h"

Adafruit_Thermal printer1(&Serial1);
Adafruit_Thermal printer2(&Serial2);

// -----------------------------------------------------------------------

void setup() {
  Serial2.begin(19200);
  Serial1.begin(19200);
  printer2.begin();
  printer1.begin();

  // Test inverse on & off
  printer2.upsideDownOn();
  printer1.upsideDownOn();
  printer2.println(F("Who knows, but that the universe is not one vast sea of compassion actually, the veritable holy honey, beneath all this show of personality and cruelty?"));
  printer1.println(F("Who knows, but that the universe is not one vast sea of compassion actually, the veritable holy honey, beneath all this show of personality and cruelty?"));
  printer2.upsideDownOff();
  printer1.upsideDownOff();
  

  // Test character double-height on & off
//  printer.doubleHeightOn();
//  printer.println(F("Double Height ON"));
//  printer.doubleHeightOff();

  printer2.feed(2);
  printer1.feed(2);

//  printer.sleep();
//  printer.wake();
  printer2.setDefault(); // Restore printer to defaults
  printer1.setDefault(); // Restore printer to defaults
}

void loop() {
}
