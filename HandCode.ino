#include <Servo.h>

int motor = 7;
int motor2 = 4; 
int sensorVal;
byte state = 0;
Servo thumb;
Servo fingers;
byte lastState = 0;
int pos = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  thumb.attach(motor);
  thumb.write(0);
  fingers.attach(motor2);
  fingers.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:

  
  sensorVal = analogRead(A0);
  Serial.println(sensorVal);
  while(sensorVal > 250 && sensorVal < 600) {
    pos = 180 - (180*state);
    thumb.write(pos);
    fingers.write(pos);
    delay(2000);
    state = 1-state;
    sensorVal = 0;
    delay(100);
  }
}
