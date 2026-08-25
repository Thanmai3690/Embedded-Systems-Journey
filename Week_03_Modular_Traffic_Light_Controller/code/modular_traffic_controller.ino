void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

}

void redLight(){
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

}

void yellowLight(){
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}

void greenLight(){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
}

void blinkGreen(){
  for(int i=1; i<=3; i++){
    digitalWrite(10, LOW);
    delay(500);
    digitalWrite(10, HIGH);
    delay(500);
    digitalWrite(10, LOW);
    delay(500);
  }
}

void loop() {
  redLight();
  delay(4000);

  yellowLight();
  delay(2000);

  greenLight();
  delay(4000);

  blinkGreen();

}
