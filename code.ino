#include <Servo.h>

#define trigEntry 9
#define echoEntry 10
#define trigExit 11
#define echoExit 12
#define buzzer 8
#define ledRed 6
#define ledGreen 7
#define servoPin 5

long durationEntry, durationExit;
int distanceEntry, distanceExit;
int carCount = 0;
int maxCars = 3;
bool entryDetected = false;
bool exitDetected = false;

Servo barrierServo;

void setup() {
  pinMode(trigEntry, OUTPUT);
  pinMode(echoEntry, INPUT);
  pinMode(trigExit, OUTPUT);
  pinMode(echoExit, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  barrierServo.attach(servoPin);
  barrierServo.write(0); // Barrier closed initially

  Serial.begin(9600);
}

int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2; // cm
}

void loop() {
  distanceEntry = getDistance(trigEntry, echoEntry);
  distanceExit = getDistance(trigExit, echoExit);

  // Entry detection
  if (distanceEntry < 20 && !entryDetected) {
    entryDetected = true;
    if (carCount < maxCars) {
      carCount++;
      Serial.print("Car Entered. Total cars: ");
      Serial.println(carCount);
    }
  } else if (distanceEntry >= 20) {
    entryDetected = false;
  }

  // Exit detection
  if (distanceExit < 20 && !exitDetected) {
    exitDetected = true;
    if (carCount > 0) {
      carCount--;
      Serial.print("Car Exited. Total cars: ");
      Serial.println(carCount);
    }
  } else if (distanceExit >= 20) {
    exitDetected = false;
  }

  // Barrier logic
  if (carCount >= maxCars) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);
    barrierServo.write(0); // Barrier closed
    Serial.println("Parking FULL - Barrier Closed");
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
    barrierServo.write(90); // Barrier open
    Serial.println("Parking Available - Barrier Open");
  }

  delay(500);
}
