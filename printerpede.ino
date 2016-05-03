#include "Adafruit_Thermal.h"

Adafruit_Thermal printer1(&Serial1);
Adafruit_Thermal printer2(&Serial2);

void setup() {

  String str1 = "[1:1] In the beginning when God created the heavens and the earth, [1:2] the earth was a formless void and darkness covered the face of the deep, while a wind from God swept over the face of the waters. [1:3] Then God said, 'Let there be light'; and there was light. [1:4] And God saw that the light was good; and God separated the light from the darkness. [1:5] God called the light Day, and the darkness he called Night. And there was evening and there was morning, the first day. [1:6] And God said, 'Let there be a dome in the midst of the waters, and let it separate the waters from the waters.' [1:7] So God made the dome and separated the waters that were under the dome from the waters that were above the dome. And it was so. [1:8] God called the dome Sky. And there was evening and there was morning, the second day.";
  String str2 = "In the same way, when the thought 'I' arises in dependence upon mind and body, nothing within mind and body—neither the collection which is a continuum of earlier and later moments, nor the collection of the parts at one time, nor the separate parts, nor the continuum of any of the separate parts—is in even the slightest way the 'I.' Also there is not even the slightest something that is a different entity from mind and body that is apprehendable as the 'I.' Consequently, the 'I' is merely set up by conceptuality in dependence upon mind and body; it is not established by way of its own entity.";
  

  Serial1.begin(19200);
  Serial2.begin(19200);

  printer1.begin();
  printer2.begin();
  
  printer1.upsideDownOn();
  printer2.upsideDownOn();

  int numLines = 20;
  int lineLength = 30;
  for (int i = 0; i < numLines; i++) {
    int offSet = i * lineLength;
    printline(str1, str2, lineLength, offSet);
  }

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
