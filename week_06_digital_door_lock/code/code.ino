#include <Keypad.h>
#include <string.h>
#include <Servo.h>

const byte ROWS = 4;
const byte COLS = 4;
const int greenLED = 10;
const int redLED = 11;
const int buzzer = 12;
Servo doorServo;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

const char correctPassword[] = "1234";

char enteredPassword[5];
int index = 0;

void setup() {
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  doorServo.attach(13);
  doorServo.write(0);
  Serial.println("================================");
  Serial.println("       DIGITAL DOOR LOCK");
  Serial.println("================================");
  Serial.println("System Status : READY");
  Serial.println("Enter 4-character password:");
}

char readKey(){
  char key = keypad.getKey();
  return key;
}

void storeKey(char key){
  enteredPassword[index] = key;
  index++;

  if(index == 4){
    enteredPassword[index] = '\0';
    displayPassword();

    if(checkPassword()){
      Serial.println("\nCorrect Password!");
      Serial.println("\nACCESS GRANTED");
      Serial.println("Green LED     : ON");
      Serial.println("Door Status   : UNLOCKED");
      Serial.println("Servo Angle   : 90°");
      Serial.println("Buzzer        : OFF");

      digitalWrite(greenLED, HIGH);
      moveServo(0,90);

      delay(3000);

      moveServo(90,0);
      digitalWrite(greenLED, LOW);

      Serial.println("Door Status   : LOCKED");
      Serial.println("Servo Angle   : 0°");
      Serial.println("\nSystem Status : READY");
    } else {
      Serial.println("\nWrong Password!");
      Serial.println("\nACCESS DENIED");
      Serial.println("Red LED       : ON");
      Serial.println("Buzzer        : ON");
      Serial.println("Door Status   : LOCKED");

      digitalWrite(redLED, HIGH);
      tone(buzzer,3000);

      delay(3000);

      digitalWrite(redLED, LOW);
      noTone(buzzer);

      Serial.println("Red LED       : OFF");
      Serial.println("Buzzer        : OFF");
      Serial.println("System Status : READY");
    }
    resetPassword();
  }
}

void moveServo(int startAngle, int endAngle){
  if(startAngle < endAngle){
    for(int angle = startAngle; angle <= endAngle; angle++){
      doorServo.write(angle);
      delay(20);
    }
  } else {
    for(int angle = startAngle; angle >= endAngle; angle--){
      doorServo.write(angle);
      delay(20);
    }
  }
}

void displayPassword(){
  Serial.print("Entered Password: ****");
}

bool checkPassword(){
  if(strcmp(enteredPassword, correctPassword) == 0){
    return true;
  } else {
    return false;
  }
}

void resetPassword(){
  index = 0;
  enteredPassword[0] = '\0';
}

void loop() {
  char key = readKey();

  if(key != NO_KEY){
    storeKey(key);
  }
}