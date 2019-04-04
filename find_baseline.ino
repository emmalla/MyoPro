long[] restVals = [0,0,0,0,0,0,0,0,0,0];
long[] flexVals  [0,0,0,0,0,0,0,0,0,0];
boolean[] go = true;
long sensorValue;
long restAvg = 0;
long restMax;
long flexAvg = 0;
long flexMin;


void setup() {
    Serial.begin(9600);
    pinMode(A0, INPUT);

}

void loop() {
  while(go = true){
    Serial.println("Relax");
    delay(1000);
    for(int i = 0; i < 10; i++){
      sensorValue = analogRead(A0); 
      restVals[i] = sensorValue;
      Serial.print("Rest Value ");
      Serial.print(i);
      Serial.print(" :");      
      Serial.println(sensorValue);      
      delay(100o);
     }
    Serial.println();
    Serial.println("Flex");
    delay(1000);
    for(int j = 0; j < 10; j++){
      sensorValue = analogRead(A0); 
      flexVals[j] = sensorValue;
      Serial.print("Flex Value ");
      Serial.print(j);
      Serial.print(" :");      
      Serial.println(sensorValue);      
      delay(1000);
    }
    flexMin = min(flexVals);
    for(i = 0; i < 10; i++){
      flexAvg = flaxAvg + flexVals[i];
    }
    flexAvg = flexAvg/10;
    restMax = max(restVals);
    for(i = 0; i < 10; i++){
      restMax = restMax + restVals[i];
    }
    restAvg = restAvg/10;
    go = false;
  }
  Serial.println();
  Serial.printnl();
  Serial.print("Resting Avg: ");
  Serial.println(restAvg);
  Serial.print("Resting Max: ");
  Serial.println(restMax);
  Serial.println();
  Serial.print("Flexing Avg: ");
  Serial.println(flexAvg);
  Serial.print("Flexing Min: ");
  Serial.println(flexMin);
}
    
    
