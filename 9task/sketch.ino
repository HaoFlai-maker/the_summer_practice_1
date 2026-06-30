const int redLedPin = 9;
const int greenLedPin = 5;
const int sensorPin = A0;

bool isDoorOpen = false;

//функция настройки
void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  Serial.begin(9600);

  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, LOW);
}

//работает, пока подается питание
void loop() {
  int sensorValue = analogRead(sensorPin);

  //если значение больше 512 - открывает дверь
  if (sensorValue > 512) {
    if (!isDoorOpen) {
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);
      Serial.println("Двери открываются!");

      isDoorOpen = true;

      delay(3000);
    } 
  } else {
    if (isDoorOpen) {
      digitalWrite(greenLedPin, LOW);
      digitalWrite(redLedPin, HIGH);
      Serial.println("Двери закрываются!");

      isDoorOpen = false;
    } 
  }
  
  delay(100); 
}