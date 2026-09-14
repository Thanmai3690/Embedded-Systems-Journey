
int pins[3] = {8, 9, 10};

void setup(){
    Serial.println("...Sensor Values Reading Started...");
    Serial.begin(9600);
    for(int i=0; i<3; i++){
      pinMode(pins[i], OUTPUT);
    }
    pinMode(11, OUTPUT);
}

int readSensor(){
  int sensorValue = analogRead(A0);
  return sensorValue;
}

int classifySensor(int sensorValue){
  if(sensorValue <= 300){
    return 1;
  } else if(sensorValue > 300 && sensorValue <= 700){
    return 2;
  } else {
    return 3;
  }
}

void greenLED(){
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}

void yellowLED(){
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}

void redLED(){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
}

void controlLEDs(int status){
  if(status == 1){
    greenLED();
  } else if(status == 2){
    yellowLED();
  } else {
    redLED();
  }
}

void controlBuzzer(int status){
  if(status == 3){
    tone(11, 1000);
  } else {
    noTone(11);
  }
}

void displayStatus(int sensorValue, int status){
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  if(status == 1){
        Serial.println("Status: SAFE");
    } else if(status == 2){
        Serial.println("Status: WARNING");
    } else {
        Serial.println("Status: DANGER");
    }
}

void loop(){
    int sensorValue = readSensor();
    int status = classifySensor(sensorValue);
    controlLEDs(status);
    controlBuzzer(status);
    displayStatus(sensorValue, status);

    delay(2000);

    
}