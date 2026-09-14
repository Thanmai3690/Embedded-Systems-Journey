int pot = A0;
int ledPins[] = {8, 9, 10};

void setup(){
  for(int i = 0; i < 3; i++){
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

int readSensor(){
  int value = analogRead(pot);
  return value;
}

int trafficLevel(int value){
  if(value >= 0 && value <= 300){
    return 1;
  } else if(value > 300 && value <= 700){
    return 2;
  } else {
    return 3;
  }
}

void controlBuzzer(int status){
  if(status == 3){
    tone(11, 1000);
  } else {
    noTone(11);
  }
}

void redLed(){
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}

void yellowLed(){
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}

void greenLed(){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
}

void controlLeds(int status){
  int greenTime;

  if(status == 1){
    greenTime = 3000;
  } else if(status == 2){
    greenTime = 5000;
  } else {
    greenTime = 8000;
  }

  redLed();
  noTone(11);
  Serial.println("Signal: RED");
  Serial.println("Buzzer: OFF");
  delay(3000);

  greenLed();
  Serial.println("Signal: GREEN");

  if(status == 3){
    controlBuzzer(status);
    Serial.println("Buzzer: ON");
  } else {
    controlBuzzer(status);
    Serial.println("Buzzer: OFF");
  }

  Serial.print("Green Duration: ");
  Serial.print(greenTime / 1000);
  Serial.println(" seconds");

  delay(greenTime);

  noTone(11);

  yellowLed();
  Serial.println("Signal: YELLOW");
  Serial.println("Buzzer: OFF");
  delay(1000);
}

void loop(){
  int value = readSensor();
  int status = trafficLevel(value);

  Serial.println();

  Serial.print("Sensor Value: ");
  Serial.println(value);

  if(status == 1){
    Serial.println("Traffic Level: LOW");
  } else if(status == 2){
    Serial.println("Traffic Level: MEDIUM");
  } else {
    Serial.println("Traffic Level: HIGH");
  }

  controlLeds(status);

  Serial.println("--------------------");
}