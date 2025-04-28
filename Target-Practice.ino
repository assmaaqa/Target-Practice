#include <Servo.h>
int value1 = 0;
int value2 = 0;
int value3 = 0;
int light1 = A0;
int light2 = A1;
int light3 = A2;
int buzzer = 4;
int dis = 0;
const int trigPin = 5;
const int echoPin = 3;
Servo servo1, servo2, servo3;

bool b1 = 0, b2 = 0, b3 = 0;

void returnTargets() {
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
}

void setup() {
  pinMode(light1, INPUT);
  pinMode(light2, INPUT);
  pinMode(light3, INPUT);
  servo1.attach(9);
  servo1.write(0);
  servo2.attach(10);
  servo2.write(0);
  servo3.attach(11);
  servo3.write(0);
}

void loop() {

  float duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  if (distance <= 50) {
    tone(buzzer, 1000);
  } else {
    noTone(buzzer);


    value1 = analogRead(light1);
    value2 = analogRead(light2);
    value3 = analogRead(light3);


    if (value1 > 400) {
      servo1.write(90);
      b1 = true;
    }

    if (value2 > 400) {
      servo2.write(90);
      b2 = true;
    }

    if (value3 > 400) {
      servo3.write(90);
      b3 = true;
    }

    if (b1 && b2 && b3) {
      delay(1000);
      returnTargets();
      tone(buzzer, 1000);
      delay(1000);
      noTone(buzzer);
      b1 = false;
      b2 = false;
      b3 = false;
    }
  }

}
