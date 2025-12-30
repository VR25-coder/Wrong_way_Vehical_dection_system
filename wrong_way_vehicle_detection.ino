#include <Servo.h>


#define TRIG_PIN 9
#define ECHO_PIN 10
#define SERVO_PIN 8


Servo myServo;

void setup() {
  Serial.begin(9600);

  myServo.attach(SERVO_PIN);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  long duration;
  long distance;


  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);


  duration = pulseIn(ECHO_PIN, HIGH);


  distance = (duration / 2) / 29.1;


  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");


  if (distance > 0 && distance < 10) {
    activateServo();
  }

  delay(100);
}

void activateServo() {
  myServo.write(150);   // Activate barrier
  delay(5000);          // Hold position
  myServo.write(0);     // Reset barrier
  delay(1000);
}
