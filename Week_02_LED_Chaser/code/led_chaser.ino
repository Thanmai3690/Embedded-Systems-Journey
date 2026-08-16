void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i <= 7; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // forward phase (slow to fast)
  int speed = 500;
  for(int i = 2; i<=7; i++){
    digitalWrite(i, HIGH);
    delay(speed);
    digitalWrite(i, LOW);
    speed -= 80;
  }
  // Reverse phase (fast to slow)
  int speed1 = 100;
  for(int i = 7; i>=2; i--){
    digitalWrite(i, HIGH);
    delay(speed1);
    digitalWrite(i, LOW);
    speed1 += 80;
  }
  // pingpong phase (uniform speed)
  int pingspeed = 150;
  for(int i = 2; i<=7; i++){
    digitalWrite(i, HIGH);
    delay(pingspeed);
    digitalWrite(i, LOW);
  }
  for(int i = 6; i>=2; i--){
    digitalWrite(i, HIGH);
    delay(pingspeed);
    digitalWrite(i, LOW);
  }
}
