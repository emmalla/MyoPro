
#include <Servo.h>

int motor = 7; 
int sensorVal;
byte state = 0; // 0 means hand is open, 1 means hand is closed
Servo hand;
byte lastState = 0;
int pos = 0;


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  hand.attach(motor);
  hand.write(0);
}

void loop() {
  sensorVal = analogRead(A0); 
  Serial.println(sensorVal);
  while(sensorVal > 500){
    pos = 180-(180*state);
    hand.write(pos);
    delay(2000);   
    state = 1-state;  
    sensorVal = 0;
    delay(100);
 }

}
