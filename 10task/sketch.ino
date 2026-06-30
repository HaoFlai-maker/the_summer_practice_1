#include <Servo.h>

#define SERVO_PIN 3

Servo myServo;
int currentAngle = 0;

bool isValidNumber(String& str) {
  if (str.length() == 0)  {
    return false;
  }
  for (byte i = 0; i < str.length(); i++) {
    if (!isDigit(str[i])) {
      return false;
    }
  }
  return true;
}

void move(int& fromAngle, int& toAngle) {
  if (fromAngle < toAngle) {
    for (int pos = fromAngle; pos <= toAngle; pos++) {
      myServo.write(pos);
      delay(20);
    }
  } else {
    for (int pos = fromAngle; pos >= toAngle; pos--) {
      myServo.write(pos);
      delay(20);
    }
  }
}

void setup() {
  Serial.begin(9600);

  myServo.attach(SERVO_PIN);
  myServo.write(currentAngle);

  Serial.println("Введите угол от 0 до 180 градусов включительно:");
}

void loop() {
  if (Serial.available() > 0) {

    String inputString = Serial.readStringUntil('\n');

    inputString.trim();

    if (isValidNumber(inputString)) {
      int targetAngle = inputString.toInt();
      if (targetAngle >= 0 && targetAngle <= 180) {
        if (targetAngle != currentAngle) {
          Serial.print("Перемещаю сервопривод в положение... ");
          Serial.print(targetAngle);
          Serial.println(" градусов");
          move(currentAngle, targetAngle);

          currentAngle = targetAngle; 
          Serial.println("Введите угол от 0 до 180 градусов включительно:");
        } else {
          Serial.println("Сервопривод уже находится в этом положении.");
        }
        
      } else {
        Serial.println("Ошибка! Диапазон угла должен быть строго от 0 до 180 включительно.");
      }
    } else {
      Serial.println("Ошибка! Введены некорректные данные. Повторите попытку.");
    }
  }
}