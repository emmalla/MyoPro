

long[] restVals = [0,0,0,0,0,0,0,0,0,0]; // 10 trials of rest data 
long[] flexVals  [0,0,0,0,0,0,0,0,0,0]; // 10 trials of flex data
boolean[] go = true; // outer control condition
long sensorValue; // reads from sensor
long restAvg = 0; // holds avg of rest vals
long restMax; // highest rest val to find safe threshold
long flexAvg = 0; // holds avg of flex vals
long flexMin; // lowest flex val to find safe threshold


void setup() {
    Serial.begin(9600);
    pinMode(A0, INPUT);

}

void loop() { 
  
 // gathers 10 data points from each rest and flexing
  
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
      delay(1000);
     }
     delay(5000);
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
    go = false; // end after one iteration, wait for reset
  }

  // print out the averages, min, and max
  // add code that can determine and output threshold after preliminary experimentation
  
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
    
    
