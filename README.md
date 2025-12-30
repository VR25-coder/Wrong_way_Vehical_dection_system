# Wrong Way Vehicle Detection System using Arduino

A smart road-safety system that detects wrong-way vehicles using an ultrasonic sensor and automatically activates a servo-based mechanical barrier to prevent accidents.

---

## 🚦 Project Overview

Wrong-way driving is one of the major causes of fatal road accidents. This project proposes a **cost-effective and real-time Wrong Way Vehicle Detection System** using Arduino, an ultrasonic sensor, and a servo motor.

When a vehicle is detected moving in the wrong direction, the system:
- Detects the vehicle using an ultrasonic sensor
- Processes distance data via Arduino
- Activates a servo motor to trigger a mechanical barrier (nails/spike model)
- Forces the vehicle to return to the correct lane

---

## 🛠️ Components Used

- Arduino Mega / Arduino Uno
- Ultrasonic Sensor (HC-SR04)
- Servo Motor (SG90 / MG996R)
- Jumper Wires
- Power Supply (5V / 12V)
- Mechanical barrier model (spike/nail prototype)

---

## ⚙️ Working Principle

1. The ultrasonic sensor continuously measures distance.
2. If an object (vehicle) is detected within a predefined range (e.g., <10 cm):
   - Arduino processes the signal
   - Servo motor rotates to activate the barrier
3. After a delay, the servo resets to its original position.

---

## 📄 Code Explanation

- **TRIG_PIN & ECHO_PIN**: Used to trigger and receive ultrasonic signals
- **pulseIn()**: Measures echo pulse duration
- **Distance calculation**: Converts time into distance
- **Servo control**: Activates and deactivates mechanical barrier

---

## 🔧 Arduino Code

```cpp
#include <Servo.h>

#define TRIG_PIN 9
#define ECHO_PIN 10

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(8);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  long duration, distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance < 10 && distance > 0) {
    activateServo();
  }

  delay(100);
}

void activateServo() {
  myServo.write(150);
  delay(5000);
  myServo.write(0);
  delay(1000);
}
