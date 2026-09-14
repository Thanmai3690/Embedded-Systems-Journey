#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int temperatureHistory[5];
int humidityHistory[5];
String statusHistory[5];
int historyCount = 0;

void storeHistory(int temperature, int humidity, String status){
    if(historyCount < 5){
        temperatureHistory[historyCount] = temperature;
        humidityHistory[historyCount] = humidity;
        statusHistory[historyCount] = status;
        historyCount++;
    }
}

void generateReport(){
    if(historyCount == 0){
        Serial.println("No history available");
        return;
    }

    int highestTemp = temperatureHistory[0];
    int lowestTemp = temperatureHistory[0];
    int highestHum = humidityHistory[0];
    int lowestHum = humidityHistory[0];

    int tempSum = 0;
    int humSum = 0;

    int okCount = 0;
    int warningCount = 0;
    int dangerCount = 0;

    for(int i = 0; i < historyCount; i++){
        if(temperatureHistory[i] > highestTemp){
            highestTemp = temperatureHistory[i];
        }

        if(temperatureHistory[i] < lowestTemp){
            lowestTemp = temperatureHistory[i];
        }

        if(humidityHistory[i] > highestHum){
            highestHum = humidityHistory[i];
        }

        if(humidityHistory[i] < lowestHum){
            lowestHum = humidityHistory[i];
        }

        tempSum = tempSum + temperatureHistory[i];
        humSum = humSum + humidityHistory[i];

        if(statusHistory[i] == "OK"){
            okCount++;
        }
        else if(statusHistory[i] == "WARNING"){
            warningCount++;
        }
        else if(statusHistory[i] == "DANGER"){
            dangerCount++;
        }
    }

    float averageTemp = (float)tempSum / historyCount;
    float averageHum = (float)humSum / historyCount;

    Serial.println("===== SENSOR REPORT =====");

    Serial.print("Total Readings: ");
    Serial.println(historyCount);

    Serial.println();

    Serial.println("Temperature");
    Serial.print("Highest: ");
    Serial.println(highestTemp);
    Serial.print("Lowest: ");
    Serial.println(lowestTemp);
    Serial.print("Average: ");
    Serial.println(averageTemp);

    Serial.println();

    Serial.println("Humidity");
    Serial.print("Highest: ");
    Serial.println(highestHum);
    Serial.print("Lowest: ");
    Serial.println(lowestHum);
    Serial.print("Average: ");
    Serial.println(averageHum);

    Serial.println();

    Serial.println("Status Count");
    Serial.print("OK: ");
    Serial.println(okCount);
    Serial.print("WARNING: ");
    Serial.println(warningCount);
    Serial.print("DANGER: ");
    Serial.println(dangerCount);

    Serial.println("=========================");
}



void setup() {
    Serial.begin(9600);
    dht.begin();
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
}

float temperature;
float humidity;
void readSensor(){
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
}

String generateStatus(){
  if(temperature <= 30 && humidity <= 70){
    return "OK";
  } else if((temperature > 30 && temperature <= 40) || (humidity > 70 && humidity <= 85)){
    return "WARNING";
  } else {
    return "DANGER";
  }
}

String createMessage(){
  String message = "TEMP:" + String(temperature) + ",HUM:" + String(humidity) + ",STATUS:" + generateStatus();
  return message;
}

int parseTemperature(String message){
  int number1 = 0;
  int position = message.indexOf("TEMP:");
  position = position + 5;
  while(message[position] >= '0' && message[position] <= '9'){
      number1 = number1 * 10 + (message[position] - '0');
      position++;
  }
  return number1;
}

int parseHumidity(String message){
  int number2 = 0;
  int position = message.indexOf("HUM:");
  position = position + 4;
  while(message[position] >= '0' && message[position] <= '9'){
      number2 = number2 * 10 + (message[position] - '0');
      position++;
  }
  return number2;
}

String parseStatus(String message){
  String status = "";
  int position = message.indexOf("STATUS:");
  position = position + 7;
  while(message[position] != '\0'){
    status = status + message[position];
    position++;
  }
  return status;
}

void controlOutputs(String status){
  if(status == "OK"){
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    noTone(11);
    
  } else if(status == "WARNING"){
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    noTone(11);
  } else {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    tone(11, 3000);
  }
}

void showStatus(){
    Serial.println("===== CURRENT STATUS =====");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
    Serial.print("Status: ");
    Serial.println(generateStatus());
    Serial.println("==========================");
}

void clearHistory(){
    historyCount = 0;

    Serial.println("History cleared successfully.");
}

void loop() {
  readSensor();
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  delay(2000);

  String message = createMessage();
  Serial.println(message);

  int parsedtemp = parseTemperature(message);
  Serial.println(parsedtemp);

  int parsedhum = parseHumidity(message);
  Serial.println(parsedhum);

  String parsedstatus = parseStatus(message);
  Serial.println(parsedstatus);

  controlOutputs(parsedstatus);
  delay(2000);

  storeHistory(parsedtemp, parsedhum, parsedstatus);

  if(Serial.available()){
    String command = Serial.readStringUntil('\n');
    command.trim();

    Serial.print("Received: ");
    Serial.println(command);

    if(command == "REPORT"){
      Serial.println("REPORT command detected!");
      generateReport();
    }  else if(command == "STATUS"){
        showStatus();
      } else if(command == "CLEAR"){
        clearHistory();
      }
  }
  

  
}