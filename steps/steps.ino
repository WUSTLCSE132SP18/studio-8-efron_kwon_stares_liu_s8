#include <SFE_MMA8452Q.h>
#include <Wire.h>

int counter = 0;
unsigned long endLoopTime = 0;
int deltaTime = 200;
boolean step = false;
MMA8452Q accel;

void setup() {
  Serial.begin(9600);
  accel.init();
}

void loop() {
  if (accel.available()){
    accel.read();
    csv();
  }
}


void debounce(){
  if(millis() >= endLoopTime){
      if (!step && accel.cz >= 1.5){
        step = true;
        counter++;
      }
   else if (step && accel.cz <= 1.5){
        Serial.print(counter);
        Serial.println(" steps have been taken.");
        step = false;
      }
   endLoopTime += deltaTime;
   }
}

void csv(){
  Serial.print(accel.cx, 3);
  Serial.print(",");
  Serial.print(accel.cy, 3);
  Serial.print(",");
  Serial.print(accel.cz, 3);
  Serial.println("");
}

