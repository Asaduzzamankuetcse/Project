/* FreqMeasure - Example with serial output
 * http://www.pjrc.com/teensy/td_libs_FreqMeasure.html
 *
 * This example code is in the public domain.
 */
#include <FreqMeasure.h>

void setup() {
  Serial.begin(57600);
  Serial.println("Setup func");
  FreqMeasure.begin();
}

double sum=0;
int count=0;

void loop() {
  Serial.println("outside");
  if (FreqMeasure.available() > 0) {
    Serial.println("Inside");
    Serial.println("Freq: " );
    Serial.println(F_CPU / FreqMeasure.read());
    
    //Serial.println(FreqMeasure.read());
    delay(1000);
    
    // average several reading together
    sum = sum + FreqMeasure.read();
    count = count + 1;
    if (count > 30) {
      double frequency = F_CPU / (sum / count);
      Serial.println(frequency);
      sum = 0;
      count = 0;
    }
  }
}
