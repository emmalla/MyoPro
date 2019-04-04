
// play with myoware - very first initial test code 
// sends one static reading per second


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  int sensorValue = analogRead(A0); // test the emg input 
  Serial.println(sensoreValue);
  delay(1000);

}
