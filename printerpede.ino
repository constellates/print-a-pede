#include "Adafruit_Thermal.h"

Adafruit_Thermal printer1(&Serial1);
Adafruit_Thermal printer2(&Serial2);

// -----------------------------------------------------------------------

  Serial1.begin(19200);
  Serial2.begin(19200);

  printer1.begin();
  printer2.begin();
  
  printer1.upsideDownOn();
  printer2.upsideDownOn();

  // Test character double-height on & off
//  printer.doubleHeightOn();
//  printer.println(F("Double Height ON"));
//  printer.doubleHeightOff();

  printer1.upsideDownOff();
  printer2.upsideDownOff();
  
  printer1.feed(2);
  printer2.feed(2);

  printer1.sleep();
  printer2.sleep();

  delay(3000L);

  printer1.wake();
  printer2.wake();

  printer1.setDefault();
  printer2.setDefault();

}

void loop() {
  // put your main code here, to run repeatedly:

}

void printline(String str1, String str2, int lineLength, int start) {
  int lineEnd = start + lineLength;
  String line1 = str1.substring(start, lineEnd);
  String line2 = str2.substring(start, lineEnd);

  printer1.print(line2);
  printer2.print(line1);
}
