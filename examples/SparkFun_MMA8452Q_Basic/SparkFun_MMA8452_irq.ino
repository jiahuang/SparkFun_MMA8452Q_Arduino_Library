#include <Wire.h> // Must include Wire library for I2C
#include <SparkFun_MMA8452Q.h> // Includes the SFE_MMA8452Q library
int led = 13;
bool shaked = false;
bool shouldClear = false;
MMA8452Q accel;
int irq_count = 0;

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, shake, FALLING);
  accel.init();
  accel.clearIRQ();
  Serial.println("MMA8452Q Test Code!");
}

void loop() {
  if (shouldClear){
    accel.clearIRQ();
    shouldClear = false;
  }
}


void shake() {
    if (!shaked) {
      digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    } else {
       digitalWrite(led, LOW); 
    }
    
    shaked = !shaked;
    shouldClear = true;
 
}