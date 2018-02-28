#include <wiringPi.h>
#include <wiringShift.h>

const int latchPin = 0;
const int dataPin = 2;
const int clockPin = 3;


int main(void) {
  if(wiringPiSetup() == -1){
    printf("setup wiringPi failed !\n");
    return -1; 
  }
  
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  while(1) {
    digitalWrite(latchPin, HIGH);
    shiftOut (dataPin, clockPin, MSBFIRST, 85);
    digitalWrite(latchPin, LOW);
  }

  return 0;
}
